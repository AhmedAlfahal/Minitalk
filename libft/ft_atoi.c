/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:10:51 by aalfahal          #+#    #+#             */
/*   Updated: 2023/01/21 18:46:33 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	val(const char *va, int n, int sgn)
{
	unsigned long long	res;

	res = 0;
	while (va[n] == '0' && va[n] != '\0')
		n++;
	while (va[n] != '\0' && va[n] >= '0' && va[n] <= '9')
	{
		res = (res * 10) + (va[n] - '0');
			n++;
		if ((res > 9223372036854775807 && sgn == 1)
			|| (ft_strlen(va) - n >= 19 && sgn == 1))
			exit(0);
		else if ((res > 9223372036854775807 && sgn == -1)
			|| (ft_strlen(va) - n >= 19 && sgn == -1))
			exit(0);
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sgn;
	unsigned long long	res;

	i = 0;
	sgn = 1;
	res = 0;
	while (str[i] == ' ' || ((str[i] >= 9) && (str[i] <= 13)))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if ((str[i] == '-' || str[i] == '+')
			&& (str[i + 1] == '-' || str[i + 1] == '+'))
			return (0);
		else if (str[i] == '-')
				sgn = -1;
			i++;
	}
	res = val (str, i, sgn);
	return (res * sgn);
}
