/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tohebeka <tohebeka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 18:33:10 by tohebeka      #+#    #+#                 */
/*   Updated: 2022/08/02 17:51:18 by tohebeka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
// A function to implement bubble sort
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
				swap(&arr[j], &arr[j + 1]);
			j++;
		}
		j = 0;
		i++;
	}
}

char **simplify_array(char *argv[], int argc)
{
	int *buf_arr;
	int	i;

	i = 0;
	buf_arr = malloc(sizeof(int) * argc - 1);
	while (i < argc - 1)
	{
		buf_arr[i] = atoi(argv[i]);
		i++;
	}
	bubbleSort(buf_arr, argc - 1);
	i = 0;
	while(i<argc-1)
		printf("%d ", buf_arr[i++]);
}

void sort_stacks(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		sort_bit(stack_a, stack_b, i, stack_size);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack *stack_b;

	stack_a = (t_stack *) malloc(sizeof(t_stack));
	fill_stack_a(stack_a, argc, argv);
	sort_stacks(&stack_a, &stack_b, argc - 1);
	simplify_array(argv, argc);
	//print_stacks(stack_a, stack_b);
}
