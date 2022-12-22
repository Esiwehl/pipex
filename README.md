# pipex
## Because sometimes your data needs to be redirected.

### What is it actually about tho..?
The concept of piping and redirecting basically covers how we connect streams to programs and files.

We can redirect in various ways; 
> The output of a command to a file [`ls -l > some_file`] 
> The input from a file (or STDIN) to some command [`grep -c some_word < some_file`] == [`cat some_file | grep -c some_word`]

In this last example we showed the similarities betwe

#### Diff? Is there one..?
> A *pipe* passes the standard output as the standard input to another command. Think of the shittrain thingy in southpark - that ass to moutoh type of thing..

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

To redirect STDERR messages we use 2>. here the 2 signals which stream we are accessing and the "greater than" symbol signals/ points where we're pointing to.

---