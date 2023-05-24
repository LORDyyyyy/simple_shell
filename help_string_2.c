#include "shell.h"

/**
 * _strcat -  concatenates two strings
 * @dest: first string
 * @src: second string
 *
 * Return: Always 0.
 */
char *_strcat(char *dest, char *src)
{
	int i, dest_len = 0;

	while (dest[dest_len] != '\0')
		dest_len++;
	for (i = 0; src[i] != '\0'; i++, dest_len++)
		dest[dest_len] = src[i];
	dest[dest_len++] = '\0';
	return (dest);
}
/**
 * _strdup - function that returns a pointer to a newly allocated space
 * in memory, which contains a copy of the string given as a parameter
 *
 * @str: string of chars
 *
 * Return: address of the newly allocated memory
 */

char *_strdup(char *str)
{
	unsigned int len;
	unsigned int i, j;
	char *str_copy;
	char *tmp = str;

	if (str == NULL)
		return (NULL);

	i = 0;
	while (*str++)
		i++;
	len = i;
	str = tmp;

	str_copy = malloc(len * sizeof(char) + 1);
	if (str_copy == NULL)
		return (NULL);

	j = 0;
	while (j < len)
	{
		str_copy[j] = str[j];
		j++;
	}
	str_copy[j] = '\0';
	return (str_copy);
}

/**
 * _strncmp - compares two strings
 * @string1: first string
 * @string2: second string
 * @number: no. of chars to be compared
 *
 * Return: 1 if str1 = str2, 0 otherwise
 */
int _strncmp(char *string1, char *string2, int number)
{
	int iterator;

	if (string1 == NULL || string2 == NULL)
		return (0);

	for (iterator = 0; iterator < number ; iterator++)
	{
		if (string1[iterator] != string2[iterator])
			return (0);
	}
	return (1);
}

/**
 * check_space - check is the string is only strings or not
 * @str: strting to check
 *
 * Return: 1 if spaces only, 0 otherwise
 *
 */
int check_space(char *str)
{
	char *spaces = " \r\n\t";
	int i, j;
	size_t len = 0;

	if (str == NULL)
		return (0);

	for (i = 0; str[i]; i++)
		for (j = 0; spaces[j]; j++)
			if (str[i] == spaces[j])
				len++;

	return (len == _strlen(str) ? 1 : 0);
}

