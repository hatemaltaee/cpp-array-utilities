#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

// ----------------------------
// Structs & Enums
// ----------------------------

// Struct to store statistics of an array
struct stStatus {
	int max_number;    // Maximum number in the array
	int min_number;    // Minimum number in the array
	int sum_number;    // Sum of all numbers in the array
	double avg_number; // Average of the numbers
};

// Enum to check if a number is prime
enum enIsPrime { NotPrime, Prime };

// Enum to check if a number exists in an array
enum enSearch { NotFound, Found };

// Enum to define types of characters for random generation
enum enCharType { SmallLatter, CapitalLatter, SpecialChar, Digit };

// ----------------------------
// Utility Functions
// ----------------------------

// Function: ReadNumber
// Purpose: Reads a positive integer from the user with a message
// Input: Message string
// Output: User-entered positive integer
int ReadNumber(string Message) {
	int number;
	do {
		cout << Message;
		cin >> number;
	} while (number <= 0);

	return number;
}

// Function: RandomNumber
// Purpose: Generate a random integer between 'from' and 'to'
// Input: 'from', 'to' integer range
// Output: random integer
int RandomNumber(int from, int to) {
	return rand() % (to - from + 1) + from;
}

// Function: CreateRandomArray
// Purpose: Creates a dynamic array of given length filled with random numbers [1,100]
// Input: length of the array
// Output: pointer to the array
int* CreateRandomArray(int length) {
	int* array = new int[length];
	for (int i = 0; i < length; i++) {
		array[i] = RandomNumber(1, 100);
	}
	return array;
}

// Function: CopyArray
// Purpose: Creates a copy of a given array
int* CopyArray(int* array, int length_array) {
	int* copy_array = new int[length_array];
	for (int i = 0; i < length_array; i++) {
		copy_array[i] = array[i];
	}
	return copy_array;
}

// Function: ReverseArray
// Purpose: Returns a new array which is the reverse of the given array
int* ReverseArray(int* array, int length_array) {
	int* reverse_array = new int[length_array];
	int length_reverse_array = length_array;
	for (int i = 0; i < length_array; i++) {
		reverse_array[i] = array[length_reverse_array - 1];
		length_reverse_array--;
	}
	return reverse_array;
}

// Function: ShuffleArray
// Purpose: Returns a shuffled version of the given array
int* ShuffleArray(int* array, int length_array) {
	int* shuffle_array = new int[length_array];
	for (int j = 0; j < length_array; j++)
		shuffle_array[j] = array[j];

	for (int i = 0; i < length_array - 1; i++) {
		int j = RandomNumber(i, length_array - 1);
		swap(shuffle_array[i], shuffle_array[j]);
	}
	return shuffle_array;
}

// Function: GetArrayStatus
// Purpose: Calculates statistics (max, min, sum, average) of an array
stStatus GetArrayStatus(const int* array, int length_array) {
	stStatus Status;
	Status.max_number = array[0];
	Status.min_number = array[0];
	Status.sum_number = array[0];
	for (int i = 1; i < length_array; i++) {
		if (Status.max_number < array[i]) Status.max_number = array[i];
		if (Status.min_number > array[i]) Status.min_number = array[i];
		Status.sum_number += array[i];
	}
	Status.avg_number = double(Status.sum_number) / length_array;
	return Status;
}

// Function: CheckIsPrime
// Purpose: Checks if a number is prime
enIsPrime CheckIsPrime(int number) {
	if (number > 1) {
		for (int i = 2; i * i <= number; i++) {
			if (number % i == 0) return NotPrime;
		}
	}
	else return NotPrime;
	return Prime;
}

// Function: ArrayIsPrime
// Purpose: Returns an array containing all prime numbers from the input array
int* ArrayIsPrime(int* array, int length, int& prime_count) {
	int* array_prime = nullptr;  // Start empty
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

// Function: SumTwoArrayElements
// Purpose: Returns a new array containing sum of elements from two arrays
int* SumTwoArrayElements(int* array1, int* array2, int length) {
	int* sum_two_array = new int[length];
	for (int i = 0; i < length; i++) {
		sum_two_array[i] = array1[i] + array2[i];
	}
	return sum_two_array;
}

// Function: RandomChar
// Purpose: Generates a random character based on type
char RandomChar(enCharType char_type) {
	switch (char_type) {
	case SmallLatter: return char(RandomNumber(97, 122));
	case CapitalLatter: return char(RandomNumber(65, 90));
	case SpecialChar: return char(RandomNumber(33, 47));
	case Digit: return char(RandomNumber(48, 57));
	}
	return '\0';
}

// Function: BlockChar
// Purpose: Returns a string of random capital letters
string BlockChar(int length_block) {
	string block_char = "";
	for (int i = 0; i < length_block; i++) {
		char char_type = RandomChar(CapitalLatter);
		block_char += char_type;
	}
	return block_char;
}

// Function: KeyGeneration
// Purpose: Generates a key composed of blocks of random letters
string KeyGeneration(int length_block, int count_block) {
	string key_generation = "";
	for (int i = 0; i < count_block; i++) {
		string block_char = BlockChar(length_block);
		key_generation += block_char;
		if (i < count_block - 1) key_generation += "-";
	}
	return key_generation;
}

// Function: ArrayKeyGen
// Purpose: Returns an array of keys
string* ArrayKeyGen(int length_block, int count_block, int length_array) {
	string* array_key_gen = new string[length_array];
	for (int i = 0; i < length_array; i++) {
		array_key_gen[i] = KeyGeneration(length_block, count_block);
	}
	return array_key_gen;
}

// Function: CheckIsFound
// Purpose: Checks if a number exists in the array
enSearch CheckIsFound(int* array, int length_array, int search_number) {
	for (int i = 0; i < length_array; i++) {
		if (search_number == array[i]) return Found;
	}
	return NotFound;
}

// Function: GetPositionItem
// Purpose: Returns index of a number in array, -1 if not found
int GetPositionItem(int* array, int length_array, int search_number) {
	for (int i = 0; i < length_array; i++) {
		if (search_number == array[i]) return i;
	}
	return -1;
}

// Function: QuestionToAddNumber
// Purpose: Ask user if they want to add more numbers
bool QuestionToAddNumber() {
	bool flag;
	cout << "Do you want to add more number ? [0]No,[1]Yes ? ";
	cin >> flag;
	return flag;
}

// Function: AddNumberToArray
// Purpose: Adds a number to a dynamic array
void AddNumberToArray(int*& array, int& length_array) {
	int number = ReadNumber("Please enter number :");
	int* new_array = new int[length_array + 1];
	for (int i = 0; i < length_array; i++)
		new_array[i] = array[i];
	new_array[length_array] = number;
	delete[] array;
	array = new_array;
	length_array++;
}

// Function: PrintArray
// Purpose: Prints array of integers with a name
void PrintArray(const int* array, int length_array, string name_array) {
	cout << name_array;
	for (int i = 0; i < length_array; i++)
		cout << "\t" << array[i];
	cout << endl;
}

// Function: PrintArrayElement
// Purpose: Prints array of strings with indices
void PrintArrayElement(string* array, int length_array, string name_array) {
	cout << name_array << endl;
	for (int i = 0; i < length_array; i++) {
		cout << "Array [" << i + 1 << "] : " << array[i] << endl;
	}
}

// Function: PrintIsFound
// Purpose: Prints whether a number is found and its position
void PrintIsFound(int* array, int length_array, int number_search, int position_item) {
	if (CheckIsFound(array, length_array, number_search) == Found) {
		cout << "Number you are looking for: " << number_search << endl;
		cout << "Found at position: " << position_item << endl;
		cout << "Order in array: " << position_item + 1 << endl;
	}
	else {
		cout << "Number you are looking for: " << number_search << endl;
		cout << "Number is not found :-(" << endl;
	}
}

// Function: FillArray
// Purpose: Fill array by adding numbers from user until they stop
void FillArray(int*& array, int& length_array_list) {
	while (QuestionToAddNumber()) {
		AddNumberToArray(array, length_array_list);
	}
}

// ----------------------------
// Main Function
// ----------------------------
int main() {
	srand(time(0)); // Initialize random seed

	// Parameters for random keys
	int prime_count = 0;
	int length_block = 5;
	int count_block = 3;

	// Get array length from user
	int length_array = ReadNumber("How long is the array: ");

	// Create arrays
	int* array1 = CreateRandomArray(length_array);
	int* array2 = CreateRandomArray(length_array);
	int* sum_two_array = SumTwoArrayElements(array1, array2, length_array);
	int* copy_array = CopyArray(array1, length_array);
	int* shuffle_array = ShuffleArray(array1, length_array);
	int* reverse_array = ReverseArray(array1, length_array);
	int* prime_array = ArrayIsPrime(array1, length_array, prime_count);
	stStatus Status = GetArrayStatus(array1, length_array);
	char char_type = RandomChar(CapitalLatter);
	string block_char = BlockChar(length_block);
	string key_generation = KeyGeneration(length_block, count_block);
	string* array_key_gen = ArrayKeyGen(length_block, count_block, length_array);

	// Print results
	PrintArray(array1, length_array, "Original Array1    : ");
	PrintArray(array2, length_array, "Original Array2    : ");
	PrintArray(sum_two_array, length_array, "Sum Array1 + Array2: ");
	PrintArray(copy_array, length_array, "Copy Array1        : ");
	PrintArray(shuffle_array, length_array, "Shuffle Array1     : ");
	PrintArray(reverse_array, length_array, "Reverse Array1     : ");
	PrintArray(prime_array, prime_count, "Prime Number Array : ");
	PrintArrayElement(array_key_gen, length_array, "--- Key Gen Array ---");

	// Print statistics
	cout << "Max Number Is      : " << Status.max_number << endl;
	cout << "Min Number Is      : " << Status.min_number << endl;
	cout << "Sum Number Is      : " << Status.sum_number << endl;
	cout << "Avg Number Is      : " << Status.avg_number << endl;

	// Search example
	int number_search = ReadNumber("Please enter number to search for: ");
	int position_item = GetPositionItem(array1, length_array, number_search);
	PrintIsFound(array1, length_array, number_search, position_item);

	// Dynamic array fill by user
	int length_array_list = 0;
	int* array = nullptr;
	FillArray(array, length_array_list);
	cout << "Length Array : " << length_array_list << endl;
	PrintArray(array, length_array_list, "User-filled Array: ");

	// Free dynamic memory
	delete[] array;
	delete[] array1;
	delete[] array2;
	delete[] shuffle_array;
	delete[] reverse_array;
	delete[] copy_array;
	delete[] sum_two_array;
	delete[] prime_array;
	delete[] array_key_gen;

	return 0;
}
