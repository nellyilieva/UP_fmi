#include <iostream>

int binarySearch(const int* arr, int size, int target) {
	size_t leftIndex = 0, rightIndex = size - 1;

	while (leftIndex <= rightIndex) {
		size_t midIndex = leftIndex + (rightIndex - leftIndex) / 2;

		if (arr[midIndex] == target) {
			return midIndex;
		}
		else if (arr[midIndex] < target) {
			leftIndex = midIndex + 1;
		}
		else {
			rightIndex = midIndex - 1;
		}
	}

	return -1;
}

void findElementInSortedMatrix(int** matrix, int rows, int cols, int n, int result[2]) {
	for (int i = 0; i < rows; i++) {
		int colIdx = binarySearch(matrix[i], cols, n);

		if (colIdx != -1) {
			result[0] = i;
			result[1] = colIdx;
			return;
		}
	}

	result[0] = -1;
	result[1] = -1;
}

int findIdxToAddNumber(int* arr, int size, int n) {
	int idx = 0;

	while (arr[idx] < n) {
		idx++;
	}

	return idx;
}

//int findIdxOfDifferentElement(int* arr1, int* arr2, int size) {   //linear search
//	for (int i = 0; i < size + 1; i++) {
//		if (arr1[i] != arr2[i]) {
//			return i;
//		}
//	}
//
//	return -1;
//}

int findIdxOfDifferentElement(int* arr1, int* arr2, int size) {   //binary search
	int left = 0;
	int right = size;

	while (left < right) {
		int mid = left + (right - left) / 2;

		if (arr1[mid] != arr2[mid]) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	return left;
}

int returnPeakIdx(int* arr, int size) {
	int left = 0;
	int right = size - 1;

	while (left < right) {
		int mid = left + (right - left) / 2;

		if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) {
			return mid;
		}
		
		if (arr[mid] < arr[mid + 1]) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return left;
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void cocktailShaker(int* arr, int size) { ///variation of bubble sort
	bool isSwapped = true;
	int start = 0;
	int end = size - 1;

	while (isSwapped) {
		isSwapped = false;

		for (int i = start; i < end; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				isSwapped = true;
			}
		}

		if (!isSwapped) {
			break;
		}

		isSwapped = false;

		end--;

		for (int i = end; i >= start; i--) {
			if (arr[i] < arr[i - 1]) {
				swap(arr[i], arr[i - 1]);
				isSwapped = true;
			}
		}

		start++;
	}
}

int findMissingNumber(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		while (arr[i] >= 0 && arr[i] < size && arr[i] != arr[arr[i]]) {
			swap(arr[i], arr[arr[i]]);
		}
	}

	for (int i = 0; i < size; i++) {
		if (arr[i] != i) {
			return i;
		}
	}

	return size;
}

int findKBiggestElement(int* arr, int size, int k) {
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}

	return arr[size - k];
}


int main() {
	int arr[] = { 39, 4, 6, 1, 2, 66, 33 };
	std::cout << findKBiggestElement(arr, 7, 3);

	/*int rows = 3, cols = 3;

	int** matrix = new int* [rows];
	matrix[0] = new int[cols] {1, 2, 3};
	matrix[1] = new int[cols] {4, 5, 6};
	matrix[2] = new int[cols] {7, 8, 9};

	int result[2];

	findElementInSortedMatrix(matrix, rows, cols, 7, result);

	std::cout << result[0] << " " << result[1];

	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;*/
}