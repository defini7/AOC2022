#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <deque>
#include <stack>

int main()
{
    std::ifstream file("input.txt");
	if (!file.is_open()) return 1;

    std::stack<char> stkStacks[9];

    // Cheat a little bit
    stkStacks[0] = std::stack(std::deque<char>({
        'T', 'P', 'Z', 'C',
        'S', 'L', 'Q', 'N'
    }));

    stkStacks[1] = std::stack(std::deque<char>({
        'L', 'P', 'T', 'V',
        'H', 'C', 'G'
    }));

    stkStacks[2] = std::stack(std::deque<char>({
        'D', 'C', 'F', 'Z',
    }));

    stkStacks[3] = std::stack(std::deque<char>({
        'G', 'W', 'T', 'D',
        'L', 'M', 'V', 'C'
    }));

    stkStacks[4] = std::stack(std::deque<char>({
        'P', 'W', 'C'
    }));

    stkStacks[5] = std::stack(std::deque<char>({
        'P', 'F', 'J', 'D',
        'C', 'T', 'S', 'Z'
    }));

    stkStacks[6] = std::stack(std::deque<char>({
        'V', 'W', 'G', 'B', 'D'
    }));

    stkStacks[7] = std::stack(std::deque<char>({
        'N', 'J', 'S', 'Q', 'H', 'W'
    }));

    stkStacks[8] = std::stack(std::deque<char>({
        'R', 'C', 'Q', 'F', 'S', 'L', 'V'
    }));

    while (!file.eof())
    {
        std::string sLine;
        std::getline(file, sLine);

        size_t nAfterMove = sLine.find("move") + 5;
        size_t nCount = std::stoul(sLine.substr(nAfterMove, sLine.find_first_of(' ', nAfterMove) - 1));

        size_t nAfterFrom = sLine.find("from") + 5;
        size_t nFrom = std::stoul(sLine.substr(nAfterFrom, sLine.find_first_of(' ', nAfterFrom) - 1));

        size_t nAfterTo = sLine.find("to") + 3;
        size_t nTo = std::stoul(sLine.substr(nAfterTo, sLine.find_first_of(' ', nAfterTo) - 1));

        for (size_t _ = 0; _ < nCount; _++)
        {
            char c = stkStacks[nFrom - 1].top();
            stkStacks[nFrom - 1].pop();
            stkStacks[nTo - 1].push(c);
        }
    }

    for (size_t i = 0; i < 9; i++)
        std::cout << stkStacks[i].top();

    std::cout << std::endl;

    return 0;
}
