/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tohebeka <tohebeka@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 18:33:13 by tohebeka      #+#    #+#                 */
/*   Updated: 2022/07/11 02:29:25 by tohebeka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;
#endif