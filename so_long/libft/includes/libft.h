/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguisado <lguisado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:00:15 by lguisado          #+#    #+#             */
/*   Updated: 2023/03/16 18:49:05 by lguisado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*	--	LIBFT	--	*/
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

/*	--	PRINTF	--	*/
# include <stdarg.h>

/*	--	GET_NEXT_LINE	--	*/
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/*	--	LIBFT	--	*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *str, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t len);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
char	*ft_strnstr(const char *str, const char *to_find, size_t size);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
/*	--	ADDITIONALS	--	*/
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
/*	--	BONUS	--	*/
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*	--	PRINTF	--	*/
/*	--	 ft_printf.c	--	*/
int		ft_convert(va_list list, char type);
int		ft_printf(char const *str, ...);

/*	--	 ft_prints.c	--	*/
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nbr);
int		ft_putunbr(unsigned int nbr);

/*	--	 ft_conts.c	--	*/
int		ft_nbrlen(int nbr);
int		ft_unbrlen(unsigned int nbr);
int		ft_hexnbrlen(unsigned int nbr);
int		ft_ptrlen(unsigned long long nbr);

/*	--	 ft_printhex.c	--	*/
int		ft_puthex(unsigned int nbr, char format);
int		ft_putptr(unsigned long long nbr);
void	ft_puthexptr(unsigned long long nbr);

/*	--	GET_NEXT_LINE	--	*/
/*  ---  get_next_line.c  ---  */
char	*ft_strchr_gnl(char *s, int c);
char	*ft_save_left_line(char *save);
char	*ft_get_line(char *save);
char	*ft_read_write_line(int fd, char *save);
char	*get_next_line(int fd);

#endif