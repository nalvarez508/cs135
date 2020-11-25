// A signature Nick Alvarez program, produced for Project 10, due December 11, 2018
/* This program will take in inventory from a user with part number, quantity,
and price, saving the list to a text file. Also checks for duplicate part
numbers. */

#include <stdio.h>

int main()
{
  FILE *fp;
  int partNumber, quantity, i=0, x=0;
  int PNs[1000] = {0};
  float price;
  _Bool breaker=0;

  fp = fopen("inventory.txt", "wb");

  printf("This program stores a business inventory.\n");
  do
  {
    do
    {
      breaker = 0;
      printf("Please enter the item data (part number, quantity, price): ");
      scanf("%d, %d, %f", &partNumber, &quantity, &price);
      for (x=0; x<(sizeof(PNs)/sizeof(int)); x++)
      {
        if (partNumber != 0 && (partNumber == PNs[x] && breaker == 0))
        {
          breaker = 1;
          printf("This item has been entered before.\n");
        }
      }
    } while(breaker!=0);
      PNs[i] = partNumber;
    fwrite(&partNumber, sizeof(int), 1, fp);
    fwrite(&quantity, sizeof(int), 1, fp);
    fwrite(&price, sizeof(float), 1, fp);
    i++;
  } while(partNumber!=0);
  printf("Thank you. Inventory stored in file inventory.txt\n");

  fclose(fp);
  return 0;
}
