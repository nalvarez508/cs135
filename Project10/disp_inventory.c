// A signature Nick Alvarez program, produced for Project 10, due December 11, 2018
/* This program will read the text file created and output a list. */

#include <stdio.h>

int main()
{
  FILE *fp;
  fp = fopen("inventory.txt", "rb");
  int partNumber, pN, quantity, q, i=0;
  float price, p;

  printf("Below are the items in your inventory.\n");
  printf("Part#\tQuantity\tItem Price\n");
  while ((feof(fp) == 0))
  {
    pN = fread(&partNumber, sizeof(int), 1, fp);
    if (feof(fp) == 0)
    {
      printf("%-5d", partNumber);
      q = fread(&quantity, sizeof(int), 1, fp);
      printf("\t%-8d", quantity);
      p = fread(&price, sizeof(float), 1, fp);
      printf("\t$\t%-11.2f\n", price);
    }
  }

  fclose(fp);
  return 0;
}
