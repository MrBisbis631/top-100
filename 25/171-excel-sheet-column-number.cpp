#include <algorithm>
#include <cmath>
#include <ranges>
#include <string>

class Solution
{
public:
    int titleToNumber(std::string columnTitle)
    {
        auto colNumber{0}, base{26};

        std::reverse(columnTitle.begin(), columnTitle.end());

        for (const auto &[i, c] : std::views::enumerate(columnTitle))
        {
            colNumber += (c - 'A' + 1) * std::pow(base, i);
        }

        return colNumber;
    }
};