#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Quick Sort

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);

  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);

    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

//Inserion Sort
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
    int j = n;
    for (int i = 0; i<n/2;i++){
         array[i] = i+1;
    }	 
    for (int i = n/2; i<n; i++){
	 array[i] = j;
	 j--;
         }	 
    return array;
}
int main() {
    int size = 0;
    cin >> size;
    int *dataArray;

    /* for(int i = size; i < 100; i = i+10) {
         dataArray = Array(size); 
         auto start = high_resolution_clock::now();
         quickSort(dataArray, 0, i - 1);
         auto end = high_resolution_clock::now();
         
         duration<double> duration = end - start;
         cout << "Tiempo de ejecución de "<< i << " datos es: "<< duration.count() << " segundos" << endl;
    }*/

    int *dataArray2;
    for(int i = size; i < 100; i = i+10) {
         dataArray2 = Array(i);
         auto start = high_resolution_clock::now();
         insertionSort(dataArray2,i);
         auto end = high_resolution_clock::now();

         duration<double> duration = end - start;
         cout << "Tiempo de ejecución de "<< i << " datos es: "<< duration.count() << " segundos" << endl;
       }

    return 0;
}

