#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <time.h>

std::string random_string(size_t length)
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
};

int main()
{
	std::string str;
	srand(time(NULL));

	for (int i{ 0 }; i < 100; ++i)
	{
		str += random_string(rand() % 10 + 1);
	}

	std::cout << str << std::endl;

	return 0;
}