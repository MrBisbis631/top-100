#include <ranges>
#include <vector>

class Solution
{
public:
    void moveZeroes(std::vector<int> &nums)
    {
        auto total_zeros{0};

        for (const auto &[i, n] : std::views::enumerate(nums))
        {
            if (n == 0)
            {
                ++total_zeros;
            }
            else
            {
                nums[i - total_zeros] = n;
            }
        }

        for (auto it{nums.rbegin()}; it != nums.rbegin() + total_zeros; ++it)
        {
            *it = 0;
        }
    }
};