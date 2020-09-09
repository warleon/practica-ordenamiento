#include<iostream>
#include<list>
#include<cmath>
#include<random>
#include<time.h>

using namespace std;

void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}

int myHash(int n,int radix, int pos){
    int m = pow(radix, pos+1);
    int p = pow(radix, pos);

    int temp = n%m;
    int index = temp/p;      //find index for pocket array

    return index;
}

void radixSort(int *arr, int n, int max,int radix) {
   int i, j, count = 0;
   list<int> pocket[radix];      //radix of decimal number is 10
   for(i = 0; i< max; i++) {

      for(j = 0; j<n; j++)
         pocket[myHash(arr[j],radix,i)].push_back(arr[j]);

      count = 0;
      for(j = 0; j<10; j++) {
         //delete from linked lists and store to array
         while(!pocket[j].empty()) {
            arr[count] = *(pocket[j].begin());
            pocket[j].erase(pocket[j].begin());
            count++;
         }
      }
   }

}

int main() {
   int n, max=10000;
   cout << "Enter the number of elements: ";cin >> n;
   int arr[n];
   srand(time(NULL));
   for(int i=0;i<n;i++)
       arr[i]=rand()%max + 1;

   cout << "Data before Sorting:\n";
   display(arr, n);
   radixSort(arr, n, max,10);
   cout << "Data after Sorting:\n";
   display(arr, n);
}
