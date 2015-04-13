//
//  main.cpp
//  Binary Search
//
//  Created by Mathieu Spegagne on 03/02/2015.
//  Copyright (c) 2015 Mathieu Spegagne. All rights reserved.
//

# include <iostream>
# include <stdio.h>

using namespace std;

bool binary_search(int A[], int key, int min, int max)
{
    if (max < min)
        return  false;
    else
    {
        int mid = min + ((max - min) / 2);

        if (A[mid] > key)
            return binary_search(A, key, min, mid - 1);
        else if (A[mid] < key)
            return binary_search(A, key, mid + 1, max);
        else
            return true;
    }
}

int main(int argc, const char * argv[]) {

    int length, key;
    bool res;

    printf("\nEnter the length of the array:\n");
    scanf("%d", &length);

    int numbers[length];

    printf("\nEnter the numbers:\n");
    int i;

    for(i = 0; i < length; i ++)
    {
        printf("%2d> ",i+1);
        scanf("%d", &numbers[i]);
    }

    printf("\nEnter the key:\n");
    scanf("%d", &key);

    res = binary_search(numbers, key, 0, (length-1));
    printf("\nResult of the Binary Search is: %s", res ? "true" : "false");


    return 0;
}
