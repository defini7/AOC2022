#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <algorithm>

int main()
{
	std::ifstream file("input.txt");
	if (!file.is_open()) return 1;

	uint32_t nTotal = 0;

	while (!file.eof())
	{
		std::string sLine;
		std::getline(file, sLine);
		
		size_t nCommaAt = sLine.find(',');

		std::string sRange1 = sLine.substr(0, nCommaAt);
		std::string sRange2 = sLine.substr(nCommaAt + 1);

		size_t nHyphen1At = sRange1.find('-');
		size_t nHyphen2At = sRange2.find('-');

		std::pair<uint32_t, uint32_t> pairRanges[] = {
			std::make_pair(
				std::stoi(sRange1.substr(0, nHyphen1At)),
				std::stoi(sRange1.substr(nHyphen1At + 1))
			),
			std::make_pair(
				std::stoi(sRange2.substr(0, nHyphen2At)),
				std::stoi(sRange2.substr(nHyphen2At + 1))
			)
		};

		if (std::max(pairRanges[0].first, pairRanges[1].first) <= std::min(pairRanges[0].second, pairRanges[1].second))
			nTotal++;

	}

	std::cout << nTotal << std::endl;
}
