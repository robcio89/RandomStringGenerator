#pragma once
#include <string>

class generator
{
public:
	generator();
	~generator();

	bool generate(std::string file_name, unsigned int times);

private:
	std::string generate_string(size_t length);
	size_t size{ 63 };
};

