#include "pch.h"
#include "threading.h"
#include <Windows.h>
#include <iostream>
#include <thread>
#include <string>

using namespace std;

void task1(std::string msg, unsigned long wait) {
	std::cout << "task1 says: " << msg << " wait for " << wait << " msecs\n" ; 
	Sleep(wait); 
	std::cout << "task1 says: " << "FINISHED\n";
};

void trySimpleMultithread() {
	// Constructs the new thread and runs it. Does not block execution.
	std::thread t1(task1, "Hello\n", 20000);
	std::thread t2(task1, "Somewhere\n", 10000);
	std::thread t3(task1, "Bye\n", 30000);

	// Makes the main thread wait for the new thread to finish execution, therefore blocks its own execution.
	t1.join();
	t2.join();
	t3.join();

	std::cout << "Three threads have been joined.\n";
};