#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <tuple>

struct TupleHashFunc
{
	size_t operator()(const std::tuple<int, int>& t) const
	{
		return std::get<0>(t) ^ std::get<1>(t);
	}
};

int main()
{
	std::ifstream fInput("input.txt");
	if (!fInput.is_open()) return 1;
	
	std::tuple<int, int> tupH = { 0, 0 };
	std::tuple<int, int> tupT = { 0, 0 };

	std::unordered_map<char, int> mapDirR;

	mapDirR['L'] = 0;
	mapDirR['U'] = -1;
	mapDirR['R'] = 0;
	mapDirR['D'] = 1;

	std::unordered_map<char, int> mapDirC;

	mapDirC['L'] = -1;
	mapDirC['U'] = 0;
	mapDirC['R'] = 1;
	mapDirC['D'] = 0;

	std::unordered_set<std::tuple<int, int>, TupleHashFunc> setPath;

	while (!fInput.eof())
	{
		std::string sLine;
		std::getline(fInput, sLine);

		char cDir = sLine[0];
		size_t nStep = std::stoul(sLine.substr(sLine.find(' '), sLine.length() - 1));

		for (size_t _ = 0; _ < nStep; _++)
		{
			setPath.insert(tupT);

			tupH = { std::get<0>(tupH) + mapDirR[cDir], std::get<1>(tupH) + mapDirC[cDir] };

			int nDirR = std::get<0>(tupH) - std::get<0>(tupT);
			int nDirC = std::get<1>(tupH) - std::get<1>(tupT);

			if (abs(nDirR) >= 2 && abs(nDirC) >= 2)
			{
				tupT = {
					(std::get<0>(tupT) < std::get<0>(tupH)) ? std::get<0>(tupH) - 1 : std::get<0>(tupH) + 1,
					(std::get<1>(tupT) < std::get<1>(tupH)) ? std::get<1>(tupH) - 1 : std::get<1>(tupH) + 1
				};
			}
			else if (abs(nDirR) >= 2)
			{
				tupT = {
					(std::get<0>(tupT) < std::get<0>(tupH)) ? std::get<0>(tupH) - 1 : std::get<0>(tupH) + 1,
					std::get<1>(tupH)
				};
			}
			else if (abs(nDirC) >= 2)
			{
				tupT = {
					std::get<0>(tupH),
					(std::get<1>(tupT) < std::get<1>(tupH)) ? std::get<1>(tupH) - 1 : std::get<1>(tupH) + 1
				};
			}

			setPath.insert(tupT);
		}
	}

	std::cout << setPath.size() << std::endl;

	return 0;
}
