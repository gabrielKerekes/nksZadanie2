#ifndef __GEN0_H
#define __GEN0_H

#include "generator.h"

class DummyGen : public Generator
{
protected:

	void update()
	{
		unsigned long long tmp = 0;

		for (int i = 0; i < _complexity; i++)
		{
			tmp ^= (_state << 4);
			tmp |= (_state >> 60);
			_state = tmp;
		}
	};

public:
	DummyGen(int complexity = 1) : Generator(complexity) {};

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


#endif //__GEN_H
