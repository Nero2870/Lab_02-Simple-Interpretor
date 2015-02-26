/*
** Author : Muhammad Abdullah Khan
** Lab	  : Lab-02
** Subject: Advance Programming
** School : NUST SEECS
*/

// Liberaries Include

#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;


// Function definations
int parse_file(string name_loc);


// Template Functions

// These function are going to do the calculations
template <typename T>
T add(T &a, T &b) {
	return a + b;
}


template <typename T>
T sub(T &a, T &b) {
	return a - b;
}

template <typename T>
T div(T &a, T &b) {
	return a / b;
}

template <typename T>
T mul(T &a, T &b) {
	return a * b;
}


// Test cases  Can call any test case function
int test_add() {
	ofstream myfile;
	string name;
	myfile.open("input_add.txt");
	myfile << "Let a = 10\n";
	myfile << "Let b = 10\n";
	myfile << "Let c = 0\n";
	myfile << "c = a + b\n";
	myfile << "print [c]\n";
	myfile.close();

	name = "input_add.txt";
	return parse_file(name);
}
int test_sub() {
	ofstream myfile;
	string name;
	myfile.open("input_sub.txt");
	myfile << "Let a = 10\n";
	myfile << "Let b = 10\n";
	myfile << "Let c = 0\n";
	myfile << "c = a - b\n";
	myfile << "print [c]\n";
	myfile.close();

	name = "input_sub.txt";
	return parse_file(name);
}
int test_div() {
	ofstream myfile;
	string name;
	myfile.open("input_div.txt");
	myfile << "Let a = 10\n";
	myfile << "Let b = 10\n";
	myfile << "Let c = 0\n";
	myfile << "c = a / b\n";
	myfile << "print [c]\n";
	myfile.close();


	name = "input_div.txt";
	return parse_file(name);
}
int test_mul() {
	ofstream myfile;
	string name;

	myfile.open("input_mul.txt");
	myfile << "Let a = 10\n";
	myfile << "Let b = 10\n";
	myfile << "Let c = 0\n";
	myfile << "c = a * b\n";
	myfile << "print [c]\n";
	myfile.close();


	name = "input_mul.txt";
	return parse_file(name);
}


int crash_test() {
	ofstream myfile;
	string name;

	myfile.open("crash_test.txt");
	myfile << "    Let     a    =      10   \n";
	myfile << "   Let b    =   10\n";
	myfile << "Let    c  0\n";
	myfile << "10   =   a  *   b\n";
	myfile << "print [c]\n";
	myfile.close();


	name = "crash_test.txt";
	return parse_file(name);
}

// Template Class
template <typename T>
class MyClass
{
public:
	map<string, uint32_t> my_map;
	MyClass();
	~MyClass();
	char new_string1[50];
	char operation;
	//file_read Function

private:

};



// Main function
int main() {
	string line;
	ifstream myfile("input.txt");
	map<string, uint32_t> my_map;


	parse_file("input.txt");
	getchar();
	return 0;
}



// Parser Function 
int parse_file(string name_loc)
{
	string line;
	string name;
	char oper;
	string name2;
	char new_string[50];
	map<string, uint32_t> my_map;

	ifstream myfile(name_loc);	//Open file
	if (myfile.is_open())			//if open 
	{
		while (getline(myfile, line))	// getline 
		{
			if (line.find("Let") != NULL) {
				int i = 0;
				int j = 3;
				while (1) {			// until the end of line // then it will break
					if (line.compare(i, j, "Let") == 0) {
						i += j;
						j = 1;
						if (line.compare(i, j, " ") == 0) {			// Look and do nothing if more than 1 spaces	// No error is thrown
							i++;
							while (line.compare(i, j, " ") == 0) {
								i++;
							}
							int k = i;				// Store the location of first non space character
							while (line.compare(k, j, " ") != 0) {		// Go until the next space
								k++;
							}
							line.copy(new_string, k - i, i);		// Copy the name in the name string
							i = k;
							while (line.compare(i, j, "=") != 0) {		// go until there is an = sign 
								i++;
							}
							while (line.compare(i, j, " ") != 0)
							{
								i++;				// skip all spaces go the the first character of value
							}
							char value[10];			// Store the value 
							while (line.compare(k, j, "") != 0) {
								k++;
								break;
							}
							line.copy(value, k - i, i);
							my_map[new_string] = stoi(value);			// Assign the key value pair to the map

						}
						else {
							cout << "Syntex error.Please insert space between characters" << endl;		// In case of syntex error display
							exit(1);
						}
						cout << "Syntex error";
					}
					

					// Here we are entering the calculation line now
					// If there is one of the symbol for calculation enter the calculator finder line
					else if ((line.find("+") != NULL) || (line.find("-") != NULL) || (line.find("/") != NULL) || (line.find("*") != NULL)) {
						i = 0;
						j = 1;
						int k = 0;
						int l = 0;
						char name2[10][10];
						while (1) {
							if (line.compare(i, j, " ") == 0) {
								while (line.compare(i, j, " ") == 0) {	// Skip all spaces
									i++;
								}
							}
							else if (line.compare(i, j, " ") != 0) {
								k = i;			// Starting index of first name string
								while (line.compare(i, j, " ") != 0) {		// until we reach next space
									i++;
								}
								line.copy(name2[l], i - k, k);
								l++;
							}
							// Store the character value		
							else if (line.compare(i, j, "") == 0){
								l = 0;

								// After the values have been stored

								if (name2[3] == "+") {			
									// In case of addition call generic "add" template function
									my_map[name2[3]] = add(my_map[name2[2]] , my_map[name2[4]]);
								}
								else if (name2[3] == "-") {
									// In case of subtraction call generic "sub" template function
									my_map[name2[3]] = sub(my_map[name2[2]] , my_map[name2[4]]);
								}
								else if (name2[3] == "/") {
									// In case of division call generic "div" template function
									my_map[name2[3]] = div(my_map[name2[2]] , my_map[name2[4]]);
								}
								else if (name2[3] == "*") {
									// In case of multiplication call generic "mul" template function
									my_map[name2[3]] = mul(my_map[name2[2]] , my_map[name2[4]]);
								}
								else {
									cout << "Invalid Operator";
								}
							}
						}
					}
					else if ((line.find("Print") != NULL)) {
						i = 0;
						j = 1;
						int k = 0;
						while (1) {
							while (line.compare(i, j, "[") == 0) {	// Skip all spaces
								i++;
							}
							k = i;			// Starting index of first name string
							while (line.compare(i, j, "]") != 0) {		// until we reach next space
								i++;
							}
							char name[10];			// Store the character value
							line.copy(name, k - i, i);
							cout << my_map[line];
							break;
						}
					}
					else {
						cout << "syntex error";
					}
				}
				myfile.close();
			}
		}
	}
}





