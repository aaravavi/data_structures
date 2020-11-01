#include <stdio.h>

void printArray(int *A, int n){
    for (int i = 0; i <n; i++) {
        printf("%d ", A[i]);
    }

    printf("\n");
}

int partition(int *A, int low, int high){
    int pivot=A[low];
    int i = low+1;
    int j = high;
    int temp;
    do{
        while(A[i]<=pivot)
        {
            i++;
        }
        while(A[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }while(i<=j);
    
    temp = A[low];
    A[low]=A[j];
    A[j]= temp;
    return(j);
}

void quickSort(int *A, int low, int high){
  int indexOfPivot;
  if(low<high)
  {
      indexOfPivot = partition(A, low, high);
      quickSort(A, low, indexOfPivot-1);
      quickSort(A, indexOfPivot+1, high);
  }
}

int main()
{
    // 2, 18, 4, 16, 6
    //
    int A[]={2,18,4,16,6,18,3,45,6};
    int n= 9;
    int low=0;
    int high=n-1;
    printArray(A, n);
    quickSort(A, low, high);
    printArray(A, n);

    return 0;
}