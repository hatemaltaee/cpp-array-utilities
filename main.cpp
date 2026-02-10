#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "ArrayUtilities.h"

using namespace std;

int main() {
    srand((unsigned)time(nullptr));

    cout << "================= PROGRAM سؤSTART =================\n";

    // 1️⃣ Array Size
    int length = ReadNumber("\nEnter array size: ");

    // 2️⃣ Create Arrays
    int* array1 = CreateRandomArray(length);
    int* array2 = CreateRandomArray(length);

    int* sumArray = SumTwoArrayElements(array1, array2, length);
    int* copyArray = CopyArray(array1, length);
    int* reverseArray = ReverseArray(array1, length);
    int* shuffleArray = ShuffleArray(array1, length);

    // 3️⃣ Analyze Arrays
    int primeCount = 0, evenCount = 0, oddCount = 0;
    int* primeArray = ArrayIsPrime(array1, length, primeCount);
    int* evenArray = ArrayIsEven(array1, length, evenCount);
    int* oddArray = ArrayIsOdd(array1, length, oddCount);

    stStatus status = GetArrayStatus(array1, length);

    // 4️⃣ Display Arrays
    cout << "\n=========== ARRAYS ===========" << endl;
    PrintArray(array1, length, "Array 1        : ");
    PrintArray(array2, length, "Array 2        : ");
    PrintArray(sumArray, length, "Sum Array      : ");
    PrintArray(copyArray, length, "Copy Array     : ");
    PrintArray(reverseArray, length, "Reverse Array  : ");
    PrintArray(shuffleArray, length, "Shuffle Array  : ");

    cout << "\n=========== FILTERED =========" << endl;
    PrintArray(primeArray, primeCount, "Prime Numbers  : ");
    PrintArray(evenArray, evenCount, "Even Numbers   : ");
    PrintArray(oddArray, oddCount, "Odd Numbers    : ");

    cout << "\n=========== STATISTICS =======" << endl;
    cout << "Max Number  : " << status.max_number << endl;
    cout << "Min Number  : " << status.min_number << endl;
    cout << "Sum         : " << status.sum_number << endl;
    cout << "Average     : " << status.avg_number << endl;
    cout << "Odd Count   : " << oddCount << endl;
    cout << "Even Count  : " << evenCount << endl;
    cout << "Prime Count : " << primeCount << endl;

    // 5️⃣ Search
    int searchNumber = ReadNumber("\nEnter number to search: ");
    int position = GetPositionItem(array1, length, searchNumber);
    PrintIsFound(array1, length, searchNumber, position);

    // 6️⃣ User Array
    int* userArray = nullptr;
    int userLength = 0;

    cout << "\n=========== USER ARRAY =======" << endl;
    FillArray(userArray, userLength);
    PrintArray(userArray, userLength, "User Array     : ");

    int* reverseUserArray = ReverseArray(userArray, userLength);
    PrintArray(reverseUserArray, userLength, "Reversed Array : ");

    cout << "\nPalindrome Check: ";
    cout << (IsPalindrome(userArray, userLength) ? "YES ✅" : "NO ❌") << endl;

    int distinctCount = 0;
    int* distinctArray = DistinctArray(userArray, userLength, distinctCount);
    PrintArray(distinctArray, distinctCount, "Distinct Array : ");

    // Count odd, even, prime in user array
    int userOddCount = 0, userEvenCount = 0, userPrimeCount = 0;
    ArrayIsOdd(userArray, userLength, userOddCount);
    ArrayIsEven(userArray, userLength, userEvenCount);
    ArrayIsPrime(userArray, userLength, userPrimeCount);

    cout << "\nUser Array Counts:" << endl;
    cout << "Odd Numbers   : " << userOddCount << endl;
    cout << "Even Numbers  : " << userEvenCount << endl;
    cout << "Prime Numbers : " << userPrimeCount << endl;

    // 7️⃣ Math Utilities
    float num;
    cout << "\nEnter a float number: ";
    cin >> num;
    cout << "\n=========== MATH UTILS ========" << endl;
    cout << "Absolute : " << AbsoluteNumber(num) << endl;
    cout << "Round    : " << RoundNumber(num) << endl;
    cout << "Floor    : " << FloorNumber(num) << endl;
    cout << "Ceil     : " << CeilNumber(num) << endl;

    // 8️⃣ Key Generation
    cout << "\n=========== KEYS ===========" << endl;
    string* keys = ArrayKeyGen(5, 3, length);
    PrintArrayElement(keys, length, "Generated Keys");

    // 9️⃣ Cleanup
    delete[] array1; delete[] array2; delete[] sumArray;
    delete[] copyArray; delete[] reverseArray; delete[] shuffleArray;
    delete[] primeArray; delete[] evenArray; delete[] oddArray;
    delete[] userArray; delete[] reverseUserArray; delete[] distinctArray; delete[] keys;

    cout << "\n================= PROGRAM END =================" << endl;
    return 0;
}
