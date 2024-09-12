#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;

// Quick Sort

int partition(int arr[], int low, int high) {

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {

    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


//Insertion Sort
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

//Imprimir Array
void printArray(int arr[], int n){
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

//Generando WorstCase
int* WorstArray(int n){
    int* array = new int[n];
    int j = n;
    for (int i = 0; i<n;i++){
         array[i] = j;
	 j--;
    }
    return array;
}

//Generando BestCase
int* BestArray(int n){
    int* Array = new int[n];
    for (int i = 0; i<n; i++){
        Array[i] = i+1;
    }
    return Array;
}

//Generando AverageCase
int* AverageArray(int n){
     int* Array = new int[n];
     for (int i = 0; i<n/2; i++){
         Array[i] = i+1;
     }
     int j = n;
     for (int i = n/2; i<n; i++){
         Array[i] = j;
         j--;
     }
     return Array;
}

int main() {
    int size = 0;
    int type;
    cin >> size;
    string sort;
    cout << "1=Worst   2=Best    3=Average\n";
    cin >> type;
    cin >> sort;
    int *dataArray;

    ofstream outFile("AverageQuick.txt");
    if (!outFile) {
        cerr << "No se pudo abrir el archivo para escribir." << endl;
        return 1;
    }

    if (sort == "Q") {
        if (type == 1) {
            for (int i = size; i < 45000; i += 50) {
                dataArray = WorstArray(i);
                auto start = high_resolution_clock::now();
                quickSort(dataArray, 0, i - 1);
                auto end = high_resolution_clock::now();
		duration<double> duration = end - start;
		cout << i << " " << duration.count() << endl;
                outFile << i << " " << duration.count() << endl;
                delete[] dataArray;
            }
        } else if (type == 2) {
            for (int i = size; i < 45000; i += 50) {
                dataArray = BestArray(i);
                auto start = high_resolution_clock::now();
                quickSort(dataArray, 0, i - 1);
                auto end = high_resolution_clock::now();
		duration<double> duration = end - start;
		cout << i << " " << duration.count() << endl;
                outFile << i << " " << duration.count() << endl;
                delete[] dataArray;
            }
        } else if (type == 3) {
            for (int i = size; i < 45000; i += 50) {
                dataArray = AverageArray(i);
                auto start = high_resolution_clock::now();
                quickSort(dataArray, 0, i - 1);
                auto end = high_resolution_clock::now();
		duration<double> duration = end - start;
                cout << i << " " << duration.count() << endl;
                outFile << i << " " << duration.count() << endl;
                delete[] dataArray;
            }
        }
    } else {
        if (type == 1) {
            for (int i = size; i < 45000; i += 50) {
                dataArray = WorstArray(i);
                auto start = high_resolution_clock::now();
                insertionSort(dataArray, i);
                auto end = high_resolution_clock::now();
		duration<double> duration = end - start;
                cout << i << " " << duration.count() << endl;
                outFile << i << " " << duration.count() << endl;
       	        delete[] dataArray;
            }
        } else if (type == 2) {
            for (int i = size; i < 45000; i += 50) {
                dataArray = BestArray(i);
                auto start = high_resolution_clock::now();
                insertionSort(dataArray, i);
                auto end = high_resolution_clock::now();
		duration<double> duration = end - start;
                cout << i << " " << duration.count() << endl;
                outFile << i << " " << duration.count() << endl;
                delete[] dataArray;
            }
        } else if (type == 3) {
            for (int i = size; i < 45000; i += 50) {
                dataArray = AverageArray(i);
                auto start = high_resolution_clock::now();
                insertionSort(dataArray, i);
                auto end = high_resolution_clock::now();
		duration<double> duration = end - start;
                cout << i << " " << duration.count() << endl;
                outFile << i << " " << duration.count() << endl;
                delete[] dataArray;
            }
        }
    }

    outFile.close();
    return 0;
}
