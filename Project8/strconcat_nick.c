//Working function without pointers
int z=0;
int d=5; //normally the length of string, in this case 5
while (str1[z]!='\0')
{
  printf("%s, %s\n", str1,str2);
  str2[d]=str1[z];
  printf("%s, %s\t\t%d\n", str1,str2, z++);
//  c1++;
  d++;
}
//Function with pointers
char* strconcat(char *c2, char *c1)
{
  /*c1=&c1[strlength(c1)];
  int i=1;
  int c2size = strlength(c2);
  for (c2=&c2[0]; *c2!='\0'; c2++)
  {
    printf("%s, %s\n", c1,c2);
    *(c1++)=*c2;
    printf("%s\t%s\t\t%d\n", c1,c2, i++);
    //c1++;
  }*/
//  int len = strlength(c1) + strlength(c2);
  c1=&c1[0];
  c2=&c2[6]; //normally the length of the string, in this case 6
  int i=1;
  while (*c1!='\0')
  {
    printf("%s, %s\n", c1,c2);
    *c2=*c1;
    printf("%s, %s\t\t%d\n", c1,c2, i++);
    c1++;
    c2++;
  }
//  c2=&c2[len];
//  *c2='\0';
//  *(c2++)=*c1;
//  c2=&c2[c2size+1];
//  c2=c1;
  c2=&c2[0];
  return c2;
}
