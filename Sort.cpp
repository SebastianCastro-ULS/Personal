#include <iostream>
using namespace std;

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
    int *dataArray = Array(size);

    printArray(dataArray, size);
    insertionSort(dataArray, size);
    printArray(dataArray, size);

    return 0;
}

