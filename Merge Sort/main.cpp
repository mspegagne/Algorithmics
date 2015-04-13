//
//  main.cpp
//  Merge Sort
//
//  Created by Mathieu Spegagne on 08/04/2015.
//  Copyright (c) 2015 Mathieu Spegagne. All rights reserved.
//

# include <iostream>
# include <stdio.h>
# include <cstdlib>

int max(int x, int y)
{
    if(x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

void merge(int *input, int left, int right, int *res)
{
    if(right == left + 1)
    {
        return;
    }
    else
    {
        int i = 0;
        int length = right - left;
        int mid = length/2;

        int l = left, r = left + mid;

        merge(input, left, left + mid, res);
        merge(input, left + mid, right, res);

        for(i = 0; i < length; i++)
        {
            if(l < left + mid && (r == right || max(input[l], input[r]) == input[l]))
            {
                res[i] = input[l];
                l++;
            }
            else
            {
                res[i] = input[r];
                r++;
            }
        }

        for(i = left; i < right; i++)
        {
            input[i] = res[i - left];
        }
    }
}

void mergesort(int *input, int size)
{
    int *res = (int *)malloc(size * sizeof(int));
    if(res != NULL)
    {
        merge(input, 0, size, res);

        for(int i = 0; i < size; i++)
        {
            printf("\n> %d", res[i]);
        }

        free(res);
    }
    else
    {
        printf("\n error");
    }
}

int main(int argc, const char * argv[]) {

    int length;

    printf("\nEnter the length of the array:\n");
    scanf("%d", &length);

    int numbers[length];

    printf("\nEnter the numbers:\n");
    for(int j = 0; j < length; j ++)
    {
        printf("%2d> ",j+1);
        scanf("%d", &numbers[j]);
    }

    printf("\nResult of the Merge Sort is:");
    mergesort(numbers, length);

    return 0;
}
