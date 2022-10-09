#include <stdio.h>
void printArray(int arr[], int n){
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}
void swap(int *p,int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}
int *selectionSort(int a[], int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(a[min]>a[j]){
                min = j;
            }
        }
        if(min != i){
            swap(&a[min],&a[i]);
        }
    }

    return a;
}
int main(){
    int n;
    printf("Enter the number of Array elements : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter Array Elements : ");
    for(int i=0; i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Before Sorting :\n");
    printArray(a,n);
    int *b = selectionSort(a,n);
    printf("\nAfter Sorting :\n");
    printArray(a,n);
    return 0;
}