# pipex
## Because sometimes your data needs to be redirected.

### What is it actually about tho..?
The concept of piping and redirecting basically covers how we connect streams to programs and files. This can ahppen because of processes, these are programs that are being executed. To me a program is a set of instructions under one name. 

We can redirect in various ways; 
> The output of a command to a file [`ls -l > some_file`] 
> The contents of a file (or STDIN) to some command [`grep -c some_word < some_file`] == [`cat some_file | grep -c some_word`]
	In this specific example grep is one of the commands that doesn't usually accept a file as an option, however using the less than symbol ("<") allows us to redirect it's contents.

The last example shows how different configurations of the redirection operators available can achieve the same thing.

#### Diff? Is there one..?
> A *pipe* passes the standard output as the standard input to another command. Think of the shittrain thingy in southpark - that ass to moutoh type of thing..

	![alt text](https://live.staticflickr.com/6234/6290300905_469889172b_b.jpg)

> A *redirect* sends a stream of output to a file. Sometimes you'll see a stream be referred to as a channel, sucks but it happens.

### Syntax..? Or perhaps usage instead..?
To redirect to a file we use the "greater than symbol" (>). What you're basically doing is saying that instead having the output go to STDOUT -> go be the contents of this file. I don't know whether we can specify a format yet, but I wouldn't be surprised if we could somehow, however rn every element is followed by a "\n".

Another thing that's kinda nice to know, is that our destination doesn't have to exist yet for us to be able to store something in it. However if it does already exist, we need to append to it instead using (>>), because otherwise the current contents will be overwritten. 

In the case of wanting a visual confirmation as to what is being appended/redirected somewhere we can choose to redirect some_output to multiple streams. We achieve this by using "&".

	```>&2 || 2>&1 || ls -l 2>&1```

This last program lists all the elements in our directory then the output is redirected to stream 1. So stream 2 is literally redirected into stream 1. Technically `ls -1 3>&2 2>&1 1>&3` should also work, and in bash it does, it swaps STDOUT and STDERR. In zsh however both STDOUT and STDERR end up on STDOUT.

---
### The streamos
Previously we mentioned a couple of streams; STDIN(0) STDOUT(1) and STDERR(2) these are the three streams connected to the commandline.

STDIN (0) - Standard Input (data fed into the program)
STDOUT (1) - Standard Output (data printed by the program, default of the terminal)
STDERR (2) - Standard Error (for messages, also defaults to the terminal <- what does this even mean..?)


	STDIN (0) --> [ SOME PROGRAM ] --> STDOUT (1)
				+----------> STDERR (2)

*Standard error* is an alternative mechanism for writing output from a program. It's a different link to the same output terminal as STDOUT, but
is unbuffered so error messages can be written immediately instead of one line at a time. All three of the streams have their own ID values, also
referred to as file descriptors in some cases.

---
### File redirection
So besides redirecting and piping from one stream to another, we can also do so from a file. What this means is that we're using the contents of said file as input for our command or program. To redirect from a file we use `some_command < our_textfile`. We can now also redirect that output (so the output of "some_command < ourtextfile") to another file. This looks like:
> `some_command < our_textfile > some_outputfile`

To redirect STDERR messages we use 2>. here the 2 signals which stream we are accessing and the "greater than" symbol signals/ points where we're pointing to. So `non_existent_file grep -c 2>&outfile` effectively pipes the output on STDERR to outfile. Similarly 
---

### Approved Functionez.
open(const char *path, int oflag, ...) - open or create a file for reading or writing, depending on which flags you pass into it when calling the function.
Returns: >=3 on succes (this is your fd), -1 and errno is set on error. 

close(int fd) - *deletes* a descriptor from the per-process object reference table (ORT). If this is the last reference within said ORT, the obect wil be deactivated. 
Returns: 0 upon completion, -1 and errno is set on error. 

read(int fildes, void *buf, size_t nbyte) - attempts to read nbytes if data from the object referenced by fd into buffer pointed to by buff. 
Returns: On succes num of bytes actually read, -1 and errno is set on error.

write(int fildes, const void *buf, size_t nbyte) - attempts to write nbytes if data from the object referenced by fd into buffer pointed to by buff.
Returns: On succes num of bytes actually written, -1 and errno is set on error.

perror(const char *s) - finds error message that's paired to/wtih current value of the global variable errno() and writes it iwth a \n to STDERR. This func also takes an argument if non-NULL this string is prepended to the message string and separated from it by a colon and space (\`\`: ''); otherwise, only the error message string is printed. If the error number is not recognized, these functions return an error message string containing \`\`Unknown error: '' followed by the error number in decimal.

strerror(int errnum) - accepts an error number argument errnum and returns a pointer to the corresponding message string.

access(const char *path, int mdoe) - checks whether we can access the file named by *path, for the permissions specified by mode argument. Mode can either be bitwise-inclusive OR (R_OK for read permission, W_OK for write permission, and X_OK for execute/search permission), or the existence test (F_OK).
Returns:  -1 and errno is set on error.

dup(int fd) - duplicates an existing object descriptor and returns its value to the calling process (fildes2 = dup(fildes)).
CoolioThing:: you can call getdtablesize(), to for one get the size of your ORT, but also to find out what number your last fd is. TRY THIS.

dup2(int fd, int fd2) - this is basically a redirect, fd two now instead also points to fd2. 

execve(const char *path, char *const argv[], char *const envp[]) -  Transforms the calling process into a new process. The new process is constructed from an ordinary file, whose name is pointed to by path, called the new process file. 

	The argument argv is a pointer to a null-terminated array of character pointers to null-terminated character strings.
	The argument envp is also a pointer to a null-terminated array of character pointers to null-terminated strings.

 File descriptors open in the calling process image remain open in the new process image, except for those for which the close-on-exec flag is set (see close(2) and fcntl(2)).

 Returns: As the execve() function overlays the current process image  with a new process image, the successful call has no process to return to.  If execve() does return to the calling process, an error has occurred; the return value will be -1 and the global variable errno is set to indicate the error.

exit(int status) - 'normal' program execution. Before termination, exit() performs the following functions in the order listed:

           1.   Call the functions registered with the atexit(3) function, in the reverse order of their registration.

           2.   Flush all open output streams.

           3.   Close all open streams.

           4.   Unlink all files created with the tmpfile(3) function.

Return: Well.. they don't... kinda makes sense, no?

pid_t fork(void) - creates a new process. The new process is an exact copy of the calling process, 

        o   The child process has a unique process ID.

        o   The child process has a different parent process ID (i.e., the process ID of the parent process).

        o   The child process has its own copy of the parent's descriptors.  These descriptors reference the same underlying
               objects, so that, for instance, file pointers in file objects are shared between the child and the parent, so that an lseek(2) on a descriptor in the child process can affect a subsequent read or write by the parent.  This descriptor copying is also used by the shell to establish standard input and output for newly created processes as well as to set up pipes.
Returns: 0 to the new process (the kid..) and the newID to parent. Otherwise -1 to parent and errno is set.

pipe(void) - creates a descriptor pair for interprocess communicatin. It creates a pipe (something like a one way street for data). In doing so it allocates a pair of file descriptors for its entrance (this is the read end) and exit (this is the write end). Data written to fildes[1] appears on (i.e., can be read from) fildes[0]. The pipe itself persists until all of its associated descriptors are closed.
Returns: 0 if succesful, -1 and errno are set on error.

unlink(const char *path) - removes the link named by path from its directory and decrements the link count of the file which was referenced by the link.  If that decrement reduces the link count of the file to zero, and no process has the file open, then all resources associated with the file are reclaimed.  If one or more process have the file open when the last link is removed, the link is removed, but the removal of the file is delayed until all references to it have been closed.

wait(int *stat_loc) - 'pauses' the calling process until stat_loc info ir available for a starved kid. 

waitpid(pid_t pid, int *stat_loc, int options) - rovides a more general interface for programs that need to wait for certain child processes, that need resource utilization statistics accumulated by child processes, or that require options.

	The *pid* parameter specifies the set of child processes for which to wait.  If pid is -1, the call waits for any child process. If pid is 0, the call waits for any child process in the process group of the caller.  If pid is greater than zero, the call waits for the process with process id pid.  If pid is less than -1, the call waits for any process whose process group id equals the absolute value of pid.

	The *options* parameter contains the bitwise OR of any of the following options. The WNOHANG option is used to indicate that the call should not block if there are no processes that wish to report status. If the WUNTRACED option is set, children of the current process that are stopped due to a SIGTTIN, SIGTTOU, SIGTSTP, or SIGSTOP signal also have their status reported.

##	Some info I still want to look at

### QUESTIONEZ
How many descriptors can there be per process? The man page of close() states that
> When a process exits, all associated file descriptors are freed, but since there is a limit on active descriptors per
processes, the close() function call is useful when a large quantity of file descriptors are being handled.



### Greta thunberg 
https://www.gnu.org/software/libc/manual/html_node/Standard-Environment.html

https://www.gnu.org/software/libc/manual/html_node/Program-Arguments.html

### On redirects and piping
https://www.liquidweb.com/kb/how-to-use-linux-pipe-for-redirection/#:~:text=A%20pipe%20is%20a%20form,placed%20between%20any%20two%20commands.

https://ryanstutorials.net/linuxtutorial/piping.php

https://www.geeksforgeeks.org/piping-in-unix-or-linux/

https://linuxhandbook.com/pipe-redirection/

###	README INFO

https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet

https://www.makeareadme.com/

https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax

