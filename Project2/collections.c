// A signature Nick Alvarez program, produced for Project 2, due September 20, 2018
/* This program will query the user for collections of books, including the number of
volumes and the price per volume, and then asks for a budget to spend. Various
different statements will then appear that range from matching volume prices to
the amount of books Bob can buy.*/

#include <stdio.h>

//Defines variables
int collection1_volumes, collection1_price, collection2_volumes, collection2_price, collection3_volumes, collection3_price, budget;

int main(void)
{
  //User values for number of volumes, price per, and budget
  printf("Enter volumes and price per volume for collection 1: ");
  scanf("%d %d", &collection1_volumes, &collection1_price);
  printf("Enter volumes and price per volume for collection 2: ");
  scanf("%d %d", &collection2_volumes, &collection2_price);
  printf("Enter volumes and price per volume for collection 3: ");
  scanf("%d %d", &collection3_volumes, &collection3_price);
  printf("Enter Bob's budget: ");
  scanf("%d", &budget);

  //Calculates total cost of each volumes
  int c1 = collection1_volumes * collection1_price;
  int c2 = collection2_volumes * collection2_price;
  int c3 = collection3_volumes * collection3_price;

  //Bob has money. (1)
  if (budget > 0)
  {
    printf("Bob has some money to buy collections.\n");
  }
  else
  {
    printf("Bob does not have money to buy anything.\n");
  }

  //At least two collections are more expensive than Bob's budget. (2)
  if (((c1 && c2) > budget) || ((c2 && c3) > budget) || ((c1 && c3) > budget))
  {
    printf("At least two collections are more expensive than Bob’s budget.\n");
  }
  else
  {
    printf("At least two collections are cheaper than or equal to Bob’s budget.\n");
  }

  //All the collections cost the same, only two collections cost the same, or no collections cost the same. (3)
  if ((c1 == c2) && (c2 == c3))
  {
    printf("All the collections cost the same.\n");
  }
  else if ((c1 == c2) || (c2 == c3) || (c1 == c3))
  {
    printf("Only two collections cost the same amount of money.\n");
  }
  else
  {
    printf("No collections have the same price.\n");
  }

  //Only one collection is cheaper than or equal to Bob's Budget. (4)
  if ((c3 <= budget) && (c1 > budget) && (c2 > budget))
  {
    printf("Only one collection is cheaper than or equal to Bob's budget.\n");
  }
  else if ((c2 <= budget) && (c1 > budget) && (c3 > budget))
  {
    printf("Only one collection is cheaper than or equal to Bob's budget.\n");
  }
  else if ((c1 <= budget) && (c2 > budget) && (c3 > budget))
  {
    printf("Only one collection is cheaper than or equal to Bob's budget.\n");
  }
  else
  {
    printf("More than one collection is cheaper than or equal to Bob’s budget or they are all more expensive.\n");
  }

  //The maximum number of collections that Bob can buy. (5)
  if (budget >= (c1 + c2 + c3))
  {
    printf("Bob can buy all three collections.\n");
  }
  else if (budget >= (c1 + c2) || budget >= (c2 + c3) || budget >= (c1 + c3))
  {
    printf("Bob can only buy two of the collections.\n");
  }
  else if (budget >= c1 || budget >= c2 || budget >= c3)
  {
    printf("Bob can only buy one collection.\n");
  }
  else
  {
    printf("Bob cannot buy any collection.\n");
  }
  return 0;
}
