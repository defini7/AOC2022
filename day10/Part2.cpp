#include <cmath>
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

	int32_t nX = 1;
	uint32_t nCycles = -1;

	constexpr size_t SCREEN_WIDTH = 40;
	constexpr size_t SCREEN_HEIGHT = 6;

	uint8_t nScreen[SCREEN_WIDTH * SCREEN_HEIGHT];
	std::memset(nScreen, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(uint8_t));

	while (!fInput.eof())
	{
		std::string sLine;
		std::getline(fInput, sLine);

		std::vector<std::string> vecLine;
		Split(vecLine, sLine, " ");

		auto UpdScreen = [&]()
		{
			nScreen[(nCycles / 40) * SCREEN_WIDTH + (nCycles % 40)] = (std::abs(nX - int32_t(nCycles % 40)) <= 1) ? '#' : '.';
		};

		if (vecLine[0] == "noop")
		{
			nCycles++;
			UpdScreen();
		}
		else if (vecLine[0] == "addx")
		{
			nCycles++;
			UpdScreen();

			nCycles++;
			UpdScreen();

			nX += std::stoi(vecLine[1]);
		}
	}

	for (size_t y = 0; y < SCREEN_HEIGHT; y++)
	{
		for (size_t x = 0; x < SCREEN_WIDTH; x++)
			std::putchar(nScreen[y * SCREEN_WIDTH + x]);
		std::putchar('\n');
	}

	return 0;
}
