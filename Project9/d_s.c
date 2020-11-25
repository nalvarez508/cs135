//Creates strings and fills them with user text
int strCount=atoi(argv[1]), userInput=0, srcString=0, dstString=0, sizeofString=0;
//  char strVar[strCount][3];
char *strings;
//  strings=malloc(strCount);
for (int i=1; i<=strCount; i++)
{
  printf("Enter the length of string %d: ", i);
  scanf("%d", &sizeofString);
  strings = malloc(sizeofString);
  printf("Please enter string %d: ", i);
  scanf("%s", &strings[i-1]);
//  printf("%s\n%s\n", &strings[i-1], &strings[i]);
