//
//  main.cpp
//  Boyer_Moore
//
//  Created by Mathieu Spegagne on 11/03/2015.
//  Copyright (c) 2015 Mathieu Spegagne. All rights reserved.
//

#include <iostream>
# include <limits.h>
# include <string.h>
# include <stdio.h>

# define NO_OF_CHARS 256

using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void badCharHeuristic(string str, int size, int badchar[NO_OF_CHARS])
{
    for (int i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    for (int j = 0; j < size; j++)
        badchar[(int) str[j]] = j;
}

void search(string txt, string pat)
{
    int m = static_cast<int>(pat.length());
    int n = static_cast<int>(txt.length());

    int badchar[NO_OF_CHARS];
    int nbocc = 0;

    badCharHeuristic(pat, m, badchar);

    int s = 0;
    while (s <= (n - m))
    {
        int j = m - 1;

        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        if (j < 0)
        {
            printf("\n Pattern occurs at shift = %d", s);
            nbocc++;
            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
        }

        else
            s += max(1, j - badchar[txt[s + j]]);
    }

    if(nbocc == 0)
        printf("\n Pattern not found...");


}


int main(int argc, const char * argv[])
{
    string txt, pat;

    printf("\nEnter the text :\n");
    char tmp[200];
    scanf("%200s", tmp);
    txt = tmp;

    printf("\nEnter the pattern:\n");
    char tmp2[200];
    scanf("%200s", tmp2);
    pat = tmp2;

    search(txt, pat);
    return 0;
}
