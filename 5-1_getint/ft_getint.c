#include <ctype.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>

int	restore_c(int c, FILE *fd)
{
	return (ungetc(c, fd));
}

int	ft_getint(int *pn, FILE *fd)
{
	int		c, sign;

	while (isspace((c = getc(fd))));
	if (c != EOF) {
		if (!isdigit(c) && c != '+' && c != '-') {
			assert((restore_c(c, fd)) == c);
			return (0);
		}

		sign = (c == '-') ? -1 : 1;
		c = (c == '-' || c == '+') ? getc(fd) : c;

		if (!isdigit(c)) {
			assert((restore_c(c, fd)) == c);
			return (0);
		}

		*pn = c - '0';
		while (isdigit((c = getc(fd))))
			*pn = 10 * *pn + (c - '0');

		*pn *= sign;
		restore_c(c, fd);
		return (1);
	}

	return (0);
}

int	main(void)
{
	int		arr[10];
	int		i;
	int		ret;
	FILE	*fd;

	i = 0;
	ret = 1;
	fd = fdopen(0, "r");
	while (i < 10 && ret) {
		ret = ft_getint(arr + i, fd);
		ret ? printf("i: %d\t: %d", i, arr[i]) : printf("ENDED!\n");
		i++;
	}

	fclose(fd);
	return (0);
}

