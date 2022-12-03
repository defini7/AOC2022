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
		std::string sLines[3];
		std::getline(file, sLines[0]);
		std::getline(file, sLines[1]);
		std::getline(file, sLines[2]);

		for (auto c1 : sLines[0])
			for (auto c2 : sLines[1])
				for (auto c3 : sLines[2])
					if (c1 == c2 && c1 == c3)
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
