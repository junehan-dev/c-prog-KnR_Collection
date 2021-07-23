/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 11:49:16 by junehan           #+#    #+#             */
/*   Updated: 2021/07/23 13:14:22 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_stack_push(void **stack, void *data)
{
	if (!data)
		return (-1);

	if (!*stack && !*(stack + 1))
		*stack = data;

	return ((*stack == data) ? 0 : 1);
}
