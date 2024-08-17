#include <iostream>

int** createMatrix(int rows) {
	int colls;
	std::cin >> colls;

	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[colls] {0};

		for (int j = 0; j < colls; j++) {
			std::cin >> matrix[i][j];
		}
	}
	return matrix;
}

void freeMatrix(int** matrix, int rows) {
	for (int i = 0; i < rows; i++) {
		delete matrix[i];
	}
	delete[] matrix;
}

void printMatrix(int** matrix, int rows, int colls) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colls; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void swap(int*& first, int*& second)
{
	int* temp = first;
	first = second;
	second = temp;
}

int myStrlen(const char* str) {
	if (!str) {
		return -1;
	}

	int count = 0;

	while (*str) {
		count++;
		str++;
	}

	return count;
}


int** deleteRow(int** matrix, int rows, int colls, int idx, int& resultRows) {
	if (idx < 0 || idx >= rows) {
		return nullptr;
	}

	resultRows = rows - 1;

	int** result = new int* [resultRows];
	for (int i = 0; i < resultRows; i++) {
		result[i] = new int[colls];
	}

	int resultRowIdx = 0;
	for (int i = 0; i < rows; i++) {
		if (i != idx) {
			for (int j = 0; j < colls; j++) {
				result[resultRowIdx][j] = matrix[i][j];
			}

			resultRowIdx++;
		}
	}
	return result;
}

int** deleteColl(int** matrix, int rows, int colls, int idx, int& resultColls) {
	if (idx < 0 || idx >= colls) {
		return nullptr;
	}

	resultColls = colls - 1;

	int** result = new int* [rows];
	for (int i = 0; i < rows; i++) {
		result[i] = new int[resultColls];
	}


	for (int i = 0; i < rows; i++) {
		int resultColIdx = 0;

		for (int j = 0; j < colls; j++) {
			if (j != idx) {
				result[i][resultColIdx] = matrix[i][j];
				resultColIdx++;
			}
		}
	}
	return result;
}

int** transposeMatrix(int** matrix, int rows, int colls, int& resultRows, int& resultColls) {
	resultRows = colls;
	resultColls = rows;

	int** result = new int* [resultRows];
	for (int i = 0; i < resultRows; i++) {
		result[i] = new int[resultColls];
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colls; j++) {
			result[j][i] = matrix[i][j];
		}
	}

	return result;
}

int main() {
	int rows = 3;
	int colls = 3;

	int** matrix = createMatrix(rows);

	int resultRows;
	int resultColls;

	int** result = transposeMatrix(matrix, rows, colls, resultRows, resultColls);

	printMatrix(result, resultRows, resultColls);

	freeMatrix(result, resultRows);
}