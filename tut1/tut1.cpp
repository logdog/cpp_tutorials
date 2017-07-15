#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {

	string name;

	string ageStr;
	int age; 

	cout << "What is your name? ";
	std::getline(cin, name); // assign name to the entire line, not just the first word

	cout << "How old are you? ";
	cin >> ageStr;
	stringstream(ageStr) >> age; // turn ageStr into an unsigned char

	int futureAge = age + 10;

	cout << name << ", you will be " << futureAge << " years old in 10 years." << endl;

}