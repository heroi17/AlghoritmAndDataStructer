#include <iostream>
#include <chrono>
//Example for summation of big matrix.
using namespace std;
#define MatrixSize 10000
enum HM {
	HIT,
	MISS
};


auto test(int matrix[MatrixSize * MatrixSize], HM TEST) {
	auto startHIT = std::chrono::high_resolution_clock::now();
	int answer = 0;
	if (TEST == HIT) {
		for (size_t j = 0; j < MatrixSize; j++) {
			for (size_t i = 0; i < MatrixSize; i++) {
				answer += matrix[j * MatrixSize + i];
			}
		}
	}
	else if (TEST == MISS)
	{
		for (size_t j = 0; j < MatrixSize; j++) {
			for (size_t i = 0; i < MatrixSize; i++) {
				answer += matrix[i * MatrixSize + j];
			}
		}
	}
	auto endHIT = std::chrono::high_resolution_clock::now();

	return std::pair(endHIT - startHIT, answer);
}

int main()
{
	int* matrix = new int[MatrixSize * MatrixSize];
	for (size_t i = 0; i < MatrixSize; i++) {
		for (size_t j = 0; j < MatrixSize; j++) {
			matrix[i * MatrixSize + j] = 1;
		}
	}

	auto [timeHit, answerHit] = test(matrix, HIT);

	auto [timeMiss, answerMiss] = test(matrix, MISS);


	std::cout << "Miss time summation: " << timeMiss << std::endl;
	std::cout << "Hit  time summation: " << timeHit  << std::endl;
	//Miss time summation : 861337100ns		   
	//Hit  time summation : 243014400ns        |Arround 3.5 times faster|
	//For matrix: 10000 X 10000
	system("pause");
	return 0;
}
