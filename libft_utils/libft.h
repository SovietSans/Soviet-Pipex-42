/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttremel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:54:17 by soviet            #+#    #+#             */
/*   Updated: 2025/02/14 16:07:38 by soviet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>

size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dest, const char *src, size_t n);
size_t			ft_strlen(const char *str);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memdup(void *dest, size_t n);
void			*ft_memset(void *dest, int value, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_bzero(void *dest, size_t n);
void			ft_putendl_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strcat(char *dest, const char *src);
char			**ft_split(char const *s, char c);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_join(char **strs, char *sep, size_t size);
char			*ft_strrchr(const char *s, int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(char *str);
char			*ft_strndup(char *str, size_t n);
char			*ft_itoa(int n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_abs(int x);
long int		ft_atol(const char *str);
long long int	ft_atoll(const char *str);

#endif
