// cppConsoleSanbox.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "asynchron.h"
#include "threading.h"
#include "structure.h"
#include <iostream>
#include <string>

using namespace std;
void echoConsoleInput(string msg);


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

int main(int argc, char** argv) {
	cout << "Main: argc=" << argc << " , argv=" << argv[0] << endl;
	//echoConsoleInput("Write something interesting.");
	std::cout << "Console Application - Starting...\n\n";

	tryAsync();			
	
	//tryList();
	//trySort();
	//tryLinkedList();
	//tryVector();
	//tryDeque();

	//trySimpleMultithread();
	
	std::cout << "\nConsole Application - Exiting...\n";
	return 0;
}


void echoConsoleInput(string msg) {
	cout << msg << "\n";
	char response[256];
	cin.get(response, 255);
	cout << "Echoing: " << response << "\n";
}