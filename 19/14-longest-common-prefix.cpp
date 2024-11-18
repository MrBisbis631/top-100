#include <string>
#include <vector>

class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs)
    {
        auto first_str{strs[0]};
        auto common_prefix_index{0}, strs_size{static_cast<int>(strs.size())};

        if (strs_size == 1)
        {
            return first_str;
        }

        for (auto i{1}; strs[i].size() > common_prefix_index; i = (i + 1 == strs_size) ? 1 : i + 1)
        {
            if (strs[i][common_prefix_index] == first_str[common_prefix_index])
            {
                if (i == strs_size - 1)
                {
                    common_prefix_index++;
                }
            }
            else
            {
                break;
            }
        }

        return first_str.substr(0, common_prefix_index);
    }
};
