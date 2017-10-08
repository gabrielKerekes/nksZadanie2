#pragma once

#include <cstdlib>
#include "generator.h"

class GeneratorC : public Generator
{
protected:
	void update() {	};

public:
	GeneratorC(int complexity = 1) : Generator(complexity) {};

	void init(unsigned long long seed) { }

	unsigned char nextByte()
	{
		return (unsigned char)rand();
	}

};

