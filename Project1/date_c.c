// A signature Nick Alvarez program, produced for Project 1, due September 13, 2018
/* This program will prompt the user for four dates, then output the responses
in a formatted table. */

#include <stdio.h>

// Initializes variables
int date1day, date1month, date1year;
int date2day, date2month, date2year;
int date3day, date3month, date3year;
int date4day, date4month, date4year;

int main(void)
{
  printf("Enter date 1 (dd/mm/yyyy): ");
  scanf("%d/%d/%d", &date1day, &date1month, &date1year);
  printf("Enter date 2 (dd/mm/yyyy): ");
  scanf("%d/%d/%d", &date2day, &date2month, &date2year);
  printf("Enter date 3 (dd/mm/yyyy): ");
  scanf("%d/%d/%d", &date3day, &date3month, &date3year);
  printf("Enter date 4 (dd/mm/yyyy): ");
  scanf("%d/%d/%d", &date4day, &date4month, &date4year);
  printf("Year\tMonth\tDay\n");
  printf("%.4d\t%.2d\t%-.2d\n", date1year, date1month, date1day);
  printf("%.4d\t%.2d\t%-.2d\n", date2year, date2month, date2day);
  printf("%.4d\t%.2d\t%-.2d\n", date3year, date3month, date3day);
  printf("%.4d\t%.2d\t%-.2d\n", date4year, date4month, date4day);
  return 0;
}
