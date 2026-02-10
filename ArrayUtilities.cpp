#include "ArrayUtilities.h"
#include <cstdlib>
#include <ctime>

// ========================== Basic Input & Random Utilities ==========================
int ReadNumber(string Message) {
    int number;
    do {
        cout << Message;
        cin >> number;
    } while (number <= 0);
    return number;
}

int RandomNumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}

char RandomChar(enCharType char_type) {
    switch (char_type) {
    case SmallLetter: return char(RandomNumber(97, 122));
    case CapitalLetter: return char(RandomNumber(65, 90));
    case SpecialChar: return char(RandomNumber(33, 47));
    case Digit: return char(RandomNumber(48, 57));
    default: return '\0';
    }
}

// ========================== Array Creation & Manipulation ==========================
int* CreateRandomArray(int length) {
    int* array = new int[length];
    for (int i = 0; i < length; i++) array[i] = RandomNumber(1, 100);
    return array;
}

int* CopyArray(const int* array, int length_array) {
    int* copy_array = new int[length_array];
    for (int i = 0; i < length_array; i++) copy_array[i] = array[i];
    return copy_array;
}

int* ReverseArray(const int* array, int length_array) {
    int* reverse_array = new int[length_array];
    for (int i = 0; i < length_array; i++) reverse_array[i] = array[length_array - i - 1];
    return reverse_array;
}

int* ShuffleArray(const int* array, int length_array) {
    int* shuffle_array = new int[length_array];
    for (int i = 0; i < length_array; i++) shuffle_array[i] = array[i];
    for (int i = 0; i < length_array - 1; i++) {
        int j = RandomNumber(i, length_array - 1);
        swap(shuffle_array[i], shuffle_array[j]);
    }
    return shuffle_array;
}

int* SumTwoArrayElements(const int* array1, const int* array2, int length) {
    int* sum_array = new int[length];
    for (int i = 0; i < length; i++) sum_array[i] = array1[i] + array2[i];
    return sum_array;
}

// ========================== Array Analysis & Checks ==========================
stStatus GetArrayStatus(const int* array, int length_array) {
    stStatus Status{};
    if (length_array == 0) return Status;
    Status.max_number = Status.min_number = Status.sum_number = array[0];
    for (int i = 1; i < length_array; i++) {
        if (array[i] > Status.max_number) Status.max_number = array[i];
        if (array[i] < Status.min_number) Status.min_number = array[i];
        Status.sum_number += array[i];
    }
    Status.avg_number = double(Status.sum_number) / length_array;
    return Status;
}

enIsPrime CheckIsPrime(int number) {
    if (number <= 1) return NotPrime;
    for (int i = 2; i * i <= number; i++) if (number % i == 0) return NotPrime;
    return Prime;
}

enIsEvenOrOdd CheckIsEvenOrOdd(int number) {
    return (number % 2 == 0) ? Even : Odd;
}

bool IsPalindrome(int* array, int length) {
    for (int i = 0; i < length / 2; i++) if (array[i] != array[length - i - 1]) return false;
    return true;
}

// ========================== Array Filtering & Searching ==========================
enSearch CheckIsFound(const int* array, int length_array, int search_number) {
    for (int i = 0; i < length_array; i++) if (array[i] == search_number) return Found;
    return NotFound;
}

int GetPositionItem(const int* array, int length_array, int search_number) {
    for (int i = 0; i < length_array; i++) if (array[i] == search_number) return i;
    return -1;
}

int* ArrayIsPrime(int* array, int length, int& prime_count) {
    int* array_prime = nullptr;
    prime_count = 0;
    for (int i = 0; i < length; i++) {
        if (CheckIsPrime(array[i]) == Prime) {
            int* temp = new int[prime_count + 1];
            for (int j = 0; j < prime_count; j++) temp[j] = array_prime[j];
            temp[prime_count] = array[i];
            delete[] array_prime;
            array_prime = temp;
            prime_count++;
        }
    }
    return array_prime;
}

int* ArrayIsEven(int* array, int length, int& even_count) {
    int* array_even = nullptr;
    even_count = 0;
    for (int i = 0; i < length; i++) {
        if (CheckIsEvenOrOdd(array[i]) == Even) {
            int* temp = new int[even_count + 1];
            for (int j = 0; j < even_count; j++) temp[j] = array_even[j];
            temp[even_count] = array[i];
            delete[] array_even;
            array_even = temp;
            even_count++;
        }
    }
    return array_even;
}

int* ArrayIsOdd(int* array, int length, int& odd_count) {
    int* array_odd = nullptr;
    odd_count = 0;
    for (int i = 0; i < length; i++) {
        if (CheckIsEvenOrOdd(array[i]) == Odd) {
            int* temp = new int[odd_count + 1];
            for (int j = 0; j < odd_count; j++) temp[j] = array_odd[j];
            temp[odd_count] = array[i];
            delete[] array_odd;
            array_odd = temp;
            odd_count++;
        }
    }
    return array_odd;
}

int* DistinctArray(int* array, int length, int& distinct_count) {
    int* array_distinct = nullptr;
    distinct_count = 0;
    for (int i = 0; i < length; i++) {
        if (CheckIsFound(array_distinct, distinct_count, array[i]) == NotFound) {
            int* temp = new int[distinct_count + 1];
            for (int j = 0; j < distinct_count; j++) temp[j] = array_distinct[j];
            temp[distinct_count] = array[i];
            delete[] array_distinct;
            array_distinct = temp;
            distinct_count++;
        }
    }
    return array_distinct;
}

// ========================== Key & String Utilities ==========================
string BlockChar(int length_block) {
    string block_char = "";
    for (int i = 0; i < length_block; i++) block_char += RandomChar(CapitalLetter);
    return block_char;
}

string KeyGeneration(int length_block, int count_block) {
    string key_generation = "";
    for (int i = 0; i < count_block; i++) {
        key_generation += BlockChar(length_block);
        if (i < count_block - 1) key_generation += "-";
    }
    return key_generation;
}

string* ArrayKeyGen(int length_block, int count_block, int length_array) {
    string* array_key_gen = new string[length_array];
    for (int i = 0; i < length_array; i++) array_key_gen[i] = KeyGeneration(length_block, count_block);
    return array_key_gen;
}

// ========================== Dynamic Input & Printing ==========================
bool QuestionToAddNumber() {
    int choice;
    cout << "Do you want to add more numbers? [0]No, [1]Yes: ";
    cin >> choice;
    return choice == 1;
}

void AddNumberToArray(int*& array, int& length_array) {
    int number = ReadNumber("Please enter number: ");
    int* new_array = new int[length_array + 1];
    for (int i = 0; i < length_array; i++) new_array[i] = array[i];
    new_array[length_array] = number;
    delete[] array;
    array = new_array;
    length_array++;
}

void FillArray(int*& array, int& length_array) {
    while (QuestionToAddNumber()) AddNumberToArray(array, length_array);
}

void PrintArray(const int* array, int length_array, string name_array) {
    cout << name_array;
    for (int i = 0; i < length_array; i++) cout << "\t" << array[i];
    cout << endl;
}

void PrintArrayElement(string* array, int length_array, string name_array) {
    cout << name_array << endl;
    for (int i = 0; i < length_array; i++) cout << "Array [" << i + 1 << "] : " << array[i] << endl;
}

void PrintIsFound(const int* array, int length_array, int number_search, int position_item) {
    if (CheckIsFound(array, length_array, number_search) == Found) {
        cout << "Number found: " << number_search
            << " at position " << position_item
            << " (Order: " << position_item + 1 << ")" << endl;
    }
    else {
        cout << "Number " << number_search << " not found." << endl;
    }
}

// ========================== Math Utilities ==========================
float AbsoluteNumber(float number) { return (number < 0) ? -number : number; }
int RoundNumber(float number) { return (number >= 0) ? int(number + 0.5) : int(number - 0.5); }
int FloorNumber(float number) { int i = int(number); return (number < 0 && number != i) ? i - 1 : i; }
int CeilNumber(float number) { int i = int(number); return (number > 0 && number != i) ? i + 1 : i; }
