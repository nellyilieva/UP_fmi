#include <iostream>

int* dividedElements(const int* arr, int size,int& resultSize) {
	int* tempResult = new int[size];
	int count = 0;

	for (int i = 0; i < size; i++) {
		bool isDivisible = false;

		if (i > 0 && arr[i] % arr[i - 1] == 0) {
			isDivisible = true;
		}

		if (i < size - 1 && arr[i] % arr[i + 1] == 0) {
			isDivisible = true;
		}

		if (isDivisible) {
			tempResult[count] = arr[i];
			count++;
		}
	}

	int* result = new int[count];

	for (int i = 0; i < count; i++) {
		result[i] = tempResult[i];
	}

	resultSize = count;

	delete[] tempResult;

	return result;
}

bool isLower(char ch) {
	return 'a' <= ch && ch <= 'z';
}

bool isUpper(char ch) {
	return 'A' <= ch && ch <= 'Z';
}

char* concatLowerUpper(const char* first, int size1, const char* second, int size2, int& resultSize) {
	if (!first || !second) {
		return nullptr;
	}

	char* tempResult = new char[size1 + size2 + 1];
	int idx = 0;

	while (*first) {
		if (isLower(*first)) {
			tempResult[idx] = *first;
			idx++;
		}
		first++;
	}

	while (*second) {
		if (isUpper(*second)) {
			tempResult[idx] = *second;
			idx++;
		}
		second++;
	}

	tempResult[idx] = '\0';

	resultSize = idx;

	char* result = new char[resultSize + 1];

	for (int i = 0; i < resultSize; i++) {
		result[i] = tempResult[i];
	}

	result[resultSize] = '\0';

	delete[] tempResult;

	return result;
}

char* uniqueCharacters(const char* str, int size, int& resultSize) {
	if (!str) {
		return nullptr;
	}

	char* tempResult = new char[size + 1];

	int count = 0;

	for (int i = 0; i < size; i++) {
		bool isUnique = true;

		for (int j = 0; j < size; j++) {
			if (j != i && str[i] == str[j]) {
				isUnique = false;
				break;
			}
		}

		if (isUnique) {
			tempResult[count] = str[i];
			count++;
		}
	}

	tempResult[count] = '\0';

	resultSize = count;

	char* result = new char[resultSize + 1];

	for (int i = 0; i < resultSize; i++) {
		result[i] = tempResult[i];
	}

	result[resultSize] = '\0';

	delete[] tempResult;

	return result;
	
}

char* addLetter(const char* str, int length, const int* arr, int size, char ch, int& resultSize) {
	if (!str) {
		return nullptr;
	}

	resultSize = length + size;

	char* result = new char[resultSize + 1];

	int idxArr = 0;
	int idxStr = 0;

	for (int i = 0; i < resultSize; i++) {
		if (idxArr < size && i == arr[idxArr] + idxArr) {
			result[i] = ch;
			idxArr++;
		}
		else {
			result[i] = str[idxStr];
			idxStr++;
		}

	}

	result[resultSize] = '\0';

	return result;
}


int main() {

	int arr[] = {3, 13, 18};
	int resultSize;
	char* result = addLetter("Hi here nice o mee you.", 24, arr, 3, 't', resultSize);

	std::cout << result;

	/*for (int i = 0; i < resultSize; i++) {
		std::cout << result[i] << " ";
	}*/

	delete[] result;

	//1
	/*int n;
	std::cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		int a;
		std::cin >> a;
		arr[i] = a;
	}

	for (int i = n - 1; i >= 0; i--) {
		std::cout << arr[i] << " ";
	}

	delete[] arr;*/

	//2
	/*int size1, size2, k;
	std::cin >> size1;
	int* arr1 = new int[size1];

	for (int i = 0; i < size1; i++) {
		int a;
		std::cin >> arr1[i];
	}

	std::cin >> size2;
	int* arr2 = new int[size2];

	for (int i = 0; i < size2; i++) {
		int a;
		std::cin >> arr2[i];
	}

	std::cin >> k;

	int count = 0;
	int* tempResult = new int[size1 + size2];

	for (int i = 0; i < size1; i++) {
		if (arr1[i] % k == 0) {
			tempResult[count] = arr1[i];
			count++;
		}
	}

	for (int i = 0; i < size2; i++) {
		if (arr2[i] % k == 0) {
			tempResult[count] = arr2[i];
			count++;
		}
	}

	int* result = new int[count];

	for (int i = 0; i < count; i++) {
		result[i] = tempResult[i];
	}

	std::cout << count << std::endl;
	for (int i = 0; i < count; ++i) {
		std::cout << result[i] << " ";
	}


	delete[] arr1;
	delete[] arr2;
	delete[] tempResult;
	delete[] result;*/

	//3
	/*int size, k;
	std::cin >> size;

	int* arr = new int[size];

	for (int i = 0; i < size; i++) {
		int a;
		std::cin >> arr[i];
	}

	std::cin >> k;

	int* result = new int[size];

	for (int i = 0; i < size; i++) {
		int idx = i + k;
		if (idx >= size) {
			idx -= size;
		}
		result[idx] = arr[i];
	}

	for (int i = 0; i < size; i++) {
		std::cout << result[i] << " ";
	}

	delete[] arr;
	delete[] result;*/
}