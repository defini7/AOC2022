#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>

enum ScoreTable : uint32_t
{
	Rock = 1,
	Paper = 2,
	Scissors = 3,
	Lose = 0,
	Draw = 3,
	Win = 6
};

int main()
{
	std::ifstream file("input.txt");
	if (!file.is_open()) return 1;

	uint32_t nTotalScore = 0;

	while (!file.eof())
	{
		std::string sBuffer;
		std::getline(file, sBuffer);

		char cOpponent = sBuffer[0];
		char cYou = sBuffer[2];

		uint32_t nScore = (cYou - 'X') + 1;

		if (cOpponent == 'A')
		{
			if (cYou == 'X') nScore += Draw;
			if (cYou == 'Y') nScore += Win;
			if (cYou == 'Z') nScore += Lose;
		}

		if (cOpponent == 'B')
		{
			if (cYou == 'X') nScore += Lose;
			if (cYou == 'Y') nScore += Draw;
			if (cYou == 'Z') nScore += Win;
		}

		if (cOpponent == 'C')
		{
			if (cYou == 'X') nScore += Win;
			if (cYou == 'Y') nScore += Lose;
			if (cYou == 'Z') nScore += Draw;
		}

		nTotalScore += nScore;
	}

	std::cout << nTotalScore << std::endl;
}
