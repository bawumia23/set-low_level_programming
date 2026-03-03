#include <stdio.h>
#include "main.h"

/**
 * print_remaining_days - prints how many days are left in the year
 * @month: month in number format
 * @day: day of month (already converted to day of year)
 * @year: year
 *
 * Return: void
 */
void print_remaining_days(int month, int day, int year)
{
	int leap = 0;

	if ((year % 4 == 0 && year % 100 != 0) ||
	    (year % 400 == 0))
		leap = 1;

	if (leap)
	{
		if (month > 2)
			day += 1;

		printf("Day of the year: %d\n", day);
		printf("Remaining days: %d\n", 366 - day);
	}
	else
	{
		if (month == 2 && day == 60)
		{
			printf("Invalid date: %02d/%02d/%04d\n",
			       month, day - 31, year);
		}
		else
		{
			printf("Day of the year: %d\n", day);
			printf("Remaining days: %d\n", 365 - day);
		}
	}
}
