#include <ranges>
#include <string>

class Solution
{
public:
    bool isSubsequence(std::string &s, std::string &t)
    {
        size_t s_visitor{0}, s_size{s.size()};

        if (s == "")
        {
            return true;
        }

        for (char c : t)
        {
            if (s[s_visitor] == c)
            {
                s_visitor++;

                if (s_visitor == s_size)
                {
                    return true;
                }
            }
        }

        return false;
    }
};