#include<stdio.h>
#include<string.h>

#define MAX 100

void computeLPSarray(const char *pattern, int patternlen, int *lps) 
{
    int j = 0;
    lps[0] = 0; // lps[0] is always 0
    int i = 1;
    while (  i < patternlen) 
    {
        if (pattern[i] == pattern[j]) 
        {
            j++;
            lps[i] = j;
            i++;
        }
        else 
        {
            if (j != 0) 
            {
                j = lps[j - 1];
            }
            else 
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(const char* txt, int textlen, const char* pattern, int patternlen) 
{
    int lps[patternlen];
    computeLPSarray(pattern, patternlen, lps);
    int i = 0, j = 0;
    while (i < textlen) 
    {
        if (pattern[j] == txt[i]) 
        {
            i++;
            j++;
        }
        if (j == patternlen) 
        {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        }
        else if (i < textlen && pattern[j] != txt[i]) 
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

int main() 
{
    char txt[MAX], pattern[MAX];
    printf("Enter the text: ");
    scanf("%s", txt);
    printf("Enter the pattern to search: ");
    scanf("%s", pattern);
    int textlen = strlen(txt);
    int patternlen = strlen(pattern);
    KMPSearch(txt, textlen, pattern, patternlen);
    return 0;
}

