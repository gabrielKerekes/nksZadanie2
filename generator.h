#ifndef __GENERATOR_H
#define __GENERATOR_H
#include <ctime>
#include <cstdlib>

class Generator
{
protected:
	unsigned long long _state;
	const int _complexity;

	virtual void update() = 0;

public:
	Generator(int complexity = 1) : _complexity(complexity), _state(0) { };

	virtual void init(unsigned long long seed) { _state = seed; };

	virtual unsigned char nextByte() = 0;

};

#endif //__GENERATOR_H
