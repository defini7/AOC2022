#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>

int main()
{
	std::ifstream file("input.txt");
	if (!file.is_open()) return 1;

	uint32_t nLastCount = 0;
	uint32_t nMax = 0;

	while (!file.eof())
	{
		std::string sBuffer;
		std::getline(file, sBuffer);

		if (!sBuffer.empty())
			nLastCount += std::stoi(sBuffer);
		else
		{
			if (nMax < nLastCount)
				nMax = nLastCount;

			nLastCount = 0;
		}
	}

	std::cout << nMax << std::endl;
}
