#pragma once

#include <cstdlib>
#include "generator.h"

class GeneratorXORSHIFT : public Generator
{
private:
	//unsigned long long bitwiseMultiply(unsigned long long a, unsigned long long b)
	//{
	//	unsigned long long r = 0;
	//	while (b != 0)
	//	{
	//		unsigned long long temp = b & 1;

	//		if (temp != 0)
	//		{
	//			r = r + a;
	//		}
	//		a = a << 1;
	//		b = b >> 1;
	//		if (temp == 0)
	//		{
	//			r = a;
	//			break;
	//		}
	//	}

	//	return r;
	//}

protected:
	void update()
	{
		unsigned long long tmp = 0;

		for (int i = 0; i < _complexity; i++)
		{
			tmp = _state;
			tmp ^= tmp >> 12; // a
			tmp ^= tmp << 25; // b
			tmp ^= tmp >> 27; // c
			//_state = bitwiseMultiply(tmp, 0x2545F4914F6CDD1D);
			_state = tmp * 0x2545F4914F6CDD1D;
		}
	};

public:
	GeneratorXORSHIFT(int complexity = 1) : Generator(complexity) {};

	void init(unsigned long long seed)
	{
		_state = seed;
	}

	unsigned char nextByte()
	{
		update();

		return (unsigned char) _state;
	}
};

