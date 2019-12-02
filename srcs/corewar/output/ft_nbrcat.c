/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 11:59:45 by abaurens          #+#    #+#             */
/*   Updated: 2019/12/02 12:13:57 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static const int	g_ten_pow[] = {
	1000000000, 100000000, 10000000,
	1000000, 100000, 10000, 1000,
	100, 10, 1, 0
};

char	*ft_nbrcat(char *dst, register int n)
{
	register int	i;
	register int	j;

	i = 0;
	j = 0;
	*dst = '0';
	if (n < 0)
		dst[j++] = '-';
	while (g_ten_pow[i] && !(n / g_ten_pow[i]))
		++i;
	while (g_ten_pow[i])
	{
		if ((dst[j] = ((n / g_ten_pow[i]))) < 0)
			dst[j] *= -1;
		dst[j++] += '0';
		n %= g_ten_pow[i++];
	}
	return (dst);
}
