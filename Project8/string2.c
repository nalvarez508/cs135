#include <stdio.h>

int strlength(char *c);
char* strcopy(char *c2, char *c1);
char* strconcat(char *c2, char *c1);
int strcomp(char *c1, char *c2);

int main()
{
  char str1[] = "\0";
  char str2[] = "\0";
  char *c1, *c2;
  c1 = str1;
  c2 = str2;
  //Get user input
  printf("Please enter the first string: ");
  scanf("%s", str1);
  printf("Please enter the second string: ");
  scanf("%s", str2);

  //Length of strings
  int size1=0;
  int i=0;
/*  for (c1=&str1[0]; *c1!=NULL; c1++)
  {
    printf("%c\n", *c1);
    size1++;
    printf("%d\n", size1);
  }*/
  printf("The length of string 1 is: %d\n", strlength(&str1));
  printf("The length of string 2 is: %d\n", strlength(&str2));

  //Checks alphabetical order
  if (strcomp(&str1, &str2)==1)
    printf("String 1 comes before string 2 alphabetically.\n");
  else if (strcomp(&str1, &str2)==(-1))
    printf("String 2 comes before string 1 alphabetically.\n");
  else
    printf("The two strings are the same.\n");

  //Concatenates strings
  printf("String 1 after concatenation: %s\n", str1);
  printf("String 2 after concatenation: %s\n", strconcat(&str2, &str1));

  //Copies strings
  printf("String 1 after copying: %s\n", str1);
  printf("String 2 after copying: %s\n", strcopy(&str2, &str1));

  return 0;
}

//WORKS
int strlength(char *c)
{
  //*c=str1 or str2
  int size = 0;
  for (c=&c[0]; *c!=NULL; c++)
    size++;
  return size;
}

//WORKS, but incorrect function
char* strcopy(char *c2, char *c1)
{
  c1=&c1[0];
  c2=&c2[0];
  *c2=*c1;
/*  int i=0;
  for (c2=&c2[0]; i<1; i++)
  {
    *c2=*c1;
//    printf("%s\n", c2);
//    c1++;
    i++;
  }*/
  c2=&c2[0];
  return c2;
}

char* strconcat(char *c2, char *c1)
{
  c1=&c1[0];
  int c2size = strlength(&c2);
  for (c2=&c2[5]; *c1!='\0'; c2++)
  {
    *c2=*c1;
    c1++;
  }
  c2=&c2[0];
  return c2;
}

//WORKS, but case sensitive
int strcomp(char *c1, char *c2)
{
//  if (*c1==*c2)
//    return 0;
  c2=&c2[0];
//  *c1=&c1[0];
  int i=0;
  int length=0;
  if (strlength(&c1)>strlength(&c2))
    length=strlength(&c1);
  else if (strlength(&c2)>strlength(&c1))
    length=strlength(&c2);
  else
    length=strlength(&c1);
  _Bool breaker=0;
  for (c1=&c1[0]; i<length; c1++)
  {
    printf("Iteration %d\n", i);
    if (*c1!=*c2)
    {
      printf("They are not equal.\n");
      if (*c1>*c2)
      {
        printf("String 2 is less.\n");
        breaker = 1;
        return -1;
      }
      else if (*c1<*c2)
      {
        printf("String 1 is less.\n");
        breaker = 1;
        return 1;
      }
    }
    c2++;
    i++;
  }
  if (breaker==0)
    return 0;
}

