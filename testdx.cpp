#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()

{

	ifstream ifs("test.txt");

	char str[256];

	if (ifs.fail())

	{

		std::cerr << "Ž¸”s" << std::endl;

		return -1;

	}

	while (ifs.getline(str, 256 - 1))

	{

		std::cout << "[" << str << "]" << std::endl;

	}

	return 0;

}