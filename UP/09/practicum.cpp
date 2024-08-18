#include <iostream>

//Linear Equation Solver
//Gaussian Elimination

const int N = 2;
const int M = 3;
const int P = 2;

void printArr(double arr[], unsigned size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void printMatrix(int arr[][M], unsigned rows, unsigned cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void divideRowBy(double arr[], unsigned cols, double num) {
	for (int i = 0; i < cols; i++) {
		arr[i] /= num;
	}
}

void substractFromRow(double rowToSubstractFrom[], double rowToSubstract[], double coef, unsigned cols) {
	for (int i = 0; i < cols; i++) {
		rowToSubstractFrom[i] -= (rowToSubstract[i] * coef);
	}
}

void substractFromOtherRows(double matrix[][3], unsigned rows, unsigned cols, int currRow) {
	for (int i = 0; i < rows; i++) {
		if (i == currRow) {
			continue;
		}
		substractFromRow(matrix[i], matrix[currRow], matrix[i][currRow], cols);
	}
}

void collectResults(double matrix[][3], unsigned rows, unsigned cols, double results[]) {
	for (int i = 0; i < rows; i++) {
		results[i] = matrix[i][cols - 1];
	}
}

void gauss(double matrix[][3], unsigned n, double result[]) {
	unsigned rows = n;
	unsigned cols = n + 1;

	for (int i = 0; i < rows; i++) {
		divideRowBy(matrix[i], cols, matrix[i][i]);
		substractFromOtherRows(matrix, rows, cols, i);
	}

	collectResults(matrix, rows, cols, result);
}



int smallestElement(int matrix[][N]) {
	int result = matrix[0][0];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int currElement = matrix[i][j];

			if (currElement < result) {
				result = currElement;
			}
		}
	}

	return result;
}

void printDiagonals(int matrix[][N]) {
	for (int i = 0; i < N; i++) {
		std::cout << matrix[i][i] << " ";
	}

	std::cout << std::endl;

	for (int i = 0; i < N; i++) {
		std::cout << matrix[i][N - i - 1] << " ";
	}
}

void printZigZag(int matrix[][N], int rows, int colls = N) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colls; j++) {
			if (i % 2 == 0) {
				std::cout << matrix[i][j] << " ";
			}
			else {
				std::cout << matrix[i][colls - j - 1] << " ";
			}
		}
		std::cout << std::endl;
	}
}

bool isTriangleMatrix(int matrix[][N]) {
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (matrix[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}

void transposeMatrix(int matrix[][M]) {
	for (int i = 0; i < M; i++) {
		for (int j = i + 1; j < M; j++) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;

		}
	}
}

bool isMagicSquare(int matrix[][N]) {
	int sum = 0;

	for (int i = 0; i < N; i++) {
		sum += matrix[0][i];
	}

	int sumDiagonal = 0;
	int sumSecDiagonal = 0;

	for (int i = 0; i < N; i++) {
		int rowSum = 0;
		int colSum = 0;

		for (int j = 0; j < N; j++) {
			rowSum += matrix[i][j];
			colSum += matrix[j][i];
		}

		if (rowSum != sum || colSum != sum) {
			return false;
		}

		sumDiagonal += matrix[i][i];
		sumSecDiagonal += matrix[i][N - i - 1];
	}

	return true;
}

void sumTwoMatrix(int first[][N], int second[][N], int rows, int colls = N) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colls; j++) {
			first[i][j] += second[i][j];
		}
	}
}

void multiplyWithNumber(int matrix[][N], int n, int rows, int colls = N) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colls; j++) {
			matrix[i][j] *= n;
		}
	}
}

void multiplyMatrix(int first[][M], int second[][P], int result[][P], int n, int m, int p) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			result[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < p; k++) {
				result[i][k] += first[i][j] * second[j][k];
			}
		}
	}
}

void printSpiral(int matrix[][M], int rows, int colls = M) {
	int top = 0;
	int bottom = rows - 1;
	int left = 0;
	int right = colls - 1;

	while (top <= bottom && left <= right) {
		for (int i = left; i <= right; i++) {
			std::cout << matrix[top][i] << " ";
		}
		top++;

		for (int i = top; i <= bottom; i++) {
			std::cout << matrix[i][right] << " ";
		}
		right--;

		if (top <= bottom) {
			for (int i = right; i >= left; i--) {
				std::cout << matrix[bottom][i] << " ";
			}
			bottom--;
		}

		if (left <= right) {
			for (int i = bottom; i >= top; i--) {
				std::cout << matrix[i][left] << " ";
			}
			left++;
		}
	}
}

void printRightFlipped(int matrix[][M], int rows = M, int colls = M) {
	transposeMatrix(matrix);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < M / 2; j++) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[i][M - j - 1];
			matrix[i][M - j - 1] = temp;
		}
	}
}

int main() {

	int first[M][M] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	int second[M][P] = { {9, 6}, {4, 15}, {4, 8} };
	int result[N][P];

	/*multiplyMatrix(first, second, result, N, M, P);
	printMatrix(result, N, P);*/

	printRightFlipped(first, 3, 3);
	printMatrix(first, M, M);
}