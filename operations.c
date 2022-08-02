/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tohebeka <tohebeka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/17 19:32:27 by tohebeka      #+#    #+#                 */
/*   Updated: 2022/08/02 19:04:48 by tohebeka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_stack *stack)
{
	int	buf;

	buf = stack->value;
	stack->value = stack->next->value;
	stack->next->value = buf;
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a))
	{
		if ((*stack_a)->next)
		{
			(*stack_a) = (*stack_a)->next;
			(*stack_a)->previous->next = (*stack_b);
			(*stack_b) = (*stack_a)->previous;
			(*stack_a)->previous = NULL;
		}
		else
		{
				(*stack_a)->next = (*stack_b);
				(*stack_b) = (*stack_a);
				(*stack_b)->next->previous = (*stack_b);
				(*stack_a) = 0;
		}
		if ((*stack_b)->next)
			(*stack_b)->next->previous = (*stack_b);
	}
	printf("pb\n");
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_b))
	{
		if ((*stack_b)->next)
		{
			(*stack_b) = (*stack_b)->next;
			(*stack_b)->previous->next = (*stack_a);
			(*stack_a) = (*stack_b)->previous;
			(*stack_b)->previous = NULL;
		}
		else
		{
				(*stack_b)->next = (*stack_a);
				(*stack_a) = (*stack_b);
				(*stack_a)->next->previous = (*stack_a);
				(*stack_b) = 0;
		}
		if ((*stack_a)->next)
			(*stack_a)->next->previous = (*stack_a);
	}
	printf("pa\n");
}

void	rot(t_stack **stack)
{
	int	buf;

	if ((*stack) && (*stack)->next)
	{
		buf = (*stack)->value;
		while ((*stack)->next)
		{
			(*stack)->value = (*stack)->next->value;
			(*stack) = (*stack)->next;
		}
		(*stack)->value = buf;
		while ((*stack)->previous)
			(*stack) = (*stack)->previous;
	}
	printf("ra\n");
}

void	rev_rot(t_stack **stack)
{
	int	buf;

	if ((*stack) && (*stack)->next)
	{
		while ((*stack)->next)
			(*stack) = (*stack)->next;
		buf = (*stack)->value;
		while ((*stack)->previous)
		{
			(*stack)->value = (*stack)->previous->value;
			(*stack) = (*stack)->previous;
		}
		(*stack)->value = buf;
	}
}

void	r_rot(t_stack **stack_a, t_stack **stack_b)
{
	rot(stack_a);
	rot(stack_b);
}

void	rev_r_rot(t_stack **stack_a, t_stack **stack_b)
{
	rev_rot(stack_a);
	rev_rot(stack_b);
}
