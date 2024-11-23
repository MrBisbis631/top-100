#include <algorithm>
#include <string>
#include <vector>

class Solution
{
public:
    bool canConstruct(std::string &ransomNote, std::string &magazine)
    {
        auto l_count{std::accumulate(magazine.begin(), magazine.end(),
                                     std::vector(26, 0), [](auto vec, char c)
                                     {
                                         vec[c - 97]++;
                                         return vec; })};

        for (auto c : ransomNote)
        {
            l_count[c - 97]--;

            if (l_count[c - 97] < 0)
            {
                return false;
            }
        }

        return true;
    }
};