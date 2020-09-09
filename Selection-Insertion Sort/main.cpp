#include <iostream>
#include <chrono>
#include <cmath>
#include "funciones.h"

using namespace std;
using namespace std::chrono;

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
}

