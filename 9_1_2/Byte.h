#ifndef __BYTE_H
#define __BYTE_H

class Byte
{
private:
	int data;
	int mask;

public:
	Byte(int data, int mask);

	int getData();
	int getMask();

	Byte operator& (Byte byte);
	Byte operator| (Byte byte);
};

#endif