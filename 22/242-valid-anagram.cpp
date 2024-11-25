#include <string>
#include <vector>
#include <ranges>
#include <algorithm>

class Solution
{
public:
    bool isAnagram(std::string &s, std::string &t)
    {
        std::vector l_indexes(26, 0);

        if (s.size() != t.size())
        {
            return false;
        }

        for (auto i{0}; i < s.size(); i++)
        {
            ++l_indexes[s[i] - 'a'];
            --l_indexes[t[i] - 'a'];
        }

        return std::all_of(l_indexes.begin(), l_indexes.end(), [](int c)
                           { return c == 0; });
    }
};
