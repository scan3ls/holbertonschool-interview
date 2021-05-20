#include "holberton.h"
/* #include <stdio.h> */

void printError(void);
void freeNumber(Number_t *);
void add(char *, char *);
int invalidDigits(Number_t *);
Number_t *newNumber(char *);
Number_t *multiply(Number_t *, Number_t *);

/**
 * main - multiply two positive integers of any size and print the result
 *@argc: number of arguments passed to the program
 *@argv: the list of arguments passed to the program
 * Return: 0
 */
int main(int argc, char *argv[])
{
	Number_t *num1, *num2, *result;
	int i;

	if (argc != 3)
	{
		printError();
	}

	num1 = newNumber(argv[1]);
	num2 = newNumber(argv[2]);

	if (invalidDigits(num1) || invalidDigits(num2))
	{
		printError();
	}

	result = multiply(num1, num2);

	for (i = 0; i < result->length; i++)
	{
		_putchar(result->value[i]);
	}
	_putchar('\n');

	freeNumber(num1);
	freeNumber(num2);
	freeNumber(result);
	return (0);
}

/**
 * printError - prints an Error message to the console.
 */
void printError(void)
{
	char msg[] = "Error\n";
	int i;

	for (i = 0; msg[i] != '\0'; i++)
	{
		_putchar(msg[i]);
	}
	exit(98);
}

/**
 * newNumber - creates a new item in memory of type Number_t
 *@arg: character array that holds a string of a positive integer
 *
 * Return: Number_t number created
 */
Number_t *newNumber(char *arg)
{
	Number_t *num;
	int i;

	if (arg == NULL)
		return (NULL);

	num = malloc(sizeof(Number_t));

	/* SET VALUE */
	num->value = arg;

	/* FIND & SET LENGTH */
	for (num->length = 0; arg[num->length] != '\0'; num->length++)
		;

	/* FIND & SET REVERSED */
	num->reversed = malloc(sizeof(char) * (num->length + 1));

	for (i = 1; i <= num->length; i++)
	{
		num->reversed[i - 1] = arg[num->length - i];
	}
	num->reversed[i] = '\0';

	return (num);
}

/**
 * multiply - multiplies two Number_t numbers together
 *@num1: a Number_t number
 *@num2: a Number_t number
 *
 * Return: The product of num1 and num2
 */
Number_t *multiply(Number_t *num1, Number_t *num2)
{
	Number_t top, bottom;
	Number_t *product;
	char *subProduct1, *subProduct2, *temp;
	int bottomIndex, topIndex, sub2Index = 0;
	int currentBottomValue, currentTopValue;
	int singleProduct, ones, tens, placeHolder = 1;

	if (num1->length >= num2->length)
	{
		top.value = num1->reversed;
		top.length = num1->length;
		bottom.value = num2->reversed;
		bottom.length = num2->length;
	}
	else
	{
		top.value = num2->reversed;
		top.length = num2->length;
		bottom.value = num1->reversed;
		bottom.length = num1->length;
	}

	subProduct1 = malloc(sizeof(char) * MAX_NUM_LENGTH);
	subProduct2 = malloc(sizeof(char) * MAX_NUM_LENGTH);
	subProduct1[0] = '0' + 0;

	for (bottomIndex = 0; bottomIndex < bottom.length; bottomIndex++)
	{
		currentBottomValue = bottom.value[bottomIndex] - '0';
		tens = 0;
		/* printf("\n"); */
		for (topIndex = 0; topIndex < top.length; topIndex++)
		{
			currentTopValue = top.value[topIndex] - '0';
			singleProduct = (currentBottomValue * currentTopValue) + tens;
/*
 *			printf(
 *				"%d * %d + %d = %d\n",
 *				currentBottomValue,
 *				currentTopValue,
 *				tens,
 *				singleProduct
 *			);
 */			tens = singleProduct / 10;
			ones = singleProduct % 10;
			subProduct2[sub2Index++] = '0' + ones;
		}

		if (tens > 0)
		{
			subProduct2[sub2Index] = '0' + tens;
		}
		/* printf("%s + %s = ", subProduct1, subProduct2); */
		add(subProduct1, subProduct2);
		/* printf("%s\n", subProduct1); */
		while (sub2Index > placeHolder)
		{
			subProduct2[sub2Index--] = 0;
		}
		subProduct2[placeHolder - 1] = '0' + 0;
		placeHolder++;

	}

	product = newNumber(subProduct1);
	temp = product->value;
	product->value = product->reversed;
	product->reversed = temp;

	free(subProduct2);

	return (product);
}

/**
 * freeNumber - free a Number_t number
 *@num: Number_t number to free
 */
void freeNumber(Number_t *num)
{
	if (num == NULL)
		return;

	if (num->reversed != NULL)
		free(num->reversed);

	free(num);
}

/**
 * add - add two numbers and store in the location of the first number
 *@num1: pointer to a char array holding a string of an integer
 *@num2: pointer to a char array holding a string of an integer
 */
void add(char *num1, char *num2)
{
	int num1Index = 0, num2Index = 0;
	int num1ValueAtIndex, num2ValueAtIndex;
	int value, carry = 0;

	while (num1Index != -1 || num2Index != -1)
	{
		num1ValueAtIndex = (num1Index != -1) ? num1[num1Index] - '0' : 0;
		num2ValueAtIndex = (num2Index != -1) ? num2[num2Index] - '0' : 0;
		value = num1ValueAtIndex + num2ValueAtIndex + carry;

		carry = value / 10;
		value = value % 10;

		if (num1Index > num2Index)
			num1[num1Index] = '0' + value;
		else
			num1[num2Index] = '0' + value;

		num1Index++;
		num2Index++;

		if (num1[num1Index] == 0 || num1Index == 0)
			num1Index = -1;
		if (num2[num2Index] == 0 || num1Index == 0)
			num2Index = -1;
	}

	if (carry > 0)
	{
		for (num1Index = 0; num1[num1Index] != '\0'; num1Index++)
			;
		num1[num1Index] = '0' + carry;
	}
}


/**
 * invalidDigits - checks an char array for non int characters
 *@num: Number_t number
 *
 * Return: 1 if has non 0-9 characters else 0
 */
int invalidDigits(Number_t *num)
{
	int index, digit;
	char *digits = num->value;

	for (index = 0; index < num->length; index++)
	{
		digit = digits[index] - '0';
		if (digit < 0)
			return (1);

		if (digit > 9)
			return (1);
	}

	return (0);
}
