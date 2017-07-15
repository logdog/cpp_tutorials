// program to generate all of the possible DOE one keys
// reqs: 6 digits only numbers
// cannot have ANY sequential numbers or back-to-back repeats
// 537283 == good
// 537823 == bad
#include <iostream>
#include <cmath>
using namespace std;

bool passesNameCheck(int number) {

	for(int i = 0; i < 5; i++) { // don't need to check left digit
		int rightDigit = number % 10;
		number /= 10;
		int leftDigit = number % 10;
		if(abs(rightDigit - leftDigit) <= 1)
			return false;
	}

	return true;
}

int main() {

	int totalKeys;

	for(int i = 0; i < pow(10, 6) ; i++) {
		if(passesNameCheck(i)) {
			// cout << "Valid One Key: " << i << endl; 
			++totalKeys;
		} else {
			// cout << "Failed One Key: " << i << endl;
		}
	}

	cout << "\nTotal One Keys: " << totalKeys << endl;

}