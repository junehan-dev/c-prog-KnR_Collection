#include <unistd.h>

static char	*_G_numbers[1024];
static char	_G_operators[1024];

size_t add_operator(const char *operator)
{
	static size_t	cur = 0;

	_G_operators[cur++] = *operator;
	_G_operators[cur] = 0;
	return (cur);
}

size_t add_number(const char *number)
{
	static size_t	cur = 0;

	_G_numbers[cur++] = (char *)number;
	_G_numbers[cur] = (char *)0;
	return (cur);
}

char	*get_number(size_t index)
{
	return (_G_numbers[index]);
}

char	get_operator(size_t index)
{
	return (_G_operators[index]);
}

