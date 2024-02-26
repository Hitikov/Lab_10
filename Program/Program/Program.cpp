#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int fun_count() 
{
	ifstream input("File1.txt");
	string row;
	int n = 0;
	while (!input.eof()) {
		getline(input, row);
		++n;
	}
	input.close();
	return n;
}

string* fun_form(int n) 
{
	string* mas = new string[n];
	ifstream input("File1.txt");
	string row;
	int i = 0;
	while (!input.eof()) {
		getline(input, row);
		mas[i] = row;
		++i;
	}
	input.close();

	return mas;
}

void fun_print(int n, string* mas) 
{
	for (int i = 0; i < n; ++i) 
	{
		cout << mas[i] << endl;
	}
}

int fun_reform(int n, string* mas, int k) 
{
	for (int i = k; i < n; ++i) {
		mas[i - k] = mas[i];
	}
	return n-k;
}

void fun_delete(string* mas)
{
	delete[] mas;
}

int main()
{	
	int k;
	int n = fun_count();
	string* mas = fun_form(n);
	fun_print(n, mas);
	cout << endl << "Enter number of elements for deleting: ";
	cin >> k;
	cout << endl;
	n = fun_reform(n, mas, k);
	fun_print(n, mas);
	fun_delete(mas);

	return 0;
}