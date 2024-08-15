#include <iostream>

size_t myStrlen(const char* str) {
    if (!str) {
        return 0;
    }

    size_t result = 0;

    while (*str) {
        result++;
        str++;
    }

    return result;
}

// - first < second
// 0 first == second
// + first > second
int myStrCmp(const char* first, const char* second) {
    if (!first || !second) {
        return -1;
    }

    while (*first && *first == *second) {
        first++;
        second++;
    }

    return *first - *second;
}

void myStrCpy(const char* source, char* destination) {
    if (!source || !destination) {
        return;
    }

    while (*source) {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0';
}

void myStrCat(const char* source, char* destination) {
    if (!source || !destination) {
        return;
    }

    size_t size = myStrlen(destination);
    destination += size;  //we move the pointer to the end of destination (the null terminator)
    myStrCpy(source, destination);
}

bool isDigit(char ch) {
    return '0' <= ch && ch <= '9';
}

int stringToNumber(const char* str) {
    if (!str) {
        return -1;
    }

    int result = 0;

    while (*str) {
        char ch = *str;
        if (!isDigit(ch)) {
            return -1;
        }

        result *= 10;
        result += (ch - '0');
        str++;
    }

    return result;
}

int getCharOccurrencesCount(const char* str, char ch) {
    if (!str) {
        return -1;
    }

    int count = 0;

    while (*str) {
        char currChar = *str;
        if (currChar == ch) {
            count++;
        }
        str++;
    }

    return count;
}

bool isPrefix(const char* str, const char* prefix) {
    if (!str || !prefix) {
        return false;
    }

    while (*prefix) {
        if (*str != *prefix) {
            return false;
        }

        str++;
        prefix++;
    }

    return true;
}

bool searchInText(const char* text, const char* str) {
    if (!text || !str) {
        return false;
    }

    size_t textSize = myStrlen(text);
    size_t strSize = myStrlen(str);

    while (strSize <= textSize) {
        if (isPrefix(text, str)) {
            return true;
        }

        text++;
        textSize--;
    }

    return false;
}

int main() {

    std::cout << myStrCmp("apples", "apple");

}