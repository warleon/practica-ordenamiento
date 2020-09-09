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

void fillArray(int array[],int size,int val){
    for(int i=0;i<size;i++)
        array[i]=val;
}
void prefixSum(int buckets[],int size){
    int total=0;
    for(int i=0;i<size;i++){
        total=total+buckets[i];
        buckets[i]=total;
    }
}

int myOtherHash(int n,int buckets[],int radix,int pos){
    return -- buckets[myHash(n,radix,pos)];
}

void copyArray(int from[],int to[],int n){
    for(int i=0;i<n;i++)
        to[i]=from[i];
}

void radixSort(int input[], int n, int maxLength,int radix) {
    int result[n];
    int buckets[radix];

    for(int i = 0; i< maxLength; i++) {
        fillArray(buckets,radix,0);
        //counting simbols
        for(int j = 0; j<n; j++)
            buckets[myHash(input[j],radix,i)]++;
        //preparing the hash
        prefixSum(buckets,radix);
        //this should fill the result completely
        for(int j = n-1; j>=0; j--)
            result[myOtherHash(input[j],buckets,radix,i)]=input[j];
        
        copyArray(result,input,n);
    }
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
