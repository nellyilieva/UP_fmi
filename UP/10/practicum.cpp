#include <iostream>

bool isLetter(char ch) {
    return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z');
}

int countWords(const char* str) {
    if (!str) {
        return -1;
    }

    int count = 0;
    bool inWord = false;

    while (*str) {
        if (isLetter(*str)) {
            if (!inWord) {
                inWord = true;
                count++;
            }
        }
        else {
            inWord = false;
        }
        str++;
    }

    return count;
}


void changeToNullptr(int*& ptr) {
    ptr = nullptr;
}

void swapWithPointers(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


const int MAX_SIZE = 1024;

bool isLower(char ch) {
    return 'a' <= ch && ch <= 'z';
}

bool isUpper(char ch) {
    return 'A' <= ch && ch <= 'Z';
}

void makeLower(char& ch) {
    ch = ch + 32;
}

char digitToStr(int n) {
    return n + '0';
}

int strToDigit(char ch) {
    return ch - '0';
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

int countOfOccurances(const char* str, char ch) {
    if (!str) {
        return -1;
    }
    
    int count = 0;

    while (*str) {
        if (*str == ch) {
            count++;
        }

        str++;
    }

    return count;
}

void saveLowerLetter(const char* str, char* result) {
    if (!str) {
        return;
    }

    while (*str) {
        if (isLower(*str)) {
            *result = *str;
            result++;
        }
        str++;
    }

    *result = '\0';
}

void returnSubstring(const char* str, int beg, int end, char* result) {
    int size = myStrlen(str);

    if (!str) {
        return;
    }

    if (beg > size) {
        result[0] = '\0';
        return;
    }

    if (end > size) {
        end = size;
    }

    int sizeResult = end - beg + 1;

    str += beg;

    while (sizeResult != 0) {
        *result = *str;
        sizeResult--;

        result++;
        str++;
    }

    *result = '\0';
}

int compareLexicographically(const char* first, const char* second) {
    if (!first || !second) {
        return 2;
    }

    while (*first && *second) {
        if (*first < *second) {
            return -1;
        }

        if (*first > *second) {
            return 1;
        }

        first++;
        second++;
    }

    if (*first && !*second) {
        return 1;
    }

    if (!*first && *second) {
        return - 1;
    }

    return 0;
}

void replaceCharacters(char* str, char x, char a, char b) {
    if (!str) {
        return;
    }

    int size = myStrlen(str);
    int occurance = 1;

    for (int i = 0; i < size; i++) {
        if (str[i] == x) {
            occurance++;
            if (occurance % 2 == 0) {
                str[i] = a;
            }
            else {
                str[i] = b;
            }
        }
    }
}

void returnLongestPrefix(const char* first, const char* second, const char* third, char* result) {
    if (!first || !second || !third) {
        return;
    }

    while (*first && *second && *third) {
        if (*first == *second && *first == *third && *second == *third) {
            *result = *first;

            first++;
            second++;
            third++;

            result++;
        }
        else {
            break;
        }
    }

    *result = '\0';
}

void countOfNumbers(const char* str, char* result) {
    if (!str) {
        return;
    }

    int counts[10] = { 0 };

    for (int i = 0; str[i] != '\0'; i++) {
        counts[strToDigit(str[i])]++;
    }

    bool first = true;

    for (int i = 0; i <= 9; i++) {
        if (counts[i] > 0) {
            if (!first) {
                *result = ',';
                result++;
            }

            first = false;

            *result = digitToStr(counts[i]);
            result++;

            *result = 'x';
            result++;

            *result = digitToStr(i);
            result++;
        }
    }

    *result = '\0';
}

bool isPresentInString(const char* str, char ch) {
    while (*str) {
        if (*str == ch) {
            return true;
        }
        str++;
    }

    return false;
}

void occurInOne(const char* first, const char* second, char* result) {
    if (!first || !second) {
        return;
    }

    //bool arrays

    int index = 0;

    for (int i = 0; first[i] != '\0'; i++) {
        char ch = first[i];
        if (!isPresentInString(second, ch)) {
            result[index++] = ch;
        }
    }

    for (int i = 0; second[i] != '\0'; i++) {
        char ch = second[i];
        if (!isPresentInString(first, ch)) {
            result[index++] = ch;
        }
    }

    result[index] = '\0';
}

void deleteRepeating(const char* str, char* result) {
    if (!str || !result) {
        return;
    }

    const char* resultStart = result;

    while (*str) {
        if (!isPresentInString(resultStart, *str)) {
            *result = *str;
            result++;
        }
        str++;
    }

    *result = '\0';
}

int firstOccurance(const char* text, const char* word) {
    if (!text || !word) {
        return -1;
    }

    int textSize = myStrlen(text);
    int wordSize = myStrlen(word);

    if (wordSize > textSize) {
        return -1;
    }

    for (int i = 0; i <= textSize - wordSize; i++) {
        int currIdx = i;
        int idxWord = 0;

        while (text[currIdx] == word[idxWord] && idxWord != wordSize) {
            idxWord++;
            currIdx++;
        }

        if (idxWord == wordSize) {
            return i;
        }
    }

    return -1;
}

int countOccurancesString(const char* text, const char* str) {
    if (!text || !str) {
        return -1;
    }

    int textSize = myStrlen(text);
    int strSize = myStrlen(str);

    if (strSize > textSize) {
        return -1;
    }

    int count = 0;

    for (int i = 0; i <= textSize - strSize; i++) {
        int currIdx = i;
        int idxStr = 0;

        while (text[currIdx] == str[idxStr] && idxStr != strSize) {
            idxStr++;
            currIdx++;
        }

        if (idxStr == strSize) {
            count++;
        }
    }

    return count;
}

void replaceString(char* text, const char* substring) {
    if (!text || !substring) {
        return;
    }

    int textSize = myStrlen(text);
    int strSize = myStrlen(substring);

    if (strSize > textSize) {
        return;
    }

    for (int i = 0; text[i] != '\0'; i++) {
        if (isUpper(text[i])) {
            makeLower(text[i]);
        }
    }

    for (int i = 0; i <= textSize - strSize; i++) {
        int currIdx = i;
        int idxStr = 0;

        while (text[currIdx] == substring[idxStr] && idxStr != strSize) {
            idxStr++;
            currIdx++;
        }

        if (idxStr == strSize) {
            while (idxStr != 0) {
                text[currIdx - 1] = '*';
                currIdx--;
                idxStr--;
            }
        }
    }
}

void replaceWord(char* text, const char* word) {
    if (!text || !word) {
        return;
    }

    int textSize = myStrlen(text);
    int strSize = myStrlen(word);

    if (strSize > textSize) {
        return;
    }

    for (int i = 0; text[i] != '\0'; i++) {
        if (isUpper(text[i])) {
            makeLower(text[i]);
        }
    }

    for (int i = 0; i <= textSize - strSize; i++) {
        int currIdx = i;
        int idxStr = 0;

        while (text[currIdx] == word[idxStr] && idxStr != strSize) {
            idxStr++;
            currIdx++;
        }

        if (idxStr == strSize && !isLetter(text[currIdx])) {
            while (idxStr != 0) {
                text[currIdx - 1] = '*';
                currIdx--;
                idxStr--;
            }
        }
    }
}


int main() {
    int a = 7;
    int b = 5;

    swapWithPointers(&a, &b);

    //std::cout << countOfOccurances("aabbabc", 'a');

    const char* input = "abcbaa";
    char output[MAX_SIZE] = "Howdy! How are you? How was your day?";
    
    replaceWord(output, "how");

    std::cout << output;

    //std::cout << countOccurancesString("abcdabcabababc", "ba");
}