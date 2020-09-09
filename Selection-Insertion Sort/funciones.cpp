#include "funciones.h"

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

int* insertion_sort(int* arr, int n){
	int cursor;
	int pos;
	for(int i=0; i<n; ++i){
		cursor =  arr[i];
		pos = 1;
		while(pos>0 && arr[pos - 1]>cursor){
			arr[pos] = arr[pos - 1];
			pos = pos - 1;
		}
		arr[pos] = cursor;	
	}
	return arr;
}
