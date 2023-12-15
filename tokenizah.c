#include "txt.h"

/**
 * word_split - Splits a line into words
 * @line: Line to split
 * @delim: Delim for the words
 *
 * Return: Set of words.
 */

char **word_split(char *line, const char *delim)
{
	char **wordings, **temp, *token;
	size_t size_new, size_old;

	size_old = sizeof(char *);
	wordings = malloc(size_old);
	if (wordings != NULL)
	{
		size_new = 1;
		token = strtok(line, delim);
		while (token)
		{
			if (token[0] == '#')
				break;
			temp = reallocate(wordings, size_old, (size_new + 1) * sizeof(char *));
			size_old = (size_new + 1) * sizeof(char *);
			if (temp == NULL)
				break;

			wordings = temp;
			++size_new;

			wordings[size_new - 2] = malloc(_strlen(token) + 1);
			if (wordings == NULL)
			{
				free(temp);
				free(wordings);
			}

			if (wordings[size_new - 2] != NULL)
				_strcpy(wordings[size_new - 2], token);

			token = strtok(NULL, delim);

			temp = NULL;
		}

		wordings[size_new - 1] = NULL;
	}

	return (wordings);
}

/**
 * join_words - Join 3 words with a delim
 * @word1: 1st word
 * @word2: 2nd word
 * @word3: 3rd word
 * @delim: delimeter
 *
 * Return: a line of 3 parts followed by a delim
 */

char *join_words(char *word1, char *word2, char *word3, const char *delim)
{
	char *auxiliary;
	int str1_size, str2_size, str3_size, size_delim;

	str1_size = str2_size = size_delim = 0;

	if (word1 != NULL)
		str1_size = _strlen(word1);
	else
		word1 = "";

	if (word2 != NULL)
		str2_size = _strlen(word2);
	else
		word2 = "";

	if (word3 != NULL)
		str3_size = _strlen(word3);
	else
		word3 = "";

	if (delim != NULL)
		size_delim = _strlen((char *) delim);
	else
		delim = "";

	auxiliary = malloc(str1_size + str2_size + size_delim +
			str3_size + size_delim + 2);
	if (auxiliary == NULL)
		return (NULL);

	auxiliary = _strcpy(auxiliary, word1);
	auxiliary = _strcat(auxiliary, (char *) delim);
	auxiliary = _strcat(auxiliary, word2);
	auxiliary = _strcat(auxiliary, (char *) delim);
	auxiliary = _strcat(auxiliary, word3);
	auxiliary = _strcat(auxiliary, "\n");

	return (auxiliary);
}
