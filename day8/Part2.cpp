#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <tuple>

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

	size_t nMax = 0;

	auto Get = [&](size_t x, size_t y)
	{
		return size_t(sData[y * nWidth + x] - '0');
	};

	std::array<std::tuple<int, int>, 4> pairDirections = {
		std::make_tuple(0, 1), std::make_tuple(0, -1),
		std::make_tuple(1, 0), std::make_tuple(-1, 0)
	};

	for (size_t x = 0; x < nWidth; x++)
		for (size_t y = 0; y < nHeight; y++)
		{
			size_t nTreeHeight = Get(x, y);
			size_t nScore = 1;

			for (const auto& [dx, dy] : pairDirections)
			{
				size_t i = x + dx;
				size_t j = y + dy;

				size_t nDist = 0;

				while (((0 <= i && i < nWidth) && (0 <= j && j < nHeight)) && (Get(i, j) < nTreeHeight))
				{
					nDist++;

					i += dx;
					j += dy;

					if (((0 <= i && i < nWidth) && (0 <= j && j < nHeight)) && (Get(i, j) >= nTreeHeight))
						nDist++;
				}

				nScore *= nDist;
			}

			if (nMax < nScore)
				nMax = nScore;
		}

	std::cout << nMax << std::endl;

	return 0;
}
