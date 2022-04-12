#include "Byte.h"

Byte::Byte(int data, int mask)
{
	this->data = data;
	this->mask = mask;
}

int Byte::getData()
{
	return this->data;
}

int Byte::getMask()
{
	return this->mask;
}

Byte Byte::operator&(Byte byte)
{
	int LM = this->mask & byte.mask;
	int TDWLM = this->data & LM;
	int BDWLM = byte.data & LM;
	int XorDsWLM = (TDWLM & BDWLM) ^ TDWLM;
	return Byte(((this->data) ^ XorDsWLM), this->mask);
}

Byte Byte::operator|(Byte byte)
{
	int LM = this->mask & byte.mask;
	int TDWLM = this->data & LM;
	int BDWLM = byte.data & LM;
	int OrDsWLM = TDWLM | BDWLM;
	return Byte(((this->data) | OrDsWLM), this->mask);
}
