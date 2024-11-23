#include <string>
#include <vector>

class Solution
{
public:
    bool isIsomorphic(std::string &s, std::string &t)
    {
        auto s_size{s.size()}, t_size{t.size()};
        auto s_indexes{std::vector(255, 0)}, t_indexes{std::vector(255, 0)};

        if (s_size != t_size)
        {
            return false;
        }

        for (auto i{0}; i < s_size; i++)
        {
            if (s_indexes[s[i]] != t_indexes[t[i]])
            {
                return false;
            }

            s_indexes[s[i]] = i + 1;
            t_indexes[t[i]] = i + 1;
        }

        return true;
    }
};