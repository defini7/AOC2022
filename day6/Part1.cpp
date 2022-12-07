#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <algorithm>

int main()
{
    std::ifstream file("input.txt");
	if (!file.is_open()) return 1;

    std::string sLine;
    std::getline(file, sLine);

    size_t nProcessedChars = 0;
    for (size_t i = 0; i < sLine.length(); i++)
    {
        std::string sMsg = std::string(sLine.begin() + i, sLine.begin() + i + 4);

        size_t nValidChars = 0;
        for (auto& c : sMsg)
        {
            if (std::count(sMsg.begin(), sMsg.end(), c) == 1)
                nValidChars++;
        }

        if (nValidChars == 4)
        {
            nProcessedChars = i + 4;
            break;
        }

    }

    std::cout << nProcessedChars << std::endl;

    return 0;
}
