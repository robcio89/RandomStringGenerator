#include <iostream>
#include <time.h>
#include "generator.h"

int main()
{
	std::string file;
	unsigned int times;

	generator g;

	std::cout << "Enter file name: ";
	std::cin >> file;
	std::cout << "\n";

	std::cout << "How many words generate: ";
	std::cin >> times;
	std::cout << "\n";

	if (g.generate(file, times))
		std::cout << "File generated successfully\n";
	else
		std::cout << "Error";

	return 0;
}