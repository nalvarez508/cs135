// A signature Nick Alvarez program, produced for Project 9, due December 4, 2018
/* This program will take in some number of strings, and present the user with options to
determine their length, compare them, copy them, and concatenate them. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int strlength(char* c); //Calculates the length of a string
char* strcopy(char *c2, char *c1); //Copies string x into string y
char* strconcat(char *c2, char *c1); //Copies string x into the end of string y
int strcomp(char *c1, char *c2); //Determines alphabetical order of two strings
void printMenu(); //Prints the menu
void printStrings(char *s[], int c); //Prints modified strings

int main(int argc, char* argv[])
{
  //Creates strings and fills them with user text
  int strCount=atoi(argv[1]), userInput=0, srcString=0, dstString=0, sizeofString=0;
  char *strings[strCount];
  for (int i=0; i<strCount; i++)
  {
    printf("Enter the length of string %d: ", (i+1));
    scanf("%d", &sizeofString);
    strings[i] = malloc(sizeofString+1);
    printf("Please enter string %d: ", (i+1));
    scanf("%s", strings[i]);
  }

  //The menu
  do
  {
    printStrings(strings, strCount);
    printMenu();
    scanf("%d", &userInput);

    switch (userInput)
    {
      case 1:
      {
        printf("Enter a string number: ");
        scanf("%d", &srcString);
        printf("The length of string %d is: %d\n", srcString, strlength(strings[srcString-1]));
        break;
      }
      case 2:
      {
        printf("Enter the number of the first string: ");
        scanf("%d", &srcString);
        printf("Enter the number of the second string: ");
        scanf("%d", &dstString);
        switch (strcomp(strings[srcString-1], strings[dstString-1]))
        {
          case -1:
          {
            printf("String %d comes before string %d alphabetically.\n", dstString, srcString);
            break;
          }
          case 1:
          {
            printf("String %d comes before string %d alphabetically.\n", srcString, dstString);
            break;
          }
          case 0:
          {
            printf("The two strings are the same.\n");
            break;
          }
        }
        break;
      }
      case 3:
      {
        printf("Enter the number of the source string: ");
        scanf("%d", &srcString);
        printf("Enter the number of the destination string: ");
        scanf("%d", &dstString);
        strcopy(strings[dstString-1], strings[srcString-1]);
        break;
      }
      case 4:
      {
        printf("Enter the number of the source string: ");
        scanf("%d", &srcString);
        printf("Enter the number of the destination string: ");
        scanf("%d", &dstString);
        strconcat(strings[dstString-1], strings[srcString-1]);
        break;
      }
      case 5: break;
      default:
      {
        printf("Invalid option.\n");
        break;
      }
    }
  } while(userInput != 5);

  //Frees allocated memory
  for (int i=0; i<strCount; i++)
    free(strings[i]);
  return 0;
}

int strlength(char *c)
{
  int size = 0;
  for (c; *c!='\0'; c++)
    size++;
  return size;
}

char* strcopy(char *c2, char *c1)
{
  c2=realloc(c2, strlength(c1)+1);
  while (*c1!='\0')
  {
    *c2=*c1;
    c2++;
    c1++;
  }
  return c2;
}

char* strconcat(char *c2, char *c1)
{
  char *c3, *c4;
  c3=c1;
  c4=c2;
  c4=realloc(c2, strlength(c1)+strlength(c2)+1);
  c3=&c3[0];
  c4=&c4[strlength(c2)];
  while (*c3!='\0')
  {
    *c4=*c3;
    c3++;
    c4++;
  }
  return c2;
}

int strcomp(char *c1, char *c2)
{
  int str1length = strlength(c1);
  int str2length = strlength(c2);

  char str3[str1length];
  char str4[str2length];
  int x=0;
  for (x=0; x<str1length; x++)
  {
    str3[x]=toupper(*c1);
    c1++;
  }
  for (x=0; x<str2length; x++)
  {
    str4[x] = toupper(*c2);
    c2++;
  }

  c2=&c2[0];
  int i=0;
  int length=0;
  if (str1length>str2length)
    length=str1length;
  else if (str2length>str1length)
    length=str2length;
  else
    length=str1length;
  _Bool breaker=0;
  for (i=0; i<length; i++)
  {
    if (str3[i]!=str4[i])
    {
      if (str3[i]>str4[i])
      {
        breaker = 1;
        return -1;
      }
      else if (str3[i]<str4[i])
      {
        breaker = 1;
        return 1;
      }
    }
  }
  if (breaker==0)
    return 0;
}

void printMenu()
{
  printf("Options:\n1 - Find string length\n2 - Compare strings\n3 - Copy strings\n4 - Concatenate strings\n5 - Quit\nPlease enter your option: ");
}

void printStrings(char *s[], int c)
{
  for (int i=0; i<c; i++)
    printf("String number %d - \"%s\"\n", (i+1), s[i]);
}
