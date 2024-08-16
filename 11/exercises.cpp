#include <iostream>

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

bool isDigit(char ch) {
    return '0' <= ch && ch <= '9';
}

int getDigitsCount(const char* str) {
    if (!str) {
        return 0;
    }

    int count = 0;

    while (*str) {
        if (isDigit(*str)) {
            count++;
        }

        str++;
    }

    return count;
}

int getNumbersCount(const char* str) {
    if (!str) {
        return 0;
    }

    int count = 0;

    while (*str) {
        if (isDigit(*str) && !isDigit(*(str + 1))) {
            count++;
        }
        str++;
    }

    return count;
}

char* censor(const char* str) {
    if (!str) {
        return nullptr;
    }

    int resultSize = myStrlen(str) - getDigitsCount(str) + getNumbersCount(str);
    char* result = new char[resultSize + 1];

    int idx = 0;

    while (*str) {
        if (!isDigit(*str)) {
            result[idx] = *str;
            idx++;
        }
        else if (!isDigit(*(str + 1))) {
            result[idx] = '*';
            idx++;
        }

        str++;
    }

    result[idx] = '\0';
    return result;
}



int main() {
    char* censoredString = censor("0A1B23C12345a5");
    std::cout << censoredString;
    delete[] censoredString;

    int rows, cols;
    std::cin >> rows >> cols;



    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];

        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    int rows, cols, height;
    std::cin >> rows >> cols >> height;



    int*** cube = new int** [height];
    for (int i = 0; i < height; i++) {
        cube[i] = new int* [rows];
        for (int j = 0; j < rows; j++) {
            cube[i][j] = new int[cols];
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < rows; j++) {
            delete[] cube[i][j];
        }
        delete[] cube[i];
    }
    delete[] cube;
}