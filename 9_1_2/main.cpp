#include "Byte.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int bytesNumber;
	
	cin >> bytesNumber;

	vector<Byte> bytes;
	bytes.reserve(bytesNumber);

	int tempData, tempMask;
	cin.unsetf(ios::dec);
	cin.setf(ios::hex);
	for (size_t iter = 0; iter < bytesNumber; iter++)
	{
		cin >> tempData >> tempMask;
		bytes.push_back(Byte(tempData, tempMask));
	}
	
	int byteNumber_1, byteNumber_2;
	char operation;
	while (cin >> byteNumber_1 >> operation >> byteNumber_2)
	{
		if (operation == '&')
		{
			bytes.at(byteNumber_1 - 1) = bytes.at(byteNumber_1 - 1) &
				bytes.at(byteNumber_2 - 1);
		}
		else
		{
			bytes.at(byteNumber_1 - 1) = bytes.at(byteNumber_1 - 1) |
				bytes.at(byteNumber_2 - 1);
		}
	}

	cout.width(2);
	cout.fill('0');
	cout << hex << uppercase << bytes.at(byteNumber_1 - 1).getData();
	return 0;
}