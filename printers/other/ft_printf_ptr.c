/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:55:43 by olimarti          #+#    #+#             */
/*   Updated: 2022/12/19 20:24:39 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_printf_ptr(va_list *argptr)
{
	unsigned long	*current_arg;

	current_arg = (void *)va_arg(*argptr, unsigned long);
	if (current_arg == 0)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	return (2 + ft_put_u_nbr_base(current_arg, 16, HEX_LC_ALPHABET));
}
