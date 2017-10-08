#ifndef __GEN4_H
#define __GEN4_H

#include "generator.h"

class GeneratorJANO : public Generator 
{
protected:

  void update() { 
     for (int i = 0; i < _complexity; i++)
     {
		 //ak je posledny bit 1 tak shiftni o 1 doprava a zoxoruj s x^64 + x^4 + x.. + 1, inak to shiftni doprava
		 // implementacia lfsr podla Fr. matematika Gaulois, to iste ako standardny LFSR len rychlejsi
		 // nie je to cryptographically secure ale to nikto riesit nebude nikdy

		 unsigned char lsb = _state & 1;
		 _state >>= 1;
		 _state ^= (-lsb) & 0x800000000000000D;
		 
		
		 //_state = (_state & 1) ? ((_state >> 1) ^ 0x800000000000000D) : (_state >> 1);
		 
     }
  };

public:
	GeneratorJANO(int complexity = 1) : Generator(complexity) {};

  unsigned char nextByte() {
     update();
     return (unsigned char)  _state;
  }

  //uprava aby to nezhorelo ked sa zada seed 0
  void init(unsigned long long seed) { 
	  _state = seed | 1;
  }
  
};


#endif //__GEN_H
