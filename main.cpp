#include "radixSort.cpp"
#include "radixSortImprove.cpp"
#include "selectionSort.cpp"

#include<iostream>
#include<random>
#include<time.h>
#include<string>
#include<fstream>

using namespace std;

int* genRandomArray(int size,int base,int exp){
    int* arr= new int[size];
    int max= pow(base,exp);
    srand(time(NULL));
    for(int i=0;i<size;i++)
        arr[i]=rand()%max;

    return arr;
}

bool checkSorting(int input[],int n,char comp){
    if(comp=='<'){
        for(int i=0;i<n-1;i++)
            if(input[i]>input[i+1])return false;
    }
    else if(comp=='>'){
        for(int i=0;i<n-1;i++)
            if(input[i]<input[i+1])return false;
    }

    return true;
}

string RadixTime(auto sort, int base, int maxPower){
    string csvalues="";
    int size;
    int *array=nullptr;
    clock_t start, end;
    double tiempo;
    for(int i=0;i<maxPower;i++){
        size=pow(base,i);
        array=genRandomArray(size,base,i);

        start=clock();
            sort(array,size,i,base);
        end=clock();

        tiempo=double(end-start)/double(CLOCKS_PER_SEC);

        if(checkSorting(array,size,'<'))
            csvalues+=to_string(tiempo)+",";
        else
            csvalues+=",";

        delete[] array;
    }
    return csvalues;
}

string SelectionTime(auto sort, int base, int maxPower){
    string csvalues="";
    int size;
    int *array=nullptr;
    clock_t start, end;
    double tiempo;
    for(int i=0;i<maxPower;i++){
        size=pow(base,i);
        array=genRandomArray(size,base,i);

        start=clock();
            sort(array,size);
        end=clock();

        tiempo=double(end-start)/double(CLOCKS_PER_SEC);

        if(checkSorting(array,size,'<'))
            csvalues+=to_string(tiempo)+",";
        else
            csvalues+=",";

        delete[] array;
    }
    return csvalues;
}

string values(int base, int maxPower){
    string csvalues="";
    int size;
    for(int i=0;i<maxPower;i++){
        size=pow(base,i);

    csvalues+=to_string(size)+",";
    }
    return csvalues;
}

int main(){
    ofstream myFile;
	myFile.open("values.csv",ios::out);
	if(myFile.is_open()){
        myFile<<values(2,21)<<"\n";
        myFile<<"Radix,"<<RadixTime(radixSortImproved,2,21)<<"\n";
        myFile<<"Selection,"<<SelectionTime(selectionSort,2,21)<<"\n";
    }
    return 0;
}
