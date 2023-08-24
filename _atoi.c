#include "shell.h"
/**
 *this has to be interactive and it must return true if shell is in interactive mode
 *@info: this is well strcutured address
 *Return: 1 if true, 0 if false.
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 *The is_delim will check if the character is a delimiter
 *@c shows us the character to check for
 *@delim will give us the delimiter info, This will return 1 if it comes true and 0 if it is fals
 */

int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *The _isalpha will check for alphabetic yeye
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 *_atoi will convert the string to an integer
 *The string to be converted is @s
 *Returns 0 if no number in string is converted
 */
int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
