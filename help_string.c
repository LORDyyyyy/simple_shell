#include "shell.h"


/**
 * _strcpy - copies a string
 * @dest: dest
 * @src: source
 *
 * Return: Always 0.
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];

	dest[i++] = '\0';
	return (dest);
}

/**
 * _strncpy -  copies a string.
 * @dest: first string
 * @src: second string
 * @n: numbr of characters to be copied
 * Return: Always 0.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, slen = 0;

	while (src[slen])
		slen++;

	for (i = 0; src[i] && i < n; i++)
		dest[i] = src[i];

	for (i = slen; i < n; i++)
		dest[i] = '\0';

	return (dest);
}

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

	while (dest[dest_len])
		dest_len++;

	for (i = 0; src[i]; i++, dest_len++)
		dest[dest_len] = src[i];

	dest[dest_len++] = '\0';

	return (dest);
}

/**
 * _strcmp -  compares two strings
 * @s1: first string
 * @s2: second string
 * Return: Always 0.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] || s2[i]; i++)
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	return (0);
}

/**
 * _strdup - copies a string
 * @str: the string
 *
 * Return: a new copy of str
 */
char *_strdup(char *str)
{
	int i, size = 0;
	char *arr;

	if (!str)
		return (NULL);
	
	while (str[size])
		size++;
	
	arr = malloc(size * sizeof(*str) + 1);

	if (!arr)
		return (NULL);
	
	for (i = 0; str[i]; i++)
		arr[i] = str[i];
	
	return (arr);
}
