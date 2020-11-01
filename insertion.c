#include <stdio.h>

void printArray(int *A, int n){
    for (int i = 0; i <n; i++) {
        printf("%d ", A[i]);
    }

    printf("\n");
}

void insertionSort(int *A, int n){
    int key;
    for(int i=1;i<n;i++)
    {
        int j = i-1;
        key = A[i];
        while(j>=0 && A[j]>key)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
}

int main()
{
    // 2, 18, 4, 16, 6
    //
    int A[]={2,18,4,16,6};
    int n= 5;
    printArray(A, n);
    insertionSort(A, n);
    printArray(A, n);

    return 0;
}
