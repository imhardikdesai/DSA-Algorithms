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
int *bubbleSort(int a[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(a[j]>a[j+1]){
                swap(&a[j], &a[j+1]);
            }
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
    int *b = bubbleSort(a,n);
    printf("\nAfter Sorting :\n");
    printArray(a,n);
    return 0;
}