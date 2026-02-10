#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

// ============================================================
//                        Structs & Enums
// ============================================================

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

// ============================================================
//                 Basic Input & Random Utilities
// ============================================================

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

// ============================================================
//                 Array Creation & Manipulation
// ============================================================

int* CreateRandomArray(int length) {
	int* array = new int[length];
	for (int i = 0; i < length; i++)
		array[i] = RandomNumber(1, 100);
	return array;
}

int* CopyArray(const int* array, int length_array) {
	int* copy_array = new int[length_array];
	for (int i = 0; i < length_array; i++)
		copy_array[i] = array[i];
	return copy_array;
}

int* ReverseArray(const int* array, int length_array) {
	int* reverse_array = new int[length_array];
	for (int i = 0; i < length_array; i++)
		reverse_array[i] = array[length_array - i - 1];
	return reverse_array;
}

int* ShuffleArray(const int* array, int length_array) {
	int* shuffle_array = new int[length_array];
	for (int i = 0; i < length_array; i++)
		shuffle_array[i] = array[i];

	for (int i = 0; i < length_array - 1; i++) {
		int j = RandomNumber(i, length_array - 1);
		swap(shuffle_array[i], shuffle_array[j]);
	}
	return shuffle_array;
}

int* SumTwoArrayElements(const int* array1, const int* array2, int length) {
	int* sum_array = new int[length];
	for (int i = 0; i < length; i++)
		sum_array[i] = array1[i] + array2[i];
	return sum_array;
}

// ============================================================
//                 Array Analysis & Checks
// ============================================================

stStatus GetArrayStatus(const int* array, int length_array) {
	stStatus Status{};
	if (length_array == 0) return Status;

	Status.max_number = array[0];
	Status.min_number = array[0];
	Status.sum_number = array[0];

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
	for (int i = 2; i * i <= number; i++) {
		if (number % i == 0) return NotPrime;
	}
	return Prime;
}

enIsEvenOrOdd CheckIsEvenOrOdd(int number) {
	return (number % 2 == 0) ? Even : Odd;
}

bool IsPalindrome(int* array, int length) {
	for (int i = 0; i < length / 2; i++)
		if (array[i] != array[length - i - 1])
			return false;
	return true;
}

// ============================================================
//                 Array Filtering & Searching
// ============================================================

enSearch CheckIsFound(const int* array, int length_array, int search_number) {
	for (int i = 0; i < length_array; i++)
		if (array[i] == search_number)
			return Found;
	return NotFound;
}

int GetPositionItem(const int* array, int length_array, int search_number) {
	for (int i = 0; i < length_array; i++)
		if (array[i] == search_number)
			return i;
	return -1;
}

int* ArrayIsPrime(int* array, int length, int& prime_count) {
	int* array_prime = nullptr;
	prime_count = 0;

	for (int i = 0; i < length; i++) {
		if (CheckIsPrime(array[i]) == Prime) {
			int* temp = new int[prime_count + 1];
			for (int j = 0; j < prime_count; j++)
				temp[j] = array_prime[j];
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
			for (int j = 0; j < even_count; j++)
				temp[j] = array_even[j];
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
			for (int j = 0; j < odd_count; j++)
				temp[j] = array_odd[j];
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
			for (int j = 0; j < distinct_count; j++)
				temp[j] = array_distinct[j];
			temp[distinct_count] = array[i];
			delete[] array_distinct;
			array_distinct = temp;
			distinct_count++;
		}
	}
	return array_distinct;
}

// ============================================================
//                 Key & String Utilities
// ============================================================

string BlockChar(int length_block) {
	string block_char = "";
	for (int i = 0; i < length_block; i++)
		block_char += RandomChar(CapitalLetter);
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
	for (int i = 0; i < length_array; i++)
		array_key_gen[i] = KeyGeneration(length_block, count_block);
	return array_key_gen;
}

// ============================================================
//                 Dynamic Input & Printing
// ============================================================

bool QuestionToAddNumber() {
	int choice;
	cout << "Do you want to add more numbers? [0]No, [1]Yes: ";
	cin >> choice;
	return choice == 1;
}

void AddNumberToArray(int*& array, int& length_array) {
	int number = ReadNumber("Please enter number: ");
	int* new_array = new int[length_array + 1];
	for (int i = 0; i < length_array; i++)
		new_array[i] = array[i];
	new_array[length_array] = number;
	delete[] array;
	array = new_array;
	length_array++;
}

void FillArray(int*& array, int& length_array) {
	while (QuestionToAddNumber()) {
		AddNumberToArray(array, length_array);
	}
}

void PrintArray(const int* array, int length_array, string name_array) {
	cout << name_array;
	for (int i = 0; i < length_array; i++)
		cout << "\t" << array[i];
	cout << endl;
}

void PrintArrayElement(string* array, int length_array, string name_array) {
	cout << name_array << endl;
	for (int i = 0; i < length_array; i++)
		cout << "Array [" << i + 1 << "] : " << array[i] << endl;
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

// ============================================================
//                  Math Utilities
// ============================================================

float AbsoluteNumber(float number) { return (number < 0) ? -number : number; }
int RoundNumber(float number) { return (number >= 0) ? int(number + 0.5) : int(number - 0.5); }
int FloorNumber(float number) { int i = int(number); return (number < 0 && number != i) ? i - 1 : i; }
int CeilNumber(float number) { int i = int(number); return (number > 0 && number != i) ? i + 1 : i; }

// ============================================================
//                          Main
// ============================================================
int main() {
	srand((unsigned)time(nullptr));

	cout << "================= PROGRAM START =================\n";

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
