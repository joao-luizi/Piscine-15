/*
AUTHOR COMMENT:
I Never had an Ok with moulinette. The version on this file never got to be tested. I included a trace file that can help if someone wants to try "fixing" the code. The output of this version is the same as the examples but i never got to resend it to evaluation before my piscine ended.
*/

#include <unistd.h>

char	dectohex(unsigned char c, int flag)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (c > 15)
	{
		if (flag == 0)
			return (dectohex(c / 16, 0));
		else
			return (dectohex(c % 16, 1));
	}
	else
	{
		return (hex[c]);
	}
}

void	print_block(void *addr, char *line, unsigned int maxsize)
{
	int				i;
	unsigned char	*c;
	unsigned int	hex_index;

	i = -1;
	hex_index = 17;
	while (i++ < 16)
	{
		c = addr + i;
		if (i % 2 == 0)
			hex_index++;
		if (i >= maxsize)
			line[59 + i] = '\0';
		else
		{
			if (c[0] > 10)
				line[hex_index + (i * 2)] = dectohex(c[0], 0);
			else
				line[hex_index + (i * 2)] = '0';
			line[hex_index + (i * 2) + 1] = dectohex(c[0], 1);
			if (c[0] < 32 || c[0] >= 127)
				line[59 + i] = '.';
			else
				line[59 + i] = c[0];
		}
	}
	line[58 + i] = '\n';
}

void	print_address(void *addr, char *line)
{
	int				i;
	unsigned char	*ptrbyte;
	int				line_index;

	line_index = 0;
	i = 7;
	ptrbyte = (unsigned char *)&addr;
	while (i >= 0)
	{
		line[line_index] = dectohex(*(ptrbyte + i), 0);
		line[line_index + 1] = dectohex(*(ptrbyte + i), 1);
		line_index += 2;
		i--;
	}
	line[16] = ':';
	i = 17;
	while (i < 75)
	{
		line[i] = ' ';
		i++;
	}
}
void	*ft_print_memory(void *addr, unsigned int size)
{
	void			*saddr;
	char			line[75];
	unsigned int	maxsize;

	saddr = addr;
	maxsize = 16;
	while (size > 0)
	{
		if (size < maxsize)
			maxsize = size;
		print_address(addr, line);
		print_block(addr, line, maxsize);
		write(1, &line, 75);
		size -= maxsize;
		addr += maxsize;
	}
	return (saddr);
}
/*
int	main(void)
{
	// char example[] = "Bonjour les aminches...c. est fou.tout.ce qu on peut faire avec...print_memory....lol.lol. .";
	char example[] = {228};
	// ft_print_memory(example, sizeof(example));
	write(1, "\n", 1);
	char example2[] = {173, 6};
	// ft_print_memory(example2, sizeof(example2));

	char example3[] = {174, 146, 232};
	// ft_print_memory(example3, sizeof(example3));

	char example4[] = {240, 175, 210, 253};
	// ft_print_memory(example4, sizeof(example4));

	char example5[] = {99, 101, 238, 30, 219};
	// ft_print_memory(example5, sizeof(example5));

	char example6[] = {176, 93, 200, 222, 197, 223};
	// ft_print_memory(example6, sizeof(example6));

	char example7[] = {
		192,
		207,
		149,
		186,
		170,
		35,
		33,
	};
	ft_print_memory(example7, sizeof(example7));
	return (0);
}*/