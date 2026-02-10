#ifndef ARRAY_UTILITIES_H
#define ARRAY_UTILITIES_H

#include <iostream>
#include <string>
using namespace std;

// ========================== Structs & Enums ==========================
struct stStatus {
    int max_number;
    int min_number;
    int sum_number;
    double avg_number;
};

enum enIsPrime { NotPrime, Prime };
enum enIsEvenOrOdd { Even, Odd };
enum enSearch { NotFound, Found };
enum enCharType { SmallLetter, CapitalLetter, SpecialChar, Digit };

// ========================== Function Declarations ====================

// Basic Input & Random Utilities
int ReadNumber(string Message);
int RandomNumber(int from, int to);
char RandomChar(enCharType char_type);

// Array Creation & Manipulation
int* CreateRandomArray(int length);
int* CopyArray(const int* array, int length_array);
int* ReverseArray(const int* array, int length_array);
int* ShuffleArray(const int* array, int length_array);
int* SumTwoArrayElements(const int* array1, const int* array2, int length);

// Array Analysis & Checks
stStatus GetArrayStatus(const int* array, int length_array);
enIsPrime CheckIsPrime(int number);
enIsEvenOrOdd CheckIsEvenOrOdd(int number);
bool IsPalindrome(int* array, int length);

// Array Filtering & Searching
enSearch CheckIsFound(const int* array, int length_array, int search_number);
int GetPositionItem(const int* array, int length_array, int search_number);
int* ArrayIsPrime(int* array, int length, int& prime_count);
int* ArrayIsEven(int* array, int length, int& even_count);
int* ArrayIsOdd(int* array, int length, int& odd_count);
int* DistinctArray(int* array, int length, int& distinct_count);

// Key & String Utilities
string BlockChar(int length_block);
string KeyGeneration(int length_block, int count_block);
string* ArrayKeyGen(int length_block, int count_block, int length_array);

// Dynamic Input & Printing
bool QuestionToAddNumber();
void AddNumberToArray(int*& array, int& length_array);
void FillArray(int*& array, int& length_array);
void PrintArray(const int* array, int length_array, string name_array);
void PrintArrayElement(string* array, int length_array, string name_array);
void PrintIsFound(const int* array, int length_array, int number_search, int position_item);

// Math Utilities
float AbsoluteNumber(float number);
int RoundNumber(float number);
int FloorNumber(float number);
int CeilNumber(float number);

#endif
