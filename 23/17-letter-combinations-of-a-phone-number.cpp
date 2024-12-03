#include <algorithm>
#include <string>
#include <vector>

class Solution
{
private:
    std::vector<std::string> getLetters(char d)
    {
        switch (d)
        {
        case '2':
            return {"a", "b", "c"};
        case '3':
            return {"d", "e", "f"};
        case '4':
            return {"g", "h", "i"};
        case '5':
            return {"j", "k", "l"};
        case '6':
            return {"m", "n", "o"};
        case '7':
            return {"p", "q", "r", "s"};
        case '8':
            return {"t", "u", "v"};
        case '9':
            return {"w", "x", "y", "z"};
        default:
            return {" "};
        }
    }

public:
    std::vector<std::string> letterCombinations(std::string &digits)
    {
        std::vector<std::string> res, temp;

        if (digits.empty())
        {
            return {};
        }

        res = getLetters(digits[0]);

        for (auto it{digits.begin() + 1}; it != digits.end(); ++it)
        {
            temp.clear();

            for (const auto &s : res)
            {

                for (const auto &c : getLetters(*it))
                {
                    temp.push_back(s + c);
                }
            }

            res = temp;
        }

        return res;
    }
};