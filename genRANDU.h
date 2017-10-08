#pragma once

#include <cstdlib>
#include "generator.h"

class GeneratorRANDU : public Generator
{
private:
	const unsigned long long modulus = 9223372036854775807;

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
			//_state = bitwiseMultiply(65539, (_state & (modulus - 1))) & (modulus - 1);
			_state = (65539 * (_state & (modulus - 1))) & (modulus - 1);
		}
	};

public:
	GeneratorRANDU(int complexity = 1) : Generator(complexity) {};

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

