#include <stdio.h>
#include <string.h>
#define ALPHABET_LEN 26
int main()
{
    int i = 0,
    count[ALPHABET_LEN] = {0};
    char s[20], c = '\0';
    printf("Please enter a line of text: \n"); gets(s);
    for (i=0; i<strlen(s);i++)
        {
    c = s[i];

    if (c <= 'z' && c >= 'a')    ++count[c - 'a'];
    if (c <= 'Z' && c >= 'A')     ++count[c - 'A'];


         }
      for (i = 0; i < ALPHABET_LEN ; ++i) {
      if (count[i] > 0)
      printf("The letter '%c' appears %d time(s).\n", 'a' + i,count[i]);

      }
      return 0;
}
