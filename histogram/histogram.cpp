#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "../colorformat/colorformat.h"

using namespace std;

class Histogram {
	int keyLen;
	vector<string> keys;
	vector<float> rawValues;
	vector<int> adjValues;
public:
	Histogram(const vector<string> &k, const vector<float> &v, int maxWidth);
	void draw();
};

Histogram::Histogram(const vector<string> &keys, const vector<float> &values, int maxWidth) {
	this->keys = keys;
	this->rawValues = values;
	// find largest number in the vector
	float maxValue = 1;
	for(float f: values) {
		maxValue = (f > maxValue) ? f : maxValue;
	}
	// max key size
	for(string s: keys) {
		this->keyLen = (s.length() > keyLen) ? s.length() : keyLen;
	}
	// create our vector filled with # of 
	float conversionRatio = float(maxWidth) / maxValue;
	for(float f: values) {
		this->adjValues.push_back(int(f * conversionRatio));
	}
}

void Histogram::draw() {
	/*
		key1 [##########] 80
		key2 [################] 120
		key3 [######] 40
	*/
	for(int i = 0; i < int(adjValues.size()); i++) {
		// make the keys have the right length
		string key = "";
		for(int j = 0; j < keyLen; j++) {
			key += " ";
		}
		key.replace(0, keys.at(i).length(), keys.at(i));

		// make the hashes
		string hashes = "";
		
		for(int j = 0; j < adjValues.at(i)-2; j++) {
			hashes += "#";
		}

		hashes = setRainbow(hashes);

		cout << key << " [" << hashes << "] "<< rawValues.at(i) << endl;
	}
}

int main() {
	vector<string> keys = {"bananas", "mangos", "pineapples", "watermelons"};
	vector<float> values = {100, 200, 150, 133};
	Histogram h (keys, values, 40);
	h.draw();
}
