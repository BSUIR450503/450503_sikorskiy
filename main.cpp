#include "libraru.h"

int main() {
	
	double x;
	cout << "Enter your number: ";
	cin >> x;
	myproc process(x);
	process.proces();
	process.show();
	Sleep(5000);
	return 0;
}
