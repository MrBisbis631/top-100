#include <algorithm>
#include <cmath>
#include <vector>

class Solution
{
public:
    int findDuplicate(std::vector<int> &nums)
    {
        auto dup{-1}, curr{0};

        for (auto n : nums)
        {
            curr = std::abs(n);

            if (nums[curr] < 0)
            {
                dup = curr;
                break;
            }

            nums[curr] *= -1;
        }

        std::transform(nums.begin(), nums.end(), nums.begin(),
                       [](auto n)
                       { return std::abs(n); });

        return dup;
    }
};