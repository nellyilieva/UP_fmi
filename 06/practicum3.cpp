#include <iostream>

const unsigned MAX_SIZE = 1000;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

bool isValidIdx(unsigned length, unsigned idx) {
	return 0 <= idx && idx <= length - 1;
}

bool isValidLength(unsigned length) {
	return 0 < length && length <= MAX_SIZE;
}

void readArray(int* arr, unsigned length) {
	for (unsigned i = 0; i < length; i++) {
		std::cin >> arr[i];
	}
}

void printArray(const int* arr, unsigned length) {
	for (unsigned i = 0; i < length; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}


int* returnIntersection(const int* arr1, unsigned size1, const int* arr2, unsigned size2, int* result = {}, unsigned sizeResult = 0) {
	sizeResult = 0;

	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			if (arr1[i] == arr2[j]) {

				bool isInArray = false;

				for (int k = 0; k < sizeResult; k++) {
					if (result[k] == arr1[i]) {
						isInArray = true;
						break;
					}
				}

				if (!isInArray) {
					result[sizeResult] = arr1[i];
					sizeResult++;
				}

				break;
			}
		}
	}

	return result;
}

int* returnUnion(const int* arr1, unsigned size1, const int* arr2, unsigned size2, int* result = {}, unsigned sizeResult = 0) {
	sizeResult = size1;

	for (int i = 0; i < size1; i++) {
		result[i] = arr1[i];
	}

	for (int i = 0; i < size2; i++) {
		bool isInArray = false;

		for (int j = 0; j < size1; j++) {
			if (arr2[i] == arr1[j]) {
				isInArray = true;
				break;
			}

			if (!isInArray) {
				result[sizeResult] = arr2[i];
				sizeResult++;
			}
		}
	}

	return result;
}

int* mergeSortedArray(const int* arr1, unsigned size1, const int* arr2, unsigned size2, int* result = {}, unsigned sizeResult = 0) {
	int firstIdx = 0;
	int secondIdx = 0;
	int resultIdx = 0;

	while (firstIdx < size1 && secondIdx < size2) {
		if (arr1[firstIdx] < arr2[secondIdx]) {
			result[resultIdx] = arr1[firstIdx];
			resultIdx++;
			firstIdx++;
		}
		else {
			result[resultIdx] = arr2[secondIdx];
			resultIdx++;
			secondIdx++;
		}
	}

	while (firstIdx < size1) {
		result[resultIdx] = arr1[firstIdx];
		resultIdx++;
		firstIdx++;
	}

	while (secondIdx < size2) {
		result[resultIdx] = arr2[secondIdx];
		resultIdx++;
		secondIdx++;
	}

	return result;
}

bool areLinearlyDependent(const int* arr1, unsigned size1, const int* arr2, unsigned size2) {
	if (size1 != size2) {
		return false;
	}

	if (size1 == 0) {
		return true;
	}

	if (arr1[0] == 0) {
		if (arr2[0] != 0) return false;
	}
	else {
		double factor = arr2[0] / arr1[0];

		for (int i = 0; i < size1; i++) {
			if (arr1[i] == 0) {
				if (arr2[i] != 0) return false;
			}
			else {
				double currFactor = arr2[i] / arr1[i];

				if (factor != currFactor) return false;
			}
		}
	}

	return true;
}

void orderNumber(int* arr, unsigned size) {
	//a1 > a2 < a3 > a4 <(...)

	for (int i = 0; i < size - 1; i++) {
		if (i % 2 == 0) {
			if (arr[i] < arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
			}
		}
		else {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
			}
		}
	}
}

int* addOne(int* arr, unsigned size) {
	if (arr[0] > 0) {
		return arr;
	}

	for (int i = size - 1; i >= 0; i--) {
		if (i == size - 1) {
			arr[i]++;
		}

		if (arr[i] == 10) {
			arr[i] = 0;
			arr[i - 1]++;
		}
	}

	return arr;
}

int main() {
	int arr[MAX_SIZE];

	unsigned length;
	do {
		std::cin >> length;
	} while (!isValidLength(length));

	readArray(arr, length);

	printArray(addOne(arr, length), length);
}