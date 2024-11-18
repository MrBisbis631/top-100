#include <string>

class Solution
{
public:
    int lengthOfLastWord(std::string &s)
    {
        auto start_i{s.size() - 1}, end_i{s.size() - 1}, n{s.size()};

        // find end
        for (auto i{n - 1}; i != -1; i--)
        {
            if (s[i] != ' ')
            {
                break;
            }

            start_i--;
            end_i--;
        }

        // find start
        for (auto i{end_i}; i != -1; i--)
        {
            if (s[i] == ' ')
            {
                break;
            }

            start_i--;
        }

        return end_i - start_i;
    }
};
