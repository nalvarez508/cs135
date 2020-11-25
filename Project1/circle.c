// A signature Nick Alvarez program, produced for Project 1, due September 13, 2018
/* This program will prompt the user for a radius of a circle and will then
calculate various measurements about the square and the circle, and finally the
difference between the area of the square and the circle. */

#include<stdio.h>
#define pi 3.14f

// Initializes variables
int radius, diameter, perimeter, areaSquare;
float circumference, areaCircle, areaDifference;

int main(void)
{
  printf("This program computes values related to an inscribed circle.\n");
  printf("Enter the value of the radius: ");
  scanf("%d", &radius);
// Calculates required values
  diameter = radius * 2;
  circumference = 2 * pi * radius;
  areaCircle = pi * (radius * radius);
  perimeter = diameter * 4;
  areaSquare = diameter * diameter;
  areaDifference = areaSquare - areaCircle;
  printf("The diameter of the circle is: %d\n", diameter);
  printf("The circumference of the circle is: %.3f\n", circumference);
  printf("The area of the circle is: %.3f\n", areaCircle);
  printf("The perimeter of the square is: %d\n", perimeter);
  printf("The area of the square is: %d\n", areaSquare);
  printf("The difference between the area of the square and the circle is: %.3f\n", areaDifference);
  return 0;
}
