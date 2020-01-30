#include "ft_printf.h"
#include <stdio.h>

int		main()
{
	int *p;
	int a = 2000000;

	p = &a;
	printf("\n%d, ", printf("real |yo tout le monde c'est %10s, %4c, patate %20p....|\n", "squeezie", '\0', p));
	printf("%d", ft_printf("mine |yo tout le monde c'est %10s, %4c, patate %20p....|\n", "squeezie", '\0', p));
	return (0);
}

/*
Tester : c, s, d, i, u, p, x, X

	c
- width : w - c espaces/zero avant/apres le c
- point : pas d'effet
- width > point : w - c espaces/zero avant/apres le c
- width < point : w - c espaces/zero avant/apres le c
- width = point : width only

	s
- width : w - str espaces/zero avant/apres la str
- point : pas d'effet
- width > point :	si point < str : point char de str avant/apres w espaces/zeros
					si point > str : w - str espaces/zero avant/apres la str
- width < point : w - str espaces/zero avant/apres la str
- width = point : width only

	u
- width : w - len espaces/zero avant/apres uns
- point : p - len zeros avant l'un
- width > point :	si point > uns : p - uns, avant/apres w - (p - uns) espaces
					si point < uns : width only
- width < point : point only
- width = point : point only

	i / d
- width : w - int espaces/zero avant/apres int
- point :	si int < 0 : - puis p - int zeros avant l'int
			si int >= 0 : p - int zeros avant l'int
- width > point :	si int < 0 : w espaces - 1 avant/apres - puis p - int zeros avant int, le - tjr avant les zeros
					si int > 0 : w espaces avant/apres p zeros - int avant int
- width < point : point only
- width = point : point only

	pt
- width : w - p espaces avant/apres pt, si 0 : qpres 0x mais 0x compte
- point : 0x pas pris en compte. 0x puis p zeros - pt avant pt
- width > point :	si point < pt : width only
					si point > pt : point only
- width < point : point only
- width = point : point only

	x / X
- width : w - x espaces/zero avant/apres x
- point : p - x espaces/zero avant/apres x
- width > point :	si point < x : width only
					si point > x : p - x zeros avant/apres w - (p-x)
- width < point : point only
- width = point : point only
*/
