/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_move5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 05:13:41 by mlinhard          #+#    #+#             */
/*   Updated: 2016/04/26 19:42:36 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void			ps_move5_swap(t_psstack *stack)
{
	int		val;
	int		i;

	val = stack->val;
	i = stack->i;
	stack->val = (stack->p)->val;
	stack->i = (stack->p)->i;
	(stack->p)->val = val;
	(stack->p)->i = i;
}

void			ps_move5_push(t_psstack **src, t_psstack **dst)
{
	t_psstack			*cut;

	cut = *src;
	((*src)->p)->n = (*src)->n;
	((*src)->n)->p = (*src)->p;
	*src = ((*src)->p == (*src)) ? NULL : (*src)->p;
	if (!(*dst))
	{
		*dst = cut;
		(*dst)->n = cut;
		(*dst)->p = cut;
		return ;
	}
	cut->p = (*dst);
	cut->n = (*dst)->n;
	((*dst)->n)->p = cut;
	(*dst)->n = cut;
	(*dst)->p = ((*dst)->p == *dst) ? cut : (*dst)->p;
	*dst = cut;
}

void			ps_move5_log(t_psdata *ps, enum e_move move)
{
	char		*tmp;

	tmp = ps->log5;
	if (move == sa)
		ft_printf("%-!%s sa", &ps->log5, tmp);
	if (move == sb)
		ft_printf("%-!%s sb", &ps->log5, tmp);
	if (move == ss)
		ft_printf("%-!%s ss", &ps->log5, tmp);
	if (move == pa)
		ft_printf("%-!%s pa", &ps->log5, tmp);
	if (move == pb)
		ft_printf("%-!%s pb", &ps->log5, tmp);
	if (move == ra)
		ft_printf("%-!%s ra", &ps->log5, tmp);
	if (move == rb)
		ft_printf("%-!%s rb", &ps->log5, tmp);
	if (move == rr)
		ft_printf("%-!%s rr", &ps->log5, tmp);
	if (move == rra)
		ft_printf("%-!%s rra", &ps->log5, tmp);
	if (move == rrb)
		ft_printf("%-!%s rrb", &ps->log5, tmp);
	if (move == rrr)
		ft_printf("%-!%s rrr", &ps->log5, tmp);
}

void			ps_move5_print(t_psdata *ps, enum e_move move)
{
	if (move == sa)
		ft_printf("[STUPID] move %d: sa\n", (1 + ps->nb5));
	if (move == sb)
		ft_printf("[STUPID] move %d: sb\n", (1 + ps->nb5));
	if (move == ss)
		ft_printf("[STUPID] move %d: ss\n", (1 + ps->nb5));
	if (move == pa)
		ft_printf("[STUPID] move %d: pa\n", (1 + ps->nb5));
	if (move == pb)
		ft_printf("[STUPID] move %d: pb\n", (1 + ps->nb5));
	if (move == ra)
		ft_printf("[STUPID] move %d: ra\n", (1 + ps->nb5));
	if (move == rb)
		ft_printf("[STUPID] move %d: rb\n", (1 + ps->nb5));
	if (move == rr)
		ft_printf("[STUPID] move %d: rr\n", (1 + ps->nb5));
	if (move == rra)
		ft_printf("[STUPID] move %d: rra\n", (1 + ps->nb5));
	if (move == rrb)
		ft_printf("[STUPID] move %d: rrb\n", (1 + ps->nb5));
	if (move == rrr)
		ft_printf("[STUPID] move %d: rrr\n", (1 + ps->nb5));
	ps_stack_print(ps, ps->st5a);
	ps_stack_print(ps, ps->st5b);
}

int				ps_move5(t_psdata *ps, enum e_move move)
{
	if (ps->verb)
		ps_move5_print(ps, move);
	if (move == sa || move == ss)
		ps_move5_swap(ps->st5a);
	if (move == sb || move == ss)
		ps_move5_swap(ps->st5b);
	if (move == pa)
		ps_move5_push(&ps->st5b, &ps->st5a);
	if (move == pb)
		ps_move5_push(&ps->st5a, &ps->st5b);
	if (move == ra || move == rr)
		ps->st5a = ps->st5a->p;
	if (move == rb || move == rr)
		ps->st5b = ps->st5b->p;
	if (move == rra || move == rrr)
		ps->st5a = ps->st5a->n;
	if (move == rrb || move == rrr)
		ps->st5b = ps->st5b->n;
	if (!ps->log5 && !(ps->log5 = ft_strnew(0)))
		ps_error(ps, 100);
	ps->nb5++;
	ps_move5_log(ps, move);
	return (1);
}
