#include "gnl_exam.h"
#include <stdlib.h>
int to_free(char **ptr)
{
    if(*ptr)
    {
        free(*ptr);
        *ptr = NULL;
    }
    return(-1);
}
size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dest, char *src, size_t n)
{
	char	*psrc;
	char	*pdest;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	psrc = (char*)src;
	pdest = (char*)dest;
	while (i < n)
	{
		pdest[i] = psrc[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(char *s1)
{
	char *dest;

	dest = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s1, (ft_strlen(s1) + 1));
	return (dest);
}

char	*ft_strjoin(char **s1, char **s2)
{
	int		sum;
	char	*newstr;
	char	*str1;
	char	*str2;

	str1 = *s1;
	str2 = *s2;
	if (str1 == NULL || str2 == NULL)
		return (NULL);
	sum = ft_strlen((char *)str1) + ft_strlen((char *)str2);
	newstr = (char *)malloc(sum + 1);
	if (newstr == NULL)
		return (NULL);
	ft_memcpy(newstr, str1, ft_strlen(str1));
	ft_memcpy(newstr + ft_strlen(str1), str2, ft_strlen(str2) + 1);
	free(str1);
	return (newstr);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != c && *s != '\0')
	{
		s++;
	}
	if (*s == c)
	{
		return ((char*)s);
	}
	else
	{
		return (NULL);
	}
}

int		verif_reste(char **rest, char **line)
{
	char	*s;
	char	*tmp;

	if (!*rest)
	{
		if ((*rest = ft_strdup("")) == NULL)
			return (0);
	}
	else if ((s = ft_strchr(*rest, '\n')))
	{
		*s = '\0';
		if ((*line = ft_strdup(*rest)) == NULL)
			return (0);
		tmp = *rest;
		if ((*rest = ft_strdup(s + 1)) == NULL)
			return (0);
		to_free(&tmp);
		return (1);
	}
	return (-1);
}
int		ft_read(char **rest, char **line)
{
	char	*buf;
	int		j;
	char	*s;

	if ((buf = malloc((10000 + 1) * sizeof(char))) == NULL)
		return (-1);
	while ((j = read(0, buf, 10000)) > 0)
	{
		buf[j] = '\0';
		if ((*rest = ft_strjoin(rest, &buf)) == NULL)
			return (-1);
		if ((s = ft_strchr(*rest, '\n')))
		{
			to_free(&buf);
			*s = '\0';
			*line = *rest;
			if ((*rest = ft_strdup(s + 1)) == NULL)
				return (-1);
			return (1);
		}
	}
	to_free(&buf);
	return (j);
}
int		get_next_line(char **line)
{
	static char	*rest;
	int			j;
	int			k;

	if (!line)
		return (-1);
	if ((k = verif_reste(&rest, line)) == 0)
		return (-1);
	else if (k == 1)
		return (1);
	j = ft_read(&rest, line);
	if (j == -1)
		return (to_free(&rest));
	if (rest && j == 0)
	{
		if ((*line = ft_strdup(rest)) == NULL)
			return (-1);
		to_free(&rest);
		return (0);
	}
	return (j);
}
