/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuramat <smuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:25:58 by smuramat          #+#    #+#             */
/*   Updated: 2022/05/06 20:42:11 by smuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_put_str(char *str)
{
	char	*null;

	null = "(null)";
	if (str == NULL)
	{
		write(1, null, ft_strlen(null));
		return (6);
	}
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int	ft_put_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_put_zero(void)
{
	write(1, "0", 1);
	return (1);
}

int	ft_put_char(int c)
{
	write(1, &c, 1);
	return (1);
}
