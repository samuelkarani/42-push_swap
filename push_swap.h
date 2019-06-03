/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:53:02 by smbaabu           #+#    #+#             */
/*   Updated: 2019/05/12 16:43:59 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/get_next_line/get_next_line.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct		s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

# define MAX_INT 2147483647
# define MIN_INT -2147483648

int					main_shared(int ac, char **av, void (*f)(t_stack*,
						int *flags));
void				push_swap(t_stack **ss[], int *slens, int *flags);
void				checker(t_stack *a, int *flags);
void				apply_inst(t_stack **ss[], char *s, int *flags, int ps);
void				partition(t_stack **ss[], int *slens, int *flags, int *mcb);
int					glen(int len);
void				pa(t_stack **a, t_stack **b, int blen, int *flags);
void				check_swap(t_stack **a, t_stack **b, int *flags);
void				sort_three(t_stack **a, t_stack **b, int *flags, int cb);
void				sort_b(t_stack **a, t_stack **b, int *nums, int *flags);
void				a_mult(t_stack **a, t_stack **b, char *s[], int *flags);
void				get_bool(t_stack *s, int *nums, int cb);

t_stack				*create(int n);
void				push(t_stack **s, int n);
int					pop(t_stack **s);
void				destroy(t_stack	**s);
int					size(t_stack *s);
int					median(t_stack *s, int l, int (*cmp)(int, int));
void				print(t_stack *a, t_stack *b, int c);

int					check_integer(char *s);
int					check_size(long n);
int					check_duplicates(t_stack *s, int n);
int					check_inst(char *s);
int					check_win(t_stack *a, t_stack *b);
int					check_sorted(t_stack *s, int (*cmp)(int, int));
int					check_sorted_upto(t_stack *s, int upto,
						int (*cmp)(int, int));
void				check_print(char *s, int *flags, t_stack *a, t_stack *b);
int					check_space(char *s);

int					gt(int a, int b);
int					lt(int a, int b);
long				ft_atoi_l(const char *str);
void				get_integers(char *s, t_stack **a);
void				error(void);
void				win(void);
void				ko(void);
void				error_free(void *p);
void				copy_reverse(t_stack **a);
void				ko_exit(void);

#endif
