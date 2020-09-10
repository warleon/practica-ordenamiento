#pragma once
#include<cmath>

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
