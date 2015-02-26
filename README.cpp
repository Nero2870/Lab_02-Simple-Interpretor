# Lab_02-Simple-Interpretor
Simple Interpretor in Cpp
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

int parse_file();

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
	int get_line() {

	}

	int perform_calculations() {

	}

private:

};


int main() {
	string line;
	ifstream myfile("input.txt");
	map<string, uint32_t> my_map;


	parse_file();
	getchar();
	return 0;
}


int parse_file() {
	string line;
	string name;
	string name2;
	string new_string;
	map<string, uint32_t> my_map;

	ifstream myfile("input.txt");	//Open file
	if (myfile.is_open())			//if open 
	{
		while (getline(myfile, line))	// getline 
		{
			int hell = line.find("Let");
			if (hell ==0)
			{
				cout << "Here is the line = " << line;
				int i = 0;
				int j = 3;
				if (line.compare(i, j, "Let") == 0) {
					i += j;
					j = 1;
					if (line.compare(i, j, " ") == 0) {
						i++;
						while (line.compare(i, j, " ") == 0) {
							i++;
						}
						int k = i;
						while (line.compare(k, j, " ") != 0) {
							k++;
						}
						char new_str_1[10];
						line.copy(new_str_1, k - i, i);
						std::string new_string(new_str_1);
						i = k;
						while (line.compare(i, j, "=") != 0) {
							i++;
						}
						while (line.compare(i, j, " ") != 0)
						{
							i++;
						}
						char value[10];
						while (line.compare(k, j, "") != 0) {
							k++;
						}
						line.copy(value, i - k, i);
						my_map[new_string] = stoi(value);
						cout << "Name of variable is = " << new_string << " and value = " << my_map[new_string] << endl;
						cout << "Done first line;";
					}
					else {
						cout << "Syntex error.Please insert space between characters" << endl;
						exit(1);
					}
				}
			}
			else if ((line.find("+") != NULL) || (line.find("-") != NULL) || (line.find("/") != NULL) || (line.find("*") != NULL)) {
				int i = 0;
				int j = 1;
				int k = 0;
				int foo = 0;
				string line_cal[10];
				while (line.compare(i, j, " ") == 0) {  //while spaces before expression
					i++;
				}
				k = i;
				while (line.compare(k, j, " ") != 0) {	// while spaces before next expression
					k++;
				}
				char new_str_1[10];
				line_cal[foo].copy(new_str_1, k - i, i);
				std::string new_string(new_str_1);
				foo++;
				i = k;
				while ((line.compare(i, j, "+") == 0)||(line.compare(i, j, "+") == 0)||(line.compare(i, j, "+") == 0)||(line.compare(i, j, "+") == 0)) {	// while spaces before next expression
					i++;
				}
				char new_str[10];
				line_cal[foo].copy(new_str, k - i, i);
				std::string new_string2(new_str);
				foo++;
				while (line.compare(i, j, " ") == 0) {  //while spaces before expression
					i++;
				}
				k = i;
				while (line.compare(k, j, " ") != 0) {	// while spaces before next expression
					k++;
				}
				new_str[10];
				line_cal[foo].copy(new_str, k - i, i);
				std::string new_string3(new_str);
				foo = 0;
				//		perform_calculations();

				cout << "The first variable is " << my_map[line_cal[0]] << endl;
				cout << "The operator variable is \n" << my_map[line_cal[1]] << endl;
				cout << "The second variable is \n" << my_map[line_cal[2]] << endl;
				}
				else if (line.find("print") != NULL) {
					int i = 0;
					int j = 1;
					int k = 0;
					while (line.compare(i, j, "[") == 0) {  //while spaces before expression
						i++;
					}
					k = i;
					while (line.compare(i, j, "]") != 0) {	// while spaces before next expression
						i++;
					}
					string line_cal;
					int foo = 0;
					char new_str[10];
					line_cal.copy(new_str, k - i, i);
					std::string new_string(new_str);
					cout << my_map[line_cal] << endl;
				}
			else {
				cout << "Please check the line is invalid";
			}
			cout << line << '\n';		//print line
		}
		myfile.close();
	}

	 
	cout << "Unable to open file";
	getchar();
	return 0;
}

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
