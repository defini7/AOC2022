#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <algorithm>

int main()
{
	std::ifstream file("input.txt");
	if (!file.is_open()) return 1;

	uint32_t nLastCount = 0;

	uint32_t nTop1 = 0;
	uint32_t nTop2 = 0;
	uint32_t nTop3 = 0;

	while (!file.eof())
	{
		std::string sBuffer;
		std::getline(file, sBuffer);

		if (!sBuffer.empty())
			nLastCount += std::stoi(sBuffer);
		else
		{
			if (nTop1 < nLastCount)
			{
				std::swap(nTop2, nTop3);
				nTop2 = nTop1;
				nTop1 = nLastCount;
			}
			else if (nTop2 < nLastCount)
			{
				std::swap(nTop2, nTop3);
				nTop2 = nLastCount;
			}
			else if (nTop3 < nLastCount)
			{
				nTop3 = nLastCount;
			}

			nLastCount = 0;
		}
	}

	uint32_t nSum = nTop1 + nTop2 + nTop3;
	std::cout << nSum << std::endl;
}
