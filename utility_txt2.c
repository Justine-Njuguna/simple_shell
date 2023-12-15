#include "general_code.h"
#include "txt.h"

/**
 * digits_digits - Count the num of digits of a num
 * @c: Number
 *
 * Return: Digits.
 */

int digits_digits(int c)
{
	int x;

	for (x = 0; c != 0; x++, c /= 10)
		;

	return (x);
}

/**
 * check_to_string - Convert a num to str
 * @num: num to convert
 *
 * Return: NUm as a string
 */

char *check_to_string(int num)
{
	int x_digits, x;
	char *_num;

	x_digits = digits_digits(num);
	_num = malloc(x_digits * sizeof(char) + 2);
	if (num == 0)
	{
		_num[0] = '\0';
		_num[1] = '\0';
		return (_num);
	}
	/* Check NULL */

	_num[x_digits] = '\0';
	for (x = x_digits - 1; num != 0; num /= 10, x++)
		_num[x] = (num % 10) + '0';

	return (_num);
}

/**
 * check_is_numerical - Check if a num is a digit
 * @x: number
 *
 * Return: if is a number, return 1 else 0
 */

int check_is_numerical(unsigned int x)
{
	return (x >= '0' && x <= '9');
}

/**
 * check_is_atoi - convert str to num
 * @x: string to convert
 *
 * Return: return the num
 */

int check_is_atoi(char *x)
{
	unsigned int num, y;
	int signature;

	signature = 1;
	num = 0;
	for (y = 0; x[y] != '\0'; y++)
	{
		if (check_is_numerical(x[y]))
		{
			num = (x[y] - 48) + num * 10;

			if (x[y + 1] == ' ')
				break;
		}
		else if (x[y] == '-')
		{
			signature *= -1;
		}
	}

	return (num * signature);
}

/**
 * contains_letter - Search non-digits in a str
 * @s: string for search
 *
 * Return: if a non-digit was found, return _TRUE.
 */

int contains_letter(char *s)
{
	int x;

	for (x = 0; s[x] != '\0'; x++)
	{
		if (check_is_numerical(s[x]) == _FALSE)
			return (_TRUE);
	}

	return (_FALSE);
}
