#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>

/**
* A, X - Rock
* B, Y - Paper
* C, Z - Scissors
*/

enum ScoreTableCodes : uint32_t
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
		char cResult = sBuffer[2];

		if (cResult == 'X') nTotalScore += Lose;
		if (cResult == 'Y') nTotalScore += Draw;
		if (cResult == 'Z') nTotalScore += Win;

		if (cOpponent == 'A') // Rock
		{
			if (cResult == 'X') nTotalScore += Scissors;
			if (cResult == 'Y') nTotalScore += Rock;
			if (cResult == 'Z') nTotalScore += Paper;
		}
		else if (cOpponent == 'B') // Paper
		{
			if (cResult == 'X') nTotalScore += Rock;
			if (cResult == 'Y') nTotalScore += Paper;
			if (cResult == 'Z') nTotalScore += Scissors;
		}
		else if (cOpponent == 'C') // Scissors
		{
			if (cResult == 'X') nTotalScore += Paper;
			if (cResult == 'Y') nTotalScore += Scissors;
			if (cResult == 'Z') nTotalScore += Rock;
		}
	}

	std::cout << nTotalScore << std::endl;
}
