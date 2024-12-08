#include <ranges>
#include <unordered_set>
#include <vector>

class Solution
{
public:
    bool containsNearbyDuplicate(std::vector<int> &nums, int k)
    {
        auto low{0};
        std::unordered_map<int, int> window;

        for (const auto &[i, n] : std::views::enumerate(nums))
        {
            if (i - low > k)
            {
                --window[nums[low]];
                ++low;
            }

            if (++window[n] > 1)
            {
                return true;
            }
        }

        return false;
    }
};