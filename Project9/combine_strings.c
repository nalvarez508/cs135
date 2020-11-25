// A signature Nick Alvarez program, produced for Project 9, due December 4, 2018
/* This program will take in two strings and either intersperse them or
concatenate them with asterisks in between. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int strlength(char* c); //Calculates the length of the strings
int strcomp(char *c1, char *c2); //Determines alphabetical order of strings
char* intersperse(char str1[], char str2[]); //Places one character at a time from each string into new string
char* widen_stars(char str1[], char str2[]); //Adds asterisks between two strings combined

int main(int argc, char* argv[])
{
  char str1[31];
  char str2[31];

  //Get user input
  printf("Please enter a string of maximum 30 characters: ");
  scanf("%30s", str1);
  printf("Please enter a string of maximum 30 characters: ");
  scanf("%30s", str2);

  //Determines what to execute based on arguments
  if (strcomp(argv[1], "-i") == 0)
    printf("The combined string is: %s\n", intersperse(str1, str2));
  if (strcomp(argv[1], "-w") == 0)
    printf("The combined string is: %s\n", widen_stars(str1, str2));

  return 0;
}

int strlength(char *c)
{
  int size = 0;
  for (c; *c!='\0'; c++)
    size++;
  return size;
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

char* intersperse(char str1[], char str2[])
{
  char *str3;
  int str1length = strlength(str1);
  int str2length = strlength(str2);
  str3 = malloc(str1length+str2length+1);

  char *str3i;
  str3i = &str3[0];
  int a=0, b=0;
  for (int i=0; i<(str1length+str2length); i++)
  {
    if (str1[a]!=NULL)
    {
      *str3 = str1[a++];
      str3++;
    }
    if (str2[b]!=NULL)
    {
      *str3 = str2[b++];
      str3++;
    }
  }
  return str3i;
  free(str3);
}

char* widen_stars(char str1[], char str2[])
{
  char *str3;
  int str1length = strlength(str1);
  int str2length = strlength(str2);
  str3 = malloc((str1length+str2length)*2);

  char *str3i, *str2p;
  str2p = &str2[0];
  str3i = &str3[0];
  int a=0, b=0;
  do
  {
    for (a=0; a<str1length; a++)
    {
      *str3 = str1[a];
      *(++str3) = '*';
      str3++;
    }
    for (b=0; b<str2length; b++)
    {
      *str3 = str2[b];
      if (b!=str2length-1)
        *(++str3) = '*';
      str3++;
    }
  } while (str2[str2length]!=NULL);

  return str3i;
  free(str3);
}
