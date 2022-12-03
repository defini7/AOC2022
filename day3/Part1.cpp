#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>

int main()
{
	std::ifstream file("input.txt");
	if (!file.is_open()) return 1;

	uint32_t nSum = 0;

	while (!file.eof())
	{
		std::string sBuffer;
		std::getline(file, sBuffer);

		std::string sComps[] = {
			std::string(sBuffer.begin(), sBuffer.end() - sBuffer.length() / 2),
			std::string(sBuffer.begin() + sBuffer.length() / 2, sBuffer.end())
		};

		for (auto c1 : sComps[0])
			for (auto c2 : sComps[1])
				if (c1 == c2)
				{
					nSum += c1 - 'a' + 1;

					if (std::isupper(c1))
						nSum += 29 * 2;

					goto out;
				}
	out:
		continue;
	}

	std::cout << nSum << std::endl;
}
