#include "generator.h"
#include <algorithm>
#include <fstream>
#include <random>

generator::generator()
{
}


generator::~generator()
{
}

std::string generator::generate_string(size_t length)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(1, size);

	auto randchar = []() -> char
	{
		const char charset[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
		const size_t max_index = (sizeof(charset) - 1);
		return charset[ rand() % max_index];
	};
	std::string str(length, 0);
	std::generate_n(str.begin(), length, randchar);
	return str;
}

bool generator::generate(std::string file_name, unsigned int times)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(1, size);

	if (file_name.empty())
		false;
	
	std::ofstream myfile(file_name);

	std::string str;

	if (!myfile.is_open())
	{
		return false;
	}

	while (times--)
	{
		myfile << generate_string(dist(mt));
	}
	myfile.close();

	return true;
}
