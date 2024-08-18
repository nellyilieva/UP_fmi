#include <iostream>

int sumOfNumbers(int n) {
    if (n == 1) {
        return 1;
    }

    return n + sumOfNumbers(n - 1);
}

bool isInNumber(int n, int k) {
    if (n == 0) {
        return false;
    }

    return (n % 10 == k) || isInNumber(n / 10, k);
}

int sumOfDigits(int n) {
    if (n == 0) {
        return 0;
    }

    return n % 10 + sumOfDigits(n / 10);
}

bool isMonotonicallyIncreasing(const int* arr, int size) {
    if (size <= 1) {
        return true;
    }

    return arr[0] < arr[1] && isMonotonicallyIncreasing(arr + 1, size - 1);
}

bool isPrimeRecursion(int n, int divisor) {
    if (divisor == 1) {
        return true;
    }

    return n % divisor != 0 && isPrimeRecursion(n, divisor - 1);
}

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }

    return isPrimeRecursion(n, n - 1);
}

int findPositionRecursion(int* arr, int left, int right, int n) {
    if (left > right) {
        return left;
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == n) {
        return mid;
    }

    if (arr[mid] > n) {
        return findPositionRecursion(arr, left, mid - 1, n);
    }
    else {
        return findPositionRecursion(arr, mid + 1, right, n);
    }
}

void addNumberInSortedArray(int* arr, int size, int n) {
    int idx = findPositionRecursion(arr, 0, size - 1, n);

    for (int i = size - 1; i >= idx; i--) {
        arr[i + 1] = arr[i];
    }

    arr[idx] = n;
}

int binomialCoeff(int m, int n) {
    if (n == 0 || m == 0 || n == m) {
        return 1;
    }

    return binomialCoeff(m - 1, n - 1) + binomialCoeff(m - 1, n);
}

int findIdx(const int* arr, int size, int idx) {
    if (idx < 1 || idx >= size - 1) {
        return -1;
    }

    if (arr[idx] > (arr[idx - 1] + arr[idx + 1] / 2)) {
        return idx;
    }

    return findIdx(arr, size, idx - 1);
}

int idxBiggest(const int* arr, int size) {
    return findIdx(arr, size, size - 2);
}

bool isPalindrom(int n) {
    int copy = n;
    int reversed = 0;

    while (copy != 0) {
        int lastDigit = copy % 10;
        reversed = reversed * 10 + lastDigit;
        copy /= 10;
    }

    return n == reversed;
}

bool isPerfectSquare(int n) {
    for (int i = 1; i * i <= n; i++) {
        if ((n % i == 0) && (n / i == i)) {
            return true;
        }
    }

    return false;
}

void printNumbers(int a, int b) {
    for (int i = a; i <= b; i++) {
        if (isPalindrom(i)) {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;

    for (int i = a; i <= b; i++) {
        if (isPrime(i)) {
            std::cout <<  i << " ";
        }
    }

    std::cout << std::endl;

    for (int i = a; i <= b; i++) {
        if (isPerfectSquare(i)) {
            std::cout << i << " ";
        }
    }
}

bool isLeapYear(int n) {
    if (n % 4 == 0) {
        if (n % 100 == 0) {
            if (n % 400 == 0) {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

void leapYearRecursion(int year, int n) {
    if (n <= 0) {
        return;
    }

    while (!isLeapYear(year)) {
        year++;
    }

    std::cout << year << " ";

    leapYearRecursion(year + 1, n - 1);
}

void printNextLeapYears(int n) {
    return leapYearRecursion(2024 + 1, n);
}

int main() {
    int n;
    std::cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cout << idxBiggest(arr, n);
}