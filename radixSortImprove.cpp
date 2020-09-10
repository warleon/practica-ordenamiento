#include"auxiliar.h"
#include<time.h>

void radixSortImproved(int input[], int n, int maxLength,int radix) {
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
