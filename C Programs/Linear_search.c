#include <stdio.h>

// This is a linear search program.

int main()
{   int size;
    int value;
    int validator = 0;  //validator is to check whether the elements to find exists or not
    
    // getting the array input
    printf("Enter the size of the array:");
    scanf("%d",&size);
    int array[size];
    for(int i = 0;i<size;i++){
        printf("Enter the element no %d:",i+1);
        scanf("%d",&array[i]);
    }
    
    // value to be find
    printf("Enter the element you want to search:");
    scanf("%d",&value);
    
    //linear search
    printf("The value:- %d is at,\n",value);
    
    for(int i = 0;i<size;i++){
        if (array[i] == value){
            validator = 1;
            printf("index:%d \n",i);
        }
    }
    if(validator == 0) {printf("This element is not in the array");}
    
    return 0;
}
