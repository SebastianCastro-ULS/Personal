#include <iostream>
#include <chrono> 
using namespace std;
using namespace std::chrono;

void insertionSort(int arr[], int n) {
   for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void printArray(int arr[], int n){
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int* Array(int n) {
    int* array = new int[n];
    int j = 0;
  	for (int i = n; i>=1; i--){
	    array[j] = i;
	    j++;
	}
    return array;
}

int main() {
    int size = 0;
    cin >> size;
    int *dataArray; 
    for(int i = size; i < 10000000; i = i*10) {
         dataArray = Array(i);
         auto start = high_resolution_clock::now();
         insertionSort(dataArray,i);
         auto end = high_resolution_clock::now();

         duration<double> duration = end - start;
         cout << "Tiempo de ejecución de "<< i << " datos es: "<< duration.count() << " segundos" << endl;
         // printArray(dataArray,i);
	 dataArray = nullptr;
    }

    return 0;
}
