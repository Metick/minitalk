/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:20:17 by sgrootve          #+#    #+#             */
/*   Updated: 2023/10/02 15:15:44 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h> // size_t
# include <stdlib.h> // Malloc
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

extern int		ft_isalpha(int c);
extern int		ft_isdigit(int c);
extern int		ft_isalnum(int c);
extern int		ft_isascii(int c);
extern int		ft_isprint(int c);
extern size_t	ft_strlen(const char *s);
extern void		*ft_memset(void *s, int c, size_t n);
extern void		ft_bzero(void *s, size_t n);
extern void		*ft_memcpy(void *dest, const void *src, size_t n);
extern void		*ft_memmove(void *dest, const void *src, size_t n);
extern size_t	ft_strlcpy(char *dst, const char *src, size_t size);
extern size_t	ft_strlcat(char *dst, const char *src, size_t size);
extern int		ft_toupper(int c);
extern int		ft_tolower(int c);
extern char		*ft_strchr(const char *s, int c);
extern char		*ft_strrchr(const char *s, int c);
extern int		ft_strncmp(const char *s1, const char *s2, size_t n);
extern void		*ft_memchr(const void *s, int c, size_t n);
extern int		ft_memcmp(const void *s1, const void *s2, size_t n);
extern char		*ft_strnstr(const char *big, const char *little, size_t len);
extern int		ft_atoi(const char *nptr);
extern void		*ft_calloc(size_t nmemb, size_t size);
extern char		*ft_strdup(const char *s);
extern char		*ft_substr(char const *s, unsigned int start, size_t len);
extern char		*ft_strjoin(char const *s1, char const *s2);
extern char		*ft_strtrim(char const *s1, char const *set);
extern char		**ft_split(char const *s, char c);
extern char		*ft_itoa(int n);
extern char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
extern void		ft_striteri(char *s, void (*f)(unsigned int, char*));
extern void		ft_putchar_fd(char c, int fd);
extern void		ft_putstr_fd(char *s, int fd);
extern void		ft_putendl_fd(char *s, int fd);
extern void		ft_putnbr_fd(int n, int fd);
extern char		*ft_litoa_base(long long int n, const char *base);
extern char		*ft_itoa_base(int n, const char *base);
extern char		*ft_ulitoa_base(unsigned long n, const char *base);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

extern t_list	*ft_lstlast(t_list *lst);
extern void		ft_lstadd_front(t_list **lst, t_list *new);
extern t_list	*ft_lstnew(void *content);
extern int		ft_lstsize(t_list *lst);
extern void		ft_lstadd_back(t_list **lst, t_list *new);
extern void		ft_lstdelone(t_list *lst, void (*del)(void*));
extern void		ft_lstclear(t_list **lst, void (*del)(void*));
extern void		ft_lstiter(t_list *lst, void (*f)(void *));
extern t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

extern int		ft_printf(const char *str, ...);

/*Prints*/
extern int		ft_printf_int(int n, const char *base);
extern int		ft_printf_uint(long long n, const char *base);
extern int		ft_printf_char(char c);
extern int		ft_print_string(const char *str);
extern int		ft_print_pointer(void *ptr);

/*Formatter*/
extern int		ft_format(const char *str, va_list args);
extern int		ft_printf(const char *str, ...);
#endif
