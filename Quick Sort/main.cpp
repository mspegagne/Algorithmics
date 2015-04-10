//
//  main.cpp
//  Quick Sort
//
//  Created by Mathieu Spegagne on 10/04/2015.
//  Copyright (c) 2015 Mathieu Spegagne. All rights reserved.
//


#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>


int random(int first, int last)
{
    return std::rand() % (last - first) + first;
}

int part(int *input, int first, int last, int pivot)
{
    int lastval = input[last];
    input[last]= input[pivot];
    input[pivot] = lastval;

    int j = first;
    for (int i=first; i<last; i++)
    {
        if(input[i] <= input[last])
        {
            int ival = input[i];
            input[i]= input[j];
            input[j] = ival;

            j++;
        }
    }

    int jval = input[j];
    input[j]= input[last];
    input[last] = jval;

    return j;
}

void quicksort(int *input, int first, int last)
{
    if(first < last)
    {
        int pivot = random(first, last);
        pivot = part(input, first, last, pivot);
        quicksort(input, first, (pivot-1));
        quicksort(input, (pivot+1), last);
    }
}

int main(int argc, const char * argv[])
{
    int length;

    printf("\nEnter the length of the array:\n");
    scanf("%d", &length);

    int numbers[length];

    printf("\nEnter the numbers:\n");
    for(int k = 0; k < length; k ++)
    {
        printf("%2d> ",k+1);
        scanf("%d", &numbers[k]);
    }

    quicksort(numbers, 0, (length-1));

    printf("\nResult of the Quick Sort is:");
    for(int l = 0; l < length; l++)
    {
        printf("\n> %d", numbers[l]);
    }


    return 0;
}
