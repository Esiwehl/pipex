/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 13:55:29 by ewehl         #+#    #+#                 */
/*   Updated: 2022/10/28 13:55:29 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# include "libft.h"

int		ft_printf(const char *format, ...);
size_t	ft_getlen(size_t num, size_t base);
char	*base_def(char flag);
char	*ft_itoa(int n);

size_t	ft_putstr_len(char *str);
size_t	ft_putchar_len(int c);
size_t	ft_putnbr_len(int n);

size_t	ft_putptr(unsigned long ptr);
size_t	ft_puthex(unsigned long n, char format);

size_t	ft_putuint(unsigned int n);
char	*ft_uitoa(unsigned int n);
#endif
