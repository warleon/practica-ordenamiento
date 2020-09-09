#include <iostream>
#include <ctime>

using namespace std;

void display(int* arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int* arr, int n) {
    int min_idx;

    for (int i = 0; i < n-1; i++) {
        min_idx = i;

        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        swap(&arr[min_idx], &arr[i]);
    }
}

int main() {
    int n, max=10000;
    cout << "Enter the number of elements: "; cin >> n;
    int* arr = new int[n];
    srand(time(nullptr));
    for(int i=0;i<n;i++)
        arr[i]=rand()%max + 1;

    cout << "Data before Sorting:\n";
    display(arr, n);
    selectionSort(arr, n);
    cout << "Data after Sorting:\n";
    display(arr, n);
    return 0;
}