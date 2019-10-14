/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmath.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 02:29:20 by abaurens          #+#    #+#             */
/*   Updated: 2019/08/22 15:31:39 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTMATH_H
# define FTMATH_H

# include <inttypes.h>

# define FT_HPI	1.5707963267948966192313
# define FT_PI	3.1415926535897932384626
# define FT_TPI	6.2831853071795864769252
# define FT_E	2.71828182845904523536028747135266249775724709369995957496696763
# define FT_LN2	0.69314718055994530942869047418497530088643543422222137451171875

char		fnan(long double d);

float		ft_absf(float x);
double		ft_abs(double x);
long double	ft_absl(long double x);

float		ft_minf(float a, float b);
double		ft_min(double a, double b);
long double	ft_minl(long double a, long double b);

float		ft_maxf(float a, float b);
double		ft_max(double a, double b);
long double	ft_maxl(long double a, long double b);

float		ft_powf(float x, int y);
double		ft_pow(double x, int y);
long double	ft_powl(long double x, int y);

float		ft_sqrtf(float nb);
double		ft_sqrt(double nb);
long double	ft_sqrtl(long double nb);

float		ft_radf(float a);
double		ft_rad(double a);

double		ft_tan(double an);
double		ft_cos(double an);
double		ft_sin(double an);

float		ft_logf(float nb);
double		ft_log(double nb);
long double	ft_logl(long double nb);

#endif
