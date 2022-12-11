#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>
#include <vector>
#include <set>

void Split(std::vector<std::string>& vecOutput, std::string sInput, std::string sDelimiter)
{
	size_t nStart = 0;
	size_t nEnd;

	vecOutput.clear();
	while ((nEnd = sInput.find(sDelimiter, nStart)) != std::string::npos)
	{
		vecOutput.push_back(sInput.substr(nStart, nEnd - nStart));
		nStart = nEnd + sDelimiter.length();
	}
	vecOutput.push_back(sInput.substr(nStart));
}

int main()
{
	std::ifstream fInput("input.txt");
	if (!fInput.is_open()) return 1;

	uint32_t nTotal = 0;

	int32_t nX = 1;
	uint32_t nCycles = 0;

	while (!fInput.eof())
	{
		std::string sLine;
		std::getline(fInput, sLine);

		std::vector<std::string> vecLine;
		Split(vecLine, sLine, " ");

		if (vecLine[0] == "noop")
		{
			nCycles++;
			if (std::set<int>({ 20, 60, 100, 140, 180, 220 }).count(nCycles) == 1)
				nTotal += nX * nCycles;
		}
		else if (vecLine[0] == "addx")
		{
			nCycles++;
			if (std::set<int>({ 20, 60, 100, 140, 180, 220 }).count(nCycles) == 1)
				nTotal += nX * nCycles;

			nCycles++;
			if (std::set<int>({ 20, 60, 100, 140, 180, 220 }).count(nCycles) == 1)
				nTotal += nX * nCycles;

			nX += std::stoi(vecLine[1]);
		}
	}

	std::cout << nTotal << std::endl;

	return 0;
}
