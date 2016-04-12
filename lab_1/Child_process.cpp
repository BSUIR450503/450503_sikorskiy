#include <iostream>
#include <string>
#include <fstream>


using namespace std;

int main() {
	double input;
	double output;
	fstream input_file;
	input_file.open("temp.txt", ios::in | ios::binary);
	if (!input_file) {
		cout << "No input number" << endl;
		return 1;
	}

	input_file >> input;
	input_file.close();

	output = input * input;

	remove("temp.txt");

	fstream output_file;
	output_file.open("temp.txt", ios::app | ios::binary);
	if (!output_file) {
		cout << "Error open file" << endl;
		return 1;
	}
	output_file << output;
	output_file.close();
	return 0;
}