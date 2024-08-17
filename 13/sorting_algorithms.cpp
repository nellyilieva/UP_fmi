#include <iostream>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

const int CHARACTERS_COUNT = 256;

//Bubble sort(stable)
void bubbleSort(int* arr, size_t size) {
    for (int i = 0; i < size; i++) {
        bool isSwapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                isSwapped = true;
            }
        }

        if (!isSwapped) {
            break;
        }
    }
}

//Insertion sort(stable)
void insertionSort(int* arr, size_t size) {
    for (int i = 1; i < size; i++) {
        int currElement = arr[i];
        int currIdx = i - 1;

        while (currIdx >= 0 && arr[currIdx] > currElement) {
            arr[currIdx + 1] = arr[currIdx];
            currIdx--;
        }
        arr[currIdx + 1] = currElement;
    }
}

//Selection sort(unstable)
void selectionSort(int* arr, size_t size) {
    for (int i = 0; i < size; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[minIdx] > arr[j]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
        }
    }
}

//Counting sort(stable)
void countingSort(char* arr, size_t size) {
    size_t arrSize = strlen(arr);

    int counter[CHARACTERS_COUNT] = { 0 };
    for (int i = 0; i < size; i++) {
        counter[arr[i]]++;
    }

    int idx = 0;
    for (int i = 0; i < CHARACTERS_COUNT; i++) {
        while (counter[i] != 0) {
            arr[idx++] = i;
            counter[i]--;
        }
    }
}

int main() {
    char arr[] = "ababababababa";
    countingSort(arr, 13);
    std::cout << arr;
}