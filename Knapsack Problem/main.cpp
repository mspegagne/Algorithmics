//
//  main.cpp
//  Knapsack Problem
//
//  Created by Mathieu Spegagne on 04/02/2015.
//  Copyright (c) 2015 Mathieu Spegagne. All rights reserved.
//


#include <iostream>
#include <stdio.h>
#include <cstdlib>

void Knapsack(int length, double* profit, double* weight, int capacity)
{

    double value[length];
    int max = 0;
    double maxvalue = 0;
    double maxprofit = 0;

    for(int i = 0; i < length; i ++)
    {
        value[i]=(profit[i]/weight[i]);
        printf("\nValue: %f\n", value[i]);

        if(value[i]>maxvalue){
            maxvalue=value[i];
            max=i;
        }
    }

    for(int j = 0; j < length; j ++)
    {

        for(int k = 0; k < length; k ++)
        {
            if(value[k]>maxvalue)
            {
                maxvalue=value[k];
                max=k;
            }
        }

        if((capacity-weight[max])>=0){
            maxprofit += profit[max];
            capacity -= weight[max];
            printf("\nOk: %d\n", max+1);
        }

        value[max]=0;
        maxvalue=0;
        max=0;

    }

    printf("\nMax Profit: %f\n", maxprofit);
}


int main(int argc, const char * argv[]) {

    int length, capacity, i;

    printf("\nEnter the number of objects:\n");
    scanf("%d", &length);

    double profit[length];
    double weight[length];

    printf("\nEnter the profit for each object:\n");

    for(i = 0; i < length; i ++)
    {
        scanf("%lf", &profit[i]);
    }

    printf("\nEnter the weight for each object:\n");

    for(i = 0; i < length; i ++)
    {
        scanf("%lf", &weight[i]);
    }


    printf("\nEnter the capacity:\n");
    scanf("%d", &capacity);


    Knapsack(length, profit, weight, capacity);

    return 0;
}
