#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> 
#include<stdio.h>
using namespace std;

string ConvertTextToASCII(char str[]);
void WriteFile(string);
void ReadFile();
void MyMain();

int main()
{
	
	MyMain();
	system("pause");
}


void MyMain() {
	char str[1000];

	int inputInt;
	string inputStr;
	cout << "What would you like to do?\n1:write text file || 2:read text file" << endl;
	cin >> inputInt;

	if (inputInt == 1) {
		cout << "What would you like to write?\nText:";
		//cin.getline(str, sizeof(str));
		cin.ignore();
		cin.getline(str, sizeof(str));
		WriteFile(ConvertTextToASCII(str)); // Converts the text into ASCII then overwrites it into file
	}
	else cout << "invalid" << endl;
	ReadFile(); //reads the file

	

}

void WriteFile(string text){
	fstream myFile;
	myFile.open("ASCII.txt", ios::out); //overwrite text
	if (myFile.is_open()) {
		myFile << text;
		myFile.close();
	}
}

void ReadFile() {
	fstream myFile;
	myFile.open("ASCII.txt", ios::in);
	if (myFile.is_open()) {
		string line;
		while (getline(myFile, line)) {
			cout << line << endl;
		}
		myFile.clear();
		myFile.seekg(0);
		cout << "-----text-----" << endl;
		while (getline(myFile, line)) {
			cout << char(stoi(line)) << endl;
		}
		/*char ch = char(73);
		cout << ch << endl;*/

		
		myFile.close();
	}
}

 string ConvertTextToASCII(char str[]) {
	 cout << str << "--word" << endl;
	 string ASCII = "";
	 for (int i = 0; i < sizeof(str); i++) {
		 if (int(str[i]) == 0) {
			 cout << "---NULL---" << endl;
			 break;
		 }
		
		ASCII += to_string(int(str[i])) += "\n"; //converts char's to ASCII code
	}
	 return ASCII;
}
