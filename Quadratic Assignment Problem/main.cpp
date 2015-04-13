//
//  main.cpp
//  Quadratic Assignment Problem
//
//  Created by Mathieu Spegagne on 12/04/2015.
//  Copyright (c) 2015 Mathieu Spegagne. All rights reserved.
//

# include <iostream>
# include <stdio.h>
# include <algorithm>
# include <limits>

using namespace std;

int fact(int n)
{
    int fact = 1 ;

    for(int i = 1; i <= n; i++){
        fact = fact * i ;
    }

    return fact;
}


int** permut(int n)
{
    int nbPermut = fact(n);

    int** res = new int*[nbPermut];

    int array[n];
    for(int i=0; i<n; i++)
    {
        array[i]=i;
    }
    std::sort (array,array+n);

    nbPermut = 0;
    do {
        res[nbPermut] = new int[n];
        for(int i=0; i<n; i++)
        {
            res[nbPermut][i]=array[i];
        }
        nbPermut++;
    } while ( std::next_permutation(array,array+n) );

    return res;
}

void QAP(int n, int** A, int** B, int** C)
{
    int nbPermut = fact(n);

    int** res = new int*[nbPermut];
    res = permut(n);
    int* tabZ = new int[nbPermut];

    int min =  std::numeric_limits<int32_t>::max();
    int indexMin = 0;

    for(int p = 0; p < nbPermut; p++)
    {

        int** Bbis = new int*[n];
        int* perm = res[p];

        printf("\n Permutation : ");
        for(int k = 0; k < n; k++)
        {
            printf("%d ;", perm[k]);
        }

        for(int j = 0; j < n; j++)
        {
            Bbis[j] = new int[n];
            for(int l = 0; l < n; l++)
            {
                Bbis[j][l]=B[perm[j]][perm[l]];
            }
        }

        int z = 0;

        for(int i = 0; i < n; i++)
        {
            for(int k = 0; k < n; k++)
            {
                z += A[i][k]*Bbis[i][k];
            }
        }
        for(int i = 0; i < n; i++)
        {
           z += C[i][perm[i]];
        }

        printf("\n Value : %d", z);

        tabZ[p] = z;

        if(z < min){
            min = z;
            indexMin = p;
        }

    }

    printf("\n ------------------------- ");
    printf("\n Best placement is : ");
    for(int k = 0; k < n; k ++)
    {
        printf("\n Facility %d to location %d", k, res[indexMin][k]);
    }
    printf("\n With a value equals to : %d", min);

}

int main(int argc, const char * argv[])
{
    int n;

    printf("\nEnter the number of facilities :\n");
    scanf("%d", &n);

    int** A = new int*[n];
    int** B = new int*[n];
    int** C = new int*[n];

    printf("\n ------------------------- ");
    printf("\nEnter the flow from facility i to facility k:\n");

    for(int i = 0; i < n; i++)
    {
        A[i] = new int[n];
        for(int k = 0; k < n; k++)
        {
            int val;
            printf("\n i= %d ; k= %d >", i, k);
            scanf("%d", &val);
            A[i][k] = val;
        }
    }

    printf("\n ------------------------- ");
    printf("\nEnter the distance from location j to location l:\n");

    for(int j = 0; j < n; j++)
    {
        B[j] = new int[n];
        for(int l = 0; l < n; l++)
        {
            printf("\n j= %d ; l= %d >", j, l);
            scanf("%d", &B[j][l]);
        }
    }

    printf("\n ------------------------- ");
    printf("\nEnter the cost of placing facility i at location j :\n");

    for(int i = 0; i < n; i++)
    {
        C[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
            printf("\n i= %d ; j= %d >", i, j);
            scanf("%d", &C[i][j]);
        }
    }

    printf("\n ------------------------- ");

    QAP(n, A, B, C);

    printf("\n ------------------------- \n");
    return 0;
}
