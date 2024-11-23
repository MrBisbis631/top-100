#include <regex>
#include <string>
#include <vector>
#include <algorithm>

class Solution
{
public:
    bool wordPattern(std::string &pattern, std::string &s)
    {
        std::regex re(" ");
        std::sregex_token_iterator s_it(s.begin(), s.end(), re, -1), s_end;
        auto pattern_it{pattern.begin()}, pattern_end{pattern.end()};
        std::vector<std::string> mapper(26, "");

        while (s_it != s_end && pattern_it != pattern_end)
        {
            if (mapper[*pattern_it - 97] == "")
            {
                if (std::any_of(mapper.begin(), mapper.end(), [&s_it](auto str)
                                { return str == *s_it; }))
                {
                    return false;
                }

                mapper[*pattern_it - 97] = *s_it;
            }
            else if (mapper[*pattern_it - 97] != *s_it)
            {
                return false;
            }

            s_it++;
            pattern_it++;
        }

        return s_it == s_end && pattern_it == pattern_end;
    }
};