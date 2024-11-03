#include <cmath>
#include <ranges>
#include <vector>

class Solution
{
public:
    bool canJump(std::vector<int> &nums)
    {
        int stp{0};

        for (const auto &[i, num] : std::views::enumerate(nums))
        {
            if (i > stp)
            {
                return false;
            }

            stp = std::max(stp, static_cast<int>(i + num));
        }

        return true;
    }
};
