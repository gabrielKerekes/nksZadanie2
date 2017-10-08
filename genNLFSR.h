#pragma once

#include <cstdlib>
#include "generator.h"

class GeneratorNLFSR : public Generator
{
private:
	int getBitFromNumber(unsigned long long number, int bitIndex)
	{
		return (number >> bitIndex) & 1;
	}

protected:
	void update()
	{
		unsigned long long tmp = 0;

		for (int i = 0; i < _complexity; i++)
		{
			tmp = ((_state >> 0) ^ (_state >> 2) ^ (_state >> 3) ^ (_state >> 5)) & 1;
			tmp = _state | ((getBitFromNumber(tmp, 17) & getBitFromNumber(tmp, 4)) << 29);
			tmp = (_state >> 1) | (tmp << 15);
			_state = tmp;
		}
	};

public:
	GeneratorNLFSR(int complexity = 1) : Generator(complexity) {};

	void init(unsigned long long seed)
	{
		_state = seed;
	}

	unsigned char nextByte()
	{
		update();
		return (unsigned char)_state;
	}

};

