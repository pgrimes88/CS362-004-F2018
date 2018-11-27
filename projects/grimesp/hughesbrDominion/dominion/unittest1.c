#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int compare(const void* a, const void* b);

int main(){
    printf("unittest1.c\n");
    printf("Compare Function\n");
    const void *a;
    const void *b;
    int value1;
    int value2;
    int compared;
    
    //check if value 1 is equal to value 2
    //expecting a return of 0
    value1 = 100;
    value2 = 100;
    a = &value1;
    b = &value2;
    compared = compare(a,b);
    if(compared == 0){
        printf("first test Successful -- %d == %d\n",value1,value2);
    }
    else{
        printf("TEST FAILED");
        return 0;
    }
    
    //check if value 1 is less than value 2
    //expecting a return of -1
    value1 = 50;
    value2 = 100;
    a = &value1;
    b = &value2;
    compared = compare(a,b);
    if(compared == -1){
        printf("second test Successful -- %d < %d\n",value1,value2);
    }
    else{
        printf("TEST FAILED");
        return 0;
    }
    
    //check if value 1 is greater than value 2
    //expecting a return of 1
    value1 = 100;
    value2 = 50;
    a = &value1;
    b = &value2;
    compared = compare(a,b);
    if(compared == 1){
        printf("Third test Successful -- %d > %d\n",value1,value2);
    }
    else{
        printf("TEST FAILED");
        return 0;
    }
    
    printf("ALL TESTS SUCCESSFULLY COMPLETED\n\n");
    
}