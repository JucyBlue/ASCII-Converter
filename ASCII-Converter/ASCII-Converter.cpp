#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> 
#include<stdio.h>
using namespace std;

string ConvertTextToASCII(char str[]);
void WriteFile(string);
string ReadFile();
void MyMain();

int main()
{
	
	MyMain();
	cout << "\n\n\n";
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
	else cout << "\nReading..." << endl;
	cout << ReadFile() << endl; //reads the file

	

}

void WriteFile(string text){
	fstream myFile;
	//cout << text << endl;
	myFile.open("ASCII.txt", ios::out); //overwrite text
	if (myFile.is_open()) {
		myFile << text;
		myFile.close();
	}
}

string ReadFile() {
	fstream myFile;
	myFile.open("ASCII.txt", ios::in);
	if (myFile.is_open()) {
		string line;
		cout << "\nOriginal Text:";
		while (getline(myFile, line)) {
			cout << line;
			cout << " ";
		}
		myFile.clear();
		myFile.seekg(0);
		
		string text = "\n\nAfter Decode:";
		while (getline(myFile, line)) {
			 text += char(stoi(line));
		}
		myFile.close();
		return text;
	}
}

 string ConvertTextToASCII(char str[]) {
	 //cout << str << "--word" << endl;
	 //cout << str << "--word" << endl;
	 string ASCII = "";
	 for (int i = 0; i < 1000; i++) {
		 if (int(str[i]) == 0) {
			 break;
		 }
		
		ASCII += to_string(int(str[i])) += "\n"; //converts char's to ASCII code
	}
	 return ASCII;
}
