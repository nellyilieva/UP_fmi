#include <iostream>

const unsigned LENGTH = 4;

bool containsDigit(unsigned num, unsigned digit) {
    if (digit > 9) {
        return false;
    }

    if (num == digit) {
        return true;
    }

    while (num != 0) {
        unsigned lastDigit = num % 10;
        if (lastDigit == digit) {
            return true;
        }

        num /= 10;
    }

    return false;
}

bool areDifferentDigits(unsigned n) {
    if (n == 0) {
        return true;
    }

    while (n != 0) {
        unsigned lastDigit = n % 10;
        if (containsDigit(n /= 10, lastDigit)) {
            return false;
        }
    }
    return true;
}

bool isValidLength(unsigned n) {
    unsigned numLength = 0;

   while (n != 0) {
        numLength++;
        n /= 10;
    }

    return numLength == LENGTH;
}

bool isValidInput(unsigned n) {
    return isValidLength(n) && areDifferentDigits(n);
}

void readInput(unsigned& guess) {
    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
    } while (!isValidInput(guess));

} //!!!!!!

unsigned countBulls(unsigned num, unsigned guess) {
    unsigned result = 0;

    while (num != 0) {
        unsigned lastDigitNum = num % 10;
        unsigned lastDigitGuess = guess % 10;

        if (lastDigitGuess == lastDigitNum) {
            result++;
        }

        guess /= 10;
        num /= 10;
    }

    return result;
}

unsigned countBullsAndCows(unsigned num, unsigned guess) {
    unsigned result = 0;

    while (num != 0) {
        unsigned lastDigit = num % 10;
        result += containsDigit(guess, lastDigit);
        num /= 10;
    }

    return result;
}

int main()
{
    /*Bulls = correct code, correct position.
    Cows = correct code, wrong position.*/

    unsigned toGuess;
    readInput(toGuess);

    unsigned guess, bulls, cows;
    do {
        readInput(guess);

        bulls = countBulls(guess, toGuess);
        cows = countBullsAndCows(guess, toGuess) - bulls;

        std::cout << "Bulls: " << bulls << " Cows: " << cows << std::endl;
    } while (bulls != LENGTH);
}