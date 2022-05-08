/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuramat <smuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 20:44:11 by smuramat          #+#    #+#             */
/*   Updated: 2022/05/06 20:41:59 by smuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <assert.h>
# include <memory.h>
# include <limits.h>

int	ft_cv_pointer(unsigned long int main_p);
int	ft_cv_unsigned(unsigned int main_u);
int	ft_cv_HEX(unsigned int main_x, const char style, size_t flag);
int	ft_cv_int(int n, int flag);
int	ft_printf(const char *str, ...);
int	ft_put_char(int c);

#endif