#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <unordered_map>

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
	std::ifstream file("input.txt");
	if (!file.is_open()) return 1;

	std::unordered_map<std::string, size_t> mapFileSystem;
	std::vector<std::string> vecPath;

	while (!file.eof())
	{
		std::string sLine;
		std::getline(file, sLine);
		
		std::vector<std::string> vecLine;
		Split(vecLine, sLine, " ");

		if (vecLine[1] == "cd")
		{
			if (vecLine[2] == "..")
				vecPath.pop_back();
			else
				vecPath.push_back(vecLine[2]);
		}
		else if (vecLine[1] == "ls")
		{
			continue;
		}
		else
		{
			try
			{
				size_t nSize = std::stoul(vecLine[0]);
				
				for (size_t i = 0; i < vecPath.size() + 1; i++)
				{
					std::string sPath = "";
					for (size_t j = 0; j < i; j++)
						sPath.append(vecPath[j]);

					mapFileSystem[sPath] += nSize;
				}

			}
			catch (...) {}
		}

	}

	size_t nUsed = mapFileSystem["/"];
	size_t nRequired = nUsed - 40000000;
	size_t nTotal = -1;

	for (const auto& e : mapFileSystem)
	{
		if (e.second >= nRequired)
			nTotal = std::min(nTotal, e.second);
	}

	std::cout << nTotal << std::endl;

	return 0;
}
