<<<<<<< HEAD:Selection2_Sort.cpp
#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;

int* selection_sort(int* arr, int n){
	int minimum;
	int temp;
	for(int i=0; i<n; ++i){
		minimum=i;
		for(int j=i+1; j<n; ++j){
			if(arr[j] < arr[minimum]) minimum=j;
		}
		temp = arr[minimum];
		arr[minimum] = arr[i];
		arr[i] = temp;
	}

	return arr;
}

duration<double> array_T[6];

int main(){
	time_point<system_clock> t_init, t_fin;

	for(int k = 1; k<6; ++k){
		int size=pow(10,k);
		cout<<k<<". SIZE: "<<size<<endl;
		int array[size];
		int* arr_selection;
		srand((unsigned)time(0));

		for(int i=0; i<size; i++) array[i] = (rand() % 1000000) + 1;
	
		t_init = system_clock::now();
		arr_selection = selection_sort(array, size);
		t_fin = system_clock::now();
		array_T[k-1] =  t_fin - t_init;
	}
	
	for(int j=0; j<5; j++) cout<<array_T[j].count()<<" ";
	cout<<endl;
=======
#include "radixSortImprove.cpp"
#include "funciones.cpp"

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
>>>>>>> c35a16221b7e2861cfe0cc3c62fbb23d67f4e823:Selection-Insertion Sort/main.cpp
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

string InsertionTime(auto sort, int base, int maxPower){
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

int main() {
    cout<<RadixTime(radixSort,10,7)<<"\n";
    cout<<InsertionTime(insertion_sort,10,5)<<"\n";
    return 0;
}
