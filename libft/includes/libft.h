/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 00:53:32 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/22 14:38:04 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_tree
{
	int				val;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

void				ft_tree_pre(t_tree *root, void (*f)(int));
void				ft_tree_in(t_tree *root, void (*f)(int));
void				ft_tree_post(t_tree *root, void (*f)(int));
void				ft_tree_add_elem(t_tree **root, t_tree *new);
t_tree				*ft_new_tree_elem(int val);
void				ft_list_pushback(t_list **alst, t_list *new);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr(int n);
void				ft_putendl(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strtrim(char const *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strmap(char const *s, char (*f)(char));
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
void				ft_strclr(char *s);
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
char				*ft_strnstr(const char *a, const char *b, size_t len);
int					ft_strncmp(const char *a, const char *b, size_t n);
int					ft_strcmp(const char *a, const char *b);
char				*ft_strstr(const char *a, const char *b);
char				*ft_strrchr(const char *str, int ch);
char				*ft_strchr(const char *str, int ch);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *str);
size_t				ft_strlen(const char *str);
char				*ft_itoa(int n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memccpy(void *d, const void *s, int ch, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t len);
int					ft_atoi(char *str);
void				ft_bzero(void *ptr, size_t len);
void				*ft_memset(void *ptr, int val, size_t len);
void				ft_putstr(char const *str);
void				ft_putchar(char c);

#endif
