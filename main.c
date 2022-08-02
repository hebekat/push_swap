/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tohebeka <tohebeka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 18:33:10 by tohebeka      #+#    #+#                 */
/*   Updated: 2022/08/02 19:20:01 by tohebeka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	fill_stack_a(t_stack *stack_a, int argc, int *stack_pre)
{
	int		i;

	stack_a->previous = NULL;
	i = 0;
	if (argc > 1)
	{
		while (i < argc - 2)
		{
			stack_a->value = stack_pre[i];
			stack_a->next = (t_stack *) malloc(sizeof(t_stack));
			stack_a->next->previous = stack_a;
			stack_a = stack_a->next;
			i++;
		}
		stack_a->value = stack_pre[i];
		stack_a->next = NULL;
	}
	while (stack_a->previous)
		stack_a = stack_a->previous;
}

void print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	printf("Stack A:\n");
	if (stack_a)
	{
		while (stack_a->next)
		{
			printf("%d\n", stack_a->value);
			stack_a = stack_a->next;
		}
			printf("%d\n", stack_a->value);
	}
	printf("\nStack B:\n");
	if (stack_b)
	{
		while (stack_b->next)
		{
			printf("%d\n", stack_b->value);
			stack_b = stack_b->next;
		}
	printf("%d\n\n\n", stack_b->value);
	}

	//printf("prev %x val %d nx %x ad %x\n", stack_b->previous, stack_b->value, stack_b->next, stack_b);
}

void sort_bit(t_stack **stack_a, t_stack **stack_b, int current_bit, int stack_size)
{
	int	i;

	i = 0;
	while (i < stack_size)
	{
		if (((*stack_a)->value >> current_bit) & 1)
			rot(stack_a);
		else
			push_b(stack_a, stack_b);
		i++;
	}
	while ((*stack_b))
		push_a(stack_a, stack_b);
}

void bswap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  

void bubbleSort(int arr[], int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	while (i < n - 1)
	{
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
				bswap(&arr[j], &arr[j + 1]);
			j++;
		}
		j = 0;
		i++;
	}
}

int *simplify_array(char *argv[], int argc)
{
	int *buf_arr;
	int *sort_arr;
	int	i;
	int	j;

	i = 0;
	j = 0;
	buf_arr = malloc(sizeof(int) * argc - 1);
	sort_arr = malloc(sizeof(int) * argc - 1);
	while (i < argc - 1)
	{
		buf_arr[i] = atoi(argv[i + 1]);
		sort_arr[i] = atoi(argv[i + 1]);
		i++;
	}
	bubbleSort(sort_arr, argc - 1);
	i = 0;
	while (i < argc - 1)
	{
		while (j < argc - 1)
		{
			if (buf_arr[i] == sort_arr[j])
				buf_arr[i] = j;
			j++;	
		}
		j = 0;
		i++;
	}
	return (buf_arr);
}

int check_sorted(t_stack *stack_a)
{
	while (stack_a->next)
	{
		if(stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;	
	}
	return(1);
}

void sort_stacks(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	int	i;
	int	sorted;

	i = 0;
	sorted = 0;
	while (i < 16 && sorted == 0)
	{
		sorted = check_sorted((*stack_a));
		sort_bit(stack_a, stack_b, i, stack_size);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack *stack_b;

	stack_a = (t_stack *) malloc(sizeof(t_stack));
	fill_stack_a(stack_a, argc, simplify_array(argv, argc));
	sort_stacks(&stack_a, &stack_b, argc - 1);
	//print_stacks(stack_a, stack_b);
}
