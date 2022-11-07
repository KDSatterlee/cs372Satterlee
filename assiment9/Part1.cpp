//
// File:   lab16.cpp
// Author: Your Glorious Instructor
// Purpose:
// Illustrate the workings of Quicksort

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

template <typename T>
void ourSwap(T& left, T& right) {
    T temp;
    temp = left;
    left = right;
    right = temp;
}

template<typename T>
void printArray(vector<T> test) {
    for (int index = 0; index < test.size(); ++index) {
        cout << test[index] << " ";
    }
    cout << endl;
}
template <typename T>
int Partition(vector<T> a, int start, int end) {
    int pivotValue, pivotIndex, mid;
    mid = (start + end) / 2;
    ourSwap(a[start], a[mid]);
    pivotIndex = start;
    pivotValue = a[start];
    for (int scan = start + 1; scan <= end; scan++) {
        if (a[scan] < pivotValue) {
            pivotIndex++;
            ourSwap(a[pivotIndex], a[scan]);
        }
    }
    ourSwap(a[start], a[pivotIndex]);
    return pivotIndex;
}

template<typename T>
void Quicksort(vector<T> a, int start, int end) {
    int pivotPosition;
    if (start < end) {
        pivotPosition = Partition(a, start, end);
        Quicksort(a, start, pivotPosition - 1);
        Quicksort(a, pivotPosition + 1, end);
    }
}

template<typename T>
void selectionSort(vector<T> a, int start, int end){
    unsigned minIndex;
    int temp;
    for(int scan = start; scan < end; ++scan){
        minIndex = scan;
        for(int j = scan + 1; j < end; j++){
            if(a[j] < a[minIndex]){
                minIndex = j;
            }
            if (minIndex != scan){
                temp = a[scan];
                a[scan] = a[minIndex];
                a[minIndex] = temp;
            }
        }
    }
}

vector<int> randNumber(int max){
    // Providing a seed value
    vector<int> get;
        srand((unsigned) time(NULL));

        // Loop to get 5 random numbers
        for(int i=0; i<=max; i++){
            
            // Retrieve a random number between 100 and 200
            // Offset = 100
            // Range = 101
            int random = (rand() % 100001);

            // Print the random number
            get.push_back(random);
            
        }
    return get;
}

int main() {
    vector<int> test;
    vector<int> test2;
    int myArray[]= {5, 10, 20, 50, 100, 1000, 10000, 50000};
    int y = 7;
    for(int x =0; x <= y; x++){
        int testing = myArray[x];
        test = randNumber(testing);
        int SIZE = test.size();
        cout << "Testing quicksort time of size: "<< myArray[x] << endl;
        auto start = std::chrono::steady_clock::now();
        Quicksort(test, 0, SIZE - 1);
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        cout << "time elapsed: " << elapsed_seconds.count() << "s\n";
        
        test2 = randNumber(testing);
        cout << "Testing sekection sort time of size: "<< myArray[x] << endl;
        auto start2 = std::chrono::steady_clock::now();
        selectionSort(test2, 0, SIZE - 1);
        auto end2 = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds2 = end2-start2;
        cout << "time elapsed: " << elapsed_seconds2.count() << "s\n";
        }
    return 0;
}

