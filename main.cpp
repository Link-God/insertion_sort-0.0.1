#include "stdafx.h"
#include<iostream>
#include<sstream>

using namespace std;

void sort(int * array, unsigned int size)
{
	for (unsigned int i = 1; i < size; i++)
	{
		for (int j = i - 1; j >=0; j--)
		{
			if (array[j] > array[j + 1]) 
			{
				swap(array[j], array[j + 1]);
			}
			else 
			{
				break;
			}
		}
	}
}
bool read(int * array, unsigned int size)
{
	string mas;
	unsigned int i = 0, array_count = 0;
	getline(cin, mas);
	istringstream stream(mas);
	for (i; i < size; i++)
	{
		if (stream >> array[i])
		{
			array_count++;
		}
	}
	if (array_count == size && stream.eof()) return true;
	else return false;
}
void print(int * array, unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
}

bool size_s(unsigned int &size)
{
	string str;
	getline(cin, str);
	istringstream stream(str);
	if (!(stream >> size))
	{
		return false;
	}
	else
	{
		if (stream.eof()) { return true; }
		else { return false; }
	}
}
int main()
{
	unsigned int size;
	if (size_s(size))
	{
		int * array;
		array = new int[size];
		if (read(array, size))
		{
			sort(array, size);
			print(array, size);
			cin.get();
		}
		else
		{
			cout << "fail input ";
			cin.get();
		}
		delete[] array;
	}
	else { cout << "size error"; cin.get(); }
	return 0;
}
