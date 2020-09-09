#include<list>
#include<cmath>

using namespace std;

int myHash(int n,int radix, int pos){
    int m = pow(radix, pos+1);
    int p = pow(radix, pos);

    int temp = n%m;
    int index = temp/p;      //find index for pocket array

    return index;
}

void radixSort(int arr[], int n, int max,int radix) {
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
