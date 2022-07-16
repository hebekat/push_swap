/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tohebeka <tohebeka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 18:33:10 by tohebeka      #+#    #+#                 */
/*   Updated: 2022/07/16 13:08:41 by tohebeka      ########   odam.nl         */
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

void	push(t_stack *stack_a, t_stack *stack_b, int direction)
{
	if (direction)
	{
		stack_b->previous = stack_a;
		stack_b->previous->next = stack_b;
		stack_b = stack_b->previous;
		stack_a = stack_a->next;
		stack_a->previous = NULL;
	}
}

void	fill_stack_a(t_stack *stack_a, int argc, char *argv[])
{
	int		i;

	stack_a->previous = NULL;
	i = 0;
	if (argc > 1)
	{
		while (i < argc - 2)
		{
			stack_a->value = atoi(argv[i + 1]);
			stack_a->next = (t_stack *) malloc(sizeof(t_stack));
			stack_a->next->previous = stack_a;
			stack_a = stack_a->next;
			i++;
		}
		stack_a->value = atoi(argv[i + 1]);
		stack_a->next = NULL;
	}
	while (stack_a->previous)
		stack_a = stack_a->previous;
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack *stack_b;

	stack_a = (t_stack *) malloc(sizeof(t_stack));
	stack_b = (t_stack *) malloc(sizeof(t_stack));
	stack_b->next = NULL;
	stack_b->previous = NULL;
	fill_stack_a(stack_a, argc, argv);
	
	push(stack_a, stack_b, 1);
	// push(stack_a, stack_b, 1);
	// push(stack_a, stack_b, 1);

	while (stack_a->next)
	{
		printf("%d ", stack_a->value);
		stack_a = stack_a->next;
	}
	printf("%d ", stack_a->value);
	printf("\n");
	// while (stack_b->next)
	// {
	// 	printf("%d ", stack_b->value);
	// 	stack_b = stack_b->next;
	// }
	//printf("%d ", stack_b->value);
}
