#ifdef improve
#include "radixSortImprove.cpp"
#else
#include "radixSort.cpp"
#endif

#include <iostream>
#include<random>
#include<time.h>

void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}

bool checkSorting(int input[],int n){
    for(int i=0;i<n-1;i++)
        if(input[i]>input[i+1]) return false;

    return true;
}

int main() {
    int n, max=10000;
    cout << "Enter the number of elements: ";cin >> n;
    int arr[n];
    srand(time(NULL));
    for(int i=0;i<n;i++)
       arr[i]=rand()%max + 1;

    //   cout << "Data before Sorting:\n";
    //   display(arr, n);
    radixSort(arr, n, 5,10);
    //   cout << "Data after Sorting:\n";
    //   display(arr, n);
    
    cout<<"is the array sorted?: "<< (checkSorting(arr,n)?"Yes":"No")<<"!\n";
    return 0;
}
