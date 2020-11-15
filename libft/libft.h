/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:39:51 by mobouzar          #+#    #+#             */
/*   Updated: 2019/12/04 14:35:06 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <float.h>
# include <math.h>

typedef	struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

/*
** get_next_line structer
*/

# define BUFF_SIZE 1

typedef struct			s_gnl
{
	char				buff[BUFF_SIZE + 1];
	int					c;
	int					p;
}						t_gnl;

/*
** ft_printf structers
*/

# define ZERO	0b0000000000000001
# define HASH	0b0000000000000010
# define SPACE	0b0000000000000100
# define PLUS	0b0000000000001000
# define MINUS	0b0000000000010000
# define LONG	0b0000000000100000
# define LL		0b0000000001000000
# define H		0b0000000010000000
# define HH		0b0000000100000000
# define L_D	0b0000001000000000

# define I(x)	(x - '0')
# define K(x)	(x + '0')

typedef struct			s_init
{
	short				flag;
	char				specifier;
	int					precision;
	int					width;
}						t_init;

typedef struct			s_var
{
	int					s_a;
	int					s_b;
	int					i;
	int					k;
	int					rest;
	int					len;
	int					csnt;
	char				*result;
	char				*str;
	char				*tmp;
	char				*tmp_2;
	char				aa;
	char				bb;
}						t_var;

typedef struct			s_data
{
	unsigned long long	mantissa :	63;
	unsigned long long	as :		1;
	long long			exp :		15;
	unsigned long long	sign :		1;
}						t_data;

typedef union			u_float
{
	long double			f;
	t_data				list;
}						t_float;

/*
** ft_printf functions
*/

int						ft_print_d(va_list list, t_init *lst);
int						ft_print_base(va_list list, t_init *lst);
int						ft_print_s(va_list list, t_init *lst);
int						ft_print_c(va_list list, t_init *lst);
int						ft_print_f(va_list list, t_init *lst);
int						ft_print_persent(t_init *lst);
void					ft_init(t_init *lst);
char					*ft_sum(char *a, char *b);
char					*ft_produit(char *a, char *b);
char					*ft_power(char *str, long n);
char					*ft_putstr_float(char *src, char *dst, char *tmp,
						t_init *lst);
char					*ft_check(t_init *lst, char *str, char **tmp);
char					*ft_strjoin_00(char *dst, int i);
char					*ft_exponent(t_data *lst, int prs, t_init *list);
char					*ft_rounding(char *srcs, char *dst, t_init *lst,
						int prs);
int						ft_printf(const char *format, ...);
int						ft_print_format(va_list list, const char *format,
						t_init *f);
char					*ft_push_c(char *str, int i, char *c, int ps);
char					*ft_manage_width(t_init *lst, char *str);
int						ft_get_flag_of_format(t_init *lst, const char *format);
int						ft_char_nbr(char c);
int						ft_str_nbr(char *str);

/*
** libft functions
*/

int						get_next_line(const int fd, char **line);
char					**ft_split_format(char *str, char c);
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst, const void *src, int c,
size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
size_t					ft_strlen(const char *s);
char					*ft_strdup(const char *s1);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t len);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *haystack, const char *needle);
char					*ft_strnstr(const char *haystack, const char *needle
, size_t len);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_atoi(const char *str);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);

void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
char (*f)(unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s, unsigned int start,
size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
char					*ft_itoa(long long int n);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
int						ft_strcspn(const char *str, const char *charset);
int						ft_strspn(const char *str, const char *charset);
int						ft_ceil(int nbr1, int nbr2);
void					ft_putnbr_fd(int n, int fd);

t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst,
void (*del)(void *, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

long long int			ft_abs(long long int n);
void					ft_swap(int *a, int *b);
char					*ft_strnew_00(size_t size);
char					*ft_strrev(char *str);
int						ft_getcharindex(char *str, char c);
void					ft_lstdisplcont(t_list *lst);
void					ft_lstendadd(t_list *alst, t_list *new);
char					*ft_itoa_base(unsigned long long int value, int base);
int						ft_lstsupp(t_list *lst);
char					*ft_str_toupper(char *str);
int						ft_sqrt(int nb);
char					*ft_strjoin_00(char *dst, int i);
int						ft_char_nbr(char c);
int						ft_str_nbr(char *str);
char					*ft_safe(char *str, char *temp);
char					*ft_strjoin_free(char *s1, char *s2);

#endif
