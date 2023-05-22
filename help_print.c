#include "shell.h"

/**
 * writechar - just like write, print a single character
 * @c: the character to be printed
 *
 * Return: 1
 */
int writechar(int c)
{
	if (c != -1)
		return (write(STDOUT_FILENO, &c, 1));
	return (0);
}

/**
 * writestr - prints a string
 * @str: the string
 *
 * Return: its len
 */
int writestr(char *str)
{
	int len = 0;

	while (str[len])
	{
		writechar(str[len]);
		len++;
	}

	return (len);
}

/**
 * _strlen - return the string length
 * @s: string
 *
 * Return: s length
 */
size_t _strlen(char *s)
{
	size_t len = 0;

	while (s[len])
		len++;
	return (len);
}


/**
 * print_number - prints an integer
 * @n: prints an integer
 * Return: Always 0.
 */
void print_number(int n)
{
	int i, dig;

	if (n < 0)
	{
		n *= -1;
		writechar('-');
	}
	if (n == 0)
		writechar(48);
	for (i = 1; i <= n; i *= 10)
		dig = 0;
	
	i /= 10;
	
	for (; i > 0; i /= 10)
	{
		dig = (n / i) % 10;
		writechar(dig + 48);
	}
}
