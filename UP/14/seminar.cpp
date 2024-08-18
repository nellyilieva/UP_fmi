#include <iostream>

int factoriel(int n) {
    if (n == 0) {
        return 1;
    }

    return n * factoriel(n - 1);
}

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int pow(int n, int k) {
    if (k == 0) {
        return 1;
    }

    return n * pow(n, k - 1);
}

int sumOfElements(const int* arr, int size) {
    if (size == 0) {
        return 0;
    }

    return arr[0] + sumOfElements(arr + 1, size - 1);
}

bool inArrayLinearSearch(const int* arr, int size, int n) {
    if (size == 0) {
        return false;
    }

    return *arr == n || inArrayLinearSearch(arr + 1, size - 1, n);
}

int inArrayBinarySearch(const int* arr, int size, int n) {
    if (size == 0) {
        return false;
    }

    int mid = size / 2;


    if (arr[mid] == n) {
        return mid;
    }

    if (n < arr[mid]) {
        return inArrayBinarySearch(arr, mid, n);
    }
    else {
        return inArrayBinarySearch(arr + mid + 1, size - mid, n);
    }
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

bool isPalindromRecursion(const char* str, int size) {
    if (size <= 1) {  // we have reached the middle of str or str is empty
        return true;
    }

    return str[0] == str[size - 1] && isPalindromRecursion(str + 1, size - 2);
}

bool isPalindrom(const char* str) {
    return isPalindromRecursion(str, myStrlen(str));
}

bool isPrefix(const char* text, const char* str) {
    if (*str == '\0') {
        return true;
    }

    return *text == *str && isPrefix(text + 1, str + 1);
}

bool inText(const char* text, const char* str) {
    if (*text == '\0') {
        return *str == '\0';
    }

    return isPrefix(text, str) || inText(text, str + 1);
}

int main() {
    
}