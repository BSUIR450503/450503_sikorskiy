#include "libraru.h"

myproc::myproc() {
	x = 0;
	y = 0;
}

myproc::myproc(double X) {
	x = X;
	y = 0;
}

void myproc::show() {
	cout << endl << "Input number " << x << endl;
	cout << "Result " << y << endl << endl;
}

void myproc::proces() {
	fstream input_file;
	input_file.open("temp.txt", ios::app | ios::binary);
	input_file << x;
	input_file.close();

#ifdef _WIN32
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	TCHAR CommandLine[] = TEXT("22");
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	if (!CreateProcess(NULL, CommandLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
		cout << "create process failed!";
		return;
	}

	WaitForSingleObject(pi.hProcess, INFINITE );
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
#endif

#ifdef linux
	pid_t pid; 
	int status;
	switch(pid = fork()) {
	case -1:
		perror("fork");
		cout << "Error!";
		exit(1);
	case 0:
		execl("22", "one", "two", "t", NULL);
		exit(0);
	default:
		wait(&status);
	}
#endif

	fstream output_file;
	output_file.open("temp.txt", ios::in | ios::binary);
	output_file >> y;
	output_file.close();
	remove("temp.txt");
}
