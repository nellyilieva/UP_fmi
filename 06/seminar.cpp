#include <iostream>

//Linear search

int linearSearch(const int* arr, int size, int x) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == x) {
			return i;
		}
	}

	return -1;
}

//Binary search

int binarySearch(const int* arr, int size, int x) {
	for (int i = 0; i < size; i++) {
		int low = 0;
		int high = size - 1;
		
		while (low <= high) {
			int mid = low + (high - low) / 2;

			if (arr[mid] == x) {
				return mid;
			}
			else if (arr[mid] > x) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
	}

	return -1;
}

//Reverse array

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void reverse(int* arr, int size) {
	for (int i = 0; i < size / 2; i++) {
		swap(arr[i], arr[size - i - 1]);
	}
}


int main() {
	
}