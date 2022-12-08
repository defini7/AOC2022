#include <iostream>
#include <string>
#include <fstream>

int main()
{
	std::ifstream fInput("input.txt");
	if (!fInput.is_open()) return 1;

	size_t nWidth = 0;
	size_t nHeight = 0;

	std::string sData = "";

	while (!fInput.eof())
	{
		std::string sLine;
		std::getline(fInput, sLine);

		sData.append(sLine);

		nWidth = sLine.length();
		nHeight++;
	}

	size_t nTotal = 0;

	nTotal += nWidth * 2;
	nTotal += nHeight * 2 - 4;

	auto Get = [&](size_t x, size_t y)
	{
		return size_t(sData[y * nWidth + x] - '0');
	};

	for (size_t x = 1; x < nWidth - 1; x++)
		for (size_t y = 1; y < nHeight - 1; y++)
		{
			size_t nTreeHeight = Get(x, y);

			bool bVisibleRowBefore = true;
			bool bVisibleRowAfter = true;
			bool bVisibleColBefore = true;
			bool bVisibleColAfter = true;

			for (size_t i = 0; i < x; i++)
			{
				if (Get(i, y) >= nTreeHeight)
					bVisibleRowBefore = false;
			}

			for (size_t i = x + 1; i < nWidth; i++)
			{
				if (Get(i, y) >= nTreeHeight)
					bVisibleRowAfter = false;
			}

			for (size_t j = 0; j < y; j++)
			{
				if (Get(x, j) >= nTreeHeight)
					bVisibleColBefore = false;
			}

			for (size_t j = y + 1; j < nHeight; j++)
			{
				if (Get(x, j) >= nTreeHeight)
					bVisibleColAfter = false;
			}

			if (bVisibleRowAfter || bVisibleRowBefore || bVisibleColAfter || bVisibleColBefore)
				nTotal++;
		}

	std::cout << nTotal << std::endl;

	return 0;
}
