/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbrcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 11:59:45 by abaurens          #+#    #+#             */
/*   Updated: 2019/12/02 12:10:29 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static const unsigned int	g_ten_pow[] = {
	1000000000, 100000000, 10000000,
	1000000, 100000, 10000, 1000,
	100, 10, 1, 0
};

char	*ft_unbrcat(char *dst, register unsigned int n)
{
	register int	i;
	register int	j;

	i = 0;
	j = 0;
	*dst = '0';
	while (g_ten_pow[i] && !(n / g_ten_pow[i]))
		++i;
	while (g_ten_pow[i])
	{
		dst[j++] = ((n / g_ten_pow[i])) + '0';
		n %= g_ten_pow[i++];
	}
	return (dst);
}
