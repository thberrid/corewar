/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_cos.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 07:44:09 by abaurens          #+#    #+#             */
/*   Updated: 2019/09/30 14:02:09 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef K_COS_H
# define K_COS_H

# define C1	4.16666666666666019037e-02
# define C2	-1.38888888888741095749e-03
# define C3	2.48015872894767294178e-05
# define C4	-2.75573143513906633035e-07
# define C5	2.08757232129817482790e-09
# define C6	-1.13596475577881948265e-11

double	ft_kernel_cos(double x,
			double y) __attribute__((visibility("internal")));

#endif
