/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placeholder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 11:10:44 by mgautier          #+#    #+#             */
/*   Updated: 2019/05/28 11:10:44 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H
# include <stddef.h>
# include <stdarg.h>

/*
** strlen and variants
** Implementation file : <function name for each, mostly>
*/

size_t	ft_strlen(const char *str);
size_t	ft_strnlen(const char *str, size_t size);
size_t	ft_strlen_gen(const char *str, char end_of_line);
size_t	ft_strnlen_gen(const char *str, size_t size,
		char end_of_line);

/*
** Duplication
** Implementation file : ft_strdup.c
*/

char	*ft_strdup(const char *src);
char	*ft_strndup(const char *src, size_t	size);
char	*ft_strdup_to(const char *src, char end);
char	*ft_strndup_to(const char *src, size_t	size, char end);

char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/*
** Gen strdup
** Implementation file : ft_gen_strdup.c
*/

void	*ft_gen_strdup(const void *src);
/*
** Compare
** Implementation files : name of the function (except for ft_strequ_short,
** same as ft_strequ).
*/

int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*
** Search char in string
** Implementation files : name of the function
*/

char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	last_char_of(const char *str);

/*
** Search string in string
** Implementation files : name of the function
*/

char	*ft_strstr(const char *big, const char *little);
char	*ft_strnstr(const char *big, const char *little, size_t len);

char	**ft_strsplit(char const *s, char c);
char	**strsplit_with_str(char const *src, char const *seps);

/*
** Join strings
** Implementation files : name of the function
*/

char	*f_strljoin(char const *str_1, char const *str_2,
									size_t size_1, size_t size_2);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strvajoin(size_t nb_string, ...);
char	*ft_strjoin_ifnot(const char *src, const char *add);

/*
** Ressources management
** Implementation files : name of the function
*/

char	*ft_strnew_char(size_t size, char c);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_gen_strdel(void **str);
void	ft_strclr(char *s);

/*
** Iteration on elements, transformation
** Implementation files : name of the function
*/

void	ft_striter(char *s, void (*f)(char*));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s);

/*
** Substring functions
** Implementation file : ft_substring.c
*/

size_t	is_substring_up_to(const char *to_search, const char *to_be_searched);
size_t	is_initial_substring(const char *substring, const char *string);
char	*ft_strsub(char const *s, unsigned int start, size_t len);

/*
** Display strings
** Impelmentation file : name of the function
*/

void	ft_putstr(const char *s);
void	ft_putendl(const char *s);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putendl_fd(const char *s, int fd);

/*
** Relay of display string for higher order functions (used as functions
** pointers)
** Implementation file : string_put_gen.c
*/

void	ft_gen_putstr(void const *s);
void	ft_gen_putendl(void const *s);
void	ft_gen_putstr_fd(int fd, void const *s);
void	ft_gen_putendl_fd(int fd, void const *s);
void	ft_putstr_fd_sep_gen(void const *s, va_list args);

#endif
