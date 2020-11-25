// A signature Nick Alvarez program, produced for Project 3, due September 27, 2018
/* This program will calculate the sum of a series up to a given number.*/

#include <stdio.h>
#include <math.h>

int i, n, s, t;
t = 0;
float m;

int main(void)
{
	printf("Enter an integer number: ");
	scanf("%d", &i);

	//Calculates series
	for (n = 1; n <= i; n++)
	{
		m = pow((-1),(n+1));
		s = m*(n*n);
		t = s + t;
	}

	printf("The value of the series is: %d\n", t);

	return 0;
}
