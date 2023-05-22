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
 * full_strcat -  concatenates two strings
 * @string1: first string
 * @string2: second string
 *
 * Return: Always 0.
 */
char *full_strcat(char *string1, char *string2)
{
	char *result;
	int len1 = 0, len2 = 0;

	if (!string1)
		string1 = "";
	len1 = _strlen(string1);

	if (!string2)
		string2 = "";
	len2 = _strlen(string2);

	result = malloc(sizeof(char) * (len1 + len2 + 1));

	for (len1 = 0; string1[len1]; len1++)
		result[len1] = string1[len1];

	free(string1);

	for (len2 = 0; string2[len2] != '\0'; len2++)
	{
		result[len1] = string2[len2];
		len1++;
	}

	result[len1] = '\0';
	return (result);
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
 * full_strdup - copies a string
 * @string: the string
 *
 * Return: a new copy of str
 */
char *full_strdup(char *string)
{
	char *result;
	int length, i;

	if (!string)
		return (NULL);

	length = _strlen(string) + 1;

	result = malloc(sizeof(char) * length);

	for (i = 0; i < length ; i++)
		result[i] = string[i];

	return (result);
}

