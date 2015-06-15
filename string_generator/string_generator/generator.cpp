#include "generator.h"
#include <random>
#include <algorithm>
#include <fstream>
#include <time.h>

generator::generator()
{
}


generator::~generator()
{
}

std::string generator::generate_string(size_t length)
{
	auto randchar = []() -> char
	{
		const char charset[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
		const size_t max_index = (sizeof(charset) - 1);
		return charset[rand() % max_index];
	};
	std::string str(length, 0);
	std::generate_n(str.begin(), length, randchar);
	return str;
}

bool generator::generate(std::string file_name, unsigned int times)
{
	if (file_name.empty())
		false;
	
	std::ofstream myfile(file_name);

	std::string str;
	srand(time(NULL));

	if (myfile.is_open())
	{
		while (times--)
		{
			myfile << generate_string(rand() % size);
			myfile << " ";
		}
		myfile.close();
		return true;
	}
	else
		false;
}
