// A signature Nick Alvarez program, produced for Project 10, due December 11, 2018
/* This program will take in inventory from a user with part number, quantity,
and price, saving the list to a text file. */

#include <stdio.h>

int main()
{
  FILE *fp;
  int partNumber, quantity, i=0;
  float price;

  fp = fopen("inventory.txt", "wb");

  printf("This program stores a business inventory.\n");
  do
  {
    printf("Please enter the item data (part number, quantity, price): ");
    scanf("%d, %d, %f", &partNumber, &quantity, &price);
    if (partNumber)
    {
      fwrite(&partNumber, sizeof(int), 1, fp);
      fwrite(&quantity, sizeof(int), 1, fp);
      fwrite(&price, sizeof(float), 1, fp);
      i++;
    }
  } while(partNumber!=0);
  printf("Thank you. Inventory stored in file inventory.txt\n");

  fclose(fp);
  return 0;
}
