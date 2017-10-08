#include <cstdio>
#include <iostream>
#include <bitset>
#include <fstream>

#include "genLFSR.h"
#include "genJANO.h"
#include "genNLFSR.h"
#include "genRANDU.h"
#include "genXORSHIFT.h"
#include "genc.h"

const int NUM_OF_BYTES = 1000000;
const int NUM_OF_BITS = NUM_OF_BYTES * 8;

int countSetBits(unsigned char b)
{
	int numOfOnes = 0;
	for (auto i = 0; i < 8; i++)
	{
		numOfOnes += (b >> i) & 1;
	}

	return numOfOnes;
}

void testGenerator(Generator &generator, bool printOutput = false)
{
	auto sum = 0;

	auto begin = clock();

	for (auto i = 0; i < NUM_OF_BYTES; i++)
	{
		auto b = generator.nextByte();

		if (printOutput)
		{
			std::cout << std::bitset<8>(b) << " ";
		}

		sum += countSetBits(b);
	}

	auto end = clock();
	auto timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;

	std::cout << "Generator: " << typeid(generator).name() << std::endl;
	std::cout << "Bits: " << NUM_OF_BITS << std::endl;
	std::cout << "Ones: " << sum << std::endl;
	std::cout << "Difference: " << ((double)NUM_OF_BITS / (double)2) - sum << std::endl;
	std::cout << "% of ones: " << (double)sum / (double)(NUM_OF_BITS) << std::endl;
	std::cout << "Time: " << timeSpent << std::endl;
	std::cout << std::endl;
}

void runTests()
{
	srand(time(0));

	GeneratorLFSR genLFSR(10);
	genLFSR.init(time(0));
	testGenerator(genLFSR);

	GeneratorNLFSR genNLFSR(100);
	genNLFSR.init(time(0));
	testGenerator(genNLFSR, false);

	GeneratorJANO genJANO(100);
	genJANO.init(time(0));
	testGenerator(genJANO, false);

	GeneratorRANDU genRANDU(10);
	genRANDU.init(time(0));
	testGenerator(genRANDU);

	GeneratorXORSHIFT genXORSHIFT(10);
	genXORSHIFT.init(time(0));
	testGenerator(genXORSHIFT);

	GeneratorC genC(1);
	testGenerator(genC);
}

void generateSequences(Generator &generator)
{
	for (auto i = 0; i < 100; i++)
	{
		generator.init(i);

		std::ofstream fout;
		fout.open("output/file" + std::to_string(i) + ".data", std::ios::binary | std::ios::out);

		for (auto i = 0; i < NUM_OF_BYTES; i++)
		{
			auto b = generator.nextByte();
			fout.write((char*)&b, sizeof(b));
		}

		fout.close();
	}
}

int main()
{
	//runTests();

	GeneratorJANO genJANO(10);
	generateSequences(genJANO);

	std::getchar();

	return 0;
}
