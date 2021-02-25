#include "slide_line.h"

/**
 * slide_line - slide int array following 2048 rules
 *@line: array of numbers to slide
 *@size: length of line
 *@direction: direction to slide
 *
 * Return: 1 on success
 */

int slide_line(int *line, size_t size, int direction)
{
	if (direction == SLIDE_LEFT)
	{
		push_Left(line, (int)size);

		compress_Left(line, (int)size);

		push_Left(line, (int)size);
	}
	else
	{
		push_Right(line, (int)size);
		compress_Right(line, (int)size);
		push_Right(line, (int)size);
	}

	return (1);
}

/**
 * push_Left - slide line left
 *@line: array of numbers to slide
 *@size: length of line
 */

void push_Left(int *line, int size)
{
	int prev;
	int i;

	for (i = 1; i < size; i++)
	{
		if (line[i] != 0)
		{
			for (prev = i - 1; prev >= 0 && line[prev] == 0; prev--)
				;
			if (line[++prev])
				continue;
			line[prev] = line[i];
			line[i] = 0;
			i = prev + 1;
		}
	}
}

/**
 * compress_Left - combine adjacent items start at first element
 *@line: array of numbers to slide
 *@size: length of line
 */

void compress_Left(int *line, int size)
{
	int num1, num2;
	int i = 0;

	while (i < size)
	{
		num1 = line[i++];
		if (i < size)
			num2 = line[i];
		else
			num2 = 0;

		if (num1 == num2)
		{
			line[i - 1] = num1 * 2;
			line[i++] = 0;
		}
	}
}

/**
 * push_Right - slide line right
 *@line: array of numbers to slide
 *@size: length of line
 */

void push_Right(int *line, int size)
{
	int prev;
	int i;

	for (i = (size - 1); i >= 0; i--)
	{
		if (line[i] != 0)
		{
			for (prev = i + 1; prev <= (size - 1) && line[prev] == 0; prev++)
				;
			if (line[--prev])
				continue;
			line[prev] = line[i];
			line[i] = 0;
			i = prev - 1;
		}
	}
}

/**
 * compress_Right - combine adjacent items start at last element
 *@line: array of numbers to slide
 *@size: length of line
 */

void compress_Right(int *line, int size)
{
	int num1, num2;
	int i = size - 1;

	while (i >= 0)
	{
		num1 = line[i--];
		if (i >= 0)
			num2 = line[i];
		else
			num2 = 0;

		if (num1 == num2)
		{
			line[i + 1] = num1 * 2;
			line[i--] = 0;
		}
	}
}
