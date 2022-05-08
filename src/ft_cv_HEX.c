/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv_HEX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuramat <smuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:26:11 by smuramat          #+#    #+#             */
/*   Updated: 2022/05/06 20:30:25 by smuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_pointer(char *result);
int	ft_put_str(char *str);
int	ft_put_zero(void);

static int	ft_num_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		len = 1;
	while (num > 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

static char	*ft_to_char(char *res, unsigned int x, const char s, unsigned int l)
{
	unsigned int	check;

	check = 0;
	while (x > 0)
	{
		check = x % 16;
		if (check > 9)
		{
			if (s == 'X')
				res[l] = check - 10 + 'A';
			else if (s == 'x')
				res[l] = check - 10 + 'a';
		}
		else
			res[l] = check + '0';
		x /= 16;
		l--;
	}
	return (res);
}

int	ft_cv_HEX(unsigned int main_x, const char style, size_t flag)
{
	char	*res;
	int		len;

	if (main_x == 0)
		return (ft_put_zero());
	len = ft_num_len(main_x);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	res[len--] = '\0';
	res = ft_to_char(res, main_x, style, len);
	if (flag == 3)
		len = ft_print_pointer(res);
	else
		len = ft_put_str(res);
	free(res);
	return (len);
}
