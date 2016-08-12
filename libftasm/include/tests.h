/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 21:10:20 by mngomane          #+#    #+#             */
/*   Updated: 2015/01/30 21:10:20 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <ctype.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>
# include "../libfts/include/libfts.h"

# define KO		0
# define OK		1
# define IN		0
# define OUT	1

extern FILE *stdout;

int				compare_files(char *fname1, char *fname2);
int				debug_bzero(char *str1, char *str2);
int				debug_strcat(char *str1, char *str2, char *str3, char *str4);
int				debug_isalpha(int c);
int				debug_isdigit(int c);
int				debug_isalnum(int c);
int				debug_isascii(int c);
int				debug_isprint(int c);
int				debug_toupper(int c);
int				debug_tolower(int c);
int				debug_strlen(char *str);
int				debug_memset(char *str1, char *str2);
int				debug_memcpy(char *str1, char *str2);
int				debug_strdup(char *str1, char *str2);
int				debug_atoi(char *str);
int				bzero_tests(void);
int				strcat_tests(void);
int				islapha_tests(void);
int				isdigit_tests(void);
int				isalnum_tests(void);
int				isascii_tests(void);
int				isprint_tests(void);
int				toupper_tests(void);
int				tolower_tests(void);
int				strlen_tests(void);
int				memset_tests(void);
int				memcpy_tests(void);
int				strdup_tests(void);
int				atoi_tests(void);
int				puts_tests(void);
int				cat_tests(void);

#endif
