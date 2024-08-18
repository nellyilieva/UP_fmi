#include <iostream>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void toUpper(char& ch) {
    ch -= 32;
}

void toUnder(char& ch) {
    ch += 32;
}

void sort3(int& min, int& mid, int& max) {
    if (min > mid) {
        swap(min, mid);
    }

    if (min > max) {
        swap(min, max);
    }

    if (mid > max) {
        swap(mid, max);
    }
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void simplplifyFraction(int& a, int& b) {
    int divisor = gcd(a, b);

    a /= divisor;
    b /= divisor;
}

int findDigit(int n, int k) {
    for (int i = 0; i < k; i++) {
        n /= 10;
    }
    return n % 10;
}

int replaceDigit(int n, int k, int digit) {
    int oldDigit = findDigit(n, k);

    int mult = 1;
    for (int i = 0; i < k; i++) {
        mult *= 10;
    }

    n = n - oldDigit * mult + digit * mult;

    return n;
}

void swapDigit(int& n, int& m, int k) {
    int firstDigit = findDigit(n, k);
    int secondDigit = findDigit(m, k);

    n = replaceDigit(n, k, secondDigit);
    m = replaceDigit(m, k, firstDigit);
}




int main()
{
    int n = 1234;
    int k = 567;
    int p = 2;

    swapDigit(n, k, p);
    std::cout << n << " " << k << std::endl;
}