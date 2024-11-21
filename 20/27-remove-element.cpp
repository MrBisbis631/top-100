#include <ranges>
#include <vector>

class Solution
{
public:
    int removeElement(std::vector<int> &nums, int val)
    {
        int ocurencs{0};

        for (const auto &[i, n] : std::views::enumerate(nums))
        {
            if (n == val)
            {
                ocurencs++;
            }
            else if (ocurencs > 0)
            {
                nums[i - ocurencs] = n;
            }
        }

        return nums.size() - ocurencs;
    }
};