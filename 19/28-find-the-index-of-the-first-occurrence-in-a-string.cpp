#include <ranges>
#include <string>

class Solution
{
public:
    int strStr(std::string &haystack, std::string &needle)
    {
        auto haystack_size{haystack.size()}, needle_size{needle.size()};

        if (haystack_size < needle_size)
        {
            return -1;
        }

        for (int i = 0; i <= haystack_size - needle_size; i++)
        {
            if (haystack.substr(i, needle_size) == needle)
            {
                return i;
            }
        }

        return -1;
    }
};
