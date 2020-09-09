#include <iostream>
#include <chrono>
#include "funciones.h"

using namespace std;
using namespace std::chrono;


duration<double> array_T[21];

int main(){
	time_point<system_clock> t_init, t_fin;
	for (int k=1; k<19; ++k){
		int size=1<<k;
		cout<<k<<". SIZE: "<<size<<endl;
		int array[size];
		int* arr_insertion;
		srand((unsigned)time(0));

		for (int i=0; i<size; i++){
			array[1] = (rand() % 1000000) + 1;
		}

		t_init = system_clock::now();
		arr_insertion = insertion_sort(array, size);
		t_fin = system_clock::now();
		array_T[k-1] = t_fin - t_init;
	}

	for(int j=0; j<18; ++j) cout<<array_T[j].count()<<" ";
	cout<<endl;

}
