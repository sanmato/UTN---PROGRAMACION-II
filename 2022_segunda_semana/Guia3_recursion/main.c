#include<stdlib.h>
#include<stdio.h>

int factorial(int x);
int pow(int , int );
void showArrayRecursive(int [], int, int);
void showReverseArrayRecursive(int [], int , int );

int main()
{
    int num = 5;
    num = factorial(num);
    printf("\nFactorial: %d", num);

    printf("\nPow: %d", pow(9, 2));

    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //showArrayRecursive(array, 0, 10);
    //showReverseArrayRecursive(array, 10);
    showReverseArrayRecursive(array, 0, 10);

    return 0;
}

//Ej 1
int factorial(int x) {
    int ans;
    if(x == 0)
        ans = 1;
    else
        ans = x*factorial(x-1);
    return ans;
}

//Ej 2
int pow(int x, int n) {
    int ans;
    if(n == 0)
        ans = 1;
    else if(x == 0)
        ans = 0;
    else
        ans = x*pow(x, n-1);
    return ans;
}
///3125
///5*625
///5*125
///5*25
///5*5
//0


//Ej 3
void showArrayRecursive(int array[], int pos, int quantity) {
    if(pos == quantity-1) 
        printf("\n[%d]", array[pos]);
    else {
        printf("\n[%d]", array[pos]);
        showArrayRecursive(array, pos+1, quantity);
    }
}


//Ej 4
void showReverseArrayRecursive(int array[], int pos, int quantity) {
    if(pos < quantity) {
        showReverseArrayRecursive(array, pos+1, quantity);
        printf("\n[%d]", array[pos]);
    }       
}

///5. Determinar en forma recursiva si un arreglo es capicúa.
