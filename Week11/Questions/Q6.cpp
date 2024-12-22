#include <iostream>
using namespace std;
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void reverseArray(int* arr, int size) {
    int* start = arr;  
    int* end = arr + size - 1;
    while (start < end) {
        swap(*start,*end);
        start++;
        end--;
    }
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int* array = new int[size];
    cout << "Enter " << size << " elements of the array:" << endl;
    for (int i = 0; i < size; i++) {
        cout<<"Enter the number: ";
        cin >> array[i];
    }

    reverseArray(array, size);
    cout << "Reversed array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    delete[] array;
    return 0;
}
