#include "ft_printf.h"

char	*ft_ptrcut(char *str)
{
	int 	i;
	int		j;
	char	*new;

	i = 2;
	j = 0;
	if (!(new = (char*)malloc(sizeof(char) * ft_strlen(str) - 1)))
		return (NULL);
	while (str && str[i])
		new[j++] = str[i++];
	new[j] = '\0';
	return (new);
}

char	*ft_ptrpoint(char *arg, t_struct *s_flags)
{
	char	*str;
	int		i;

	i = 2;
	if (!(str = (char*)malloc(sizeof(char) * s_flags->point - ft_strlen(arg) + 1)))
		return (NULL);
	str[0] = '0';
	str[1] = 'x';
	while (i < s_flags->point - ft_strlen(arg) + 2)
		str[i++] = '0';
	str[i] = '\0';
	return (str);
}
