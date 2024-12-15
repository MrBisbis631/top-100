#include <algorithm>
#include <ranges>
#include <vector>

class Solution
{
public:
    std::vector<int> productExceptSelf(std::vector<int> &nums)
    {
        std::vector<int> ans(nums.size(), 0);
        auto zeros_count{0};

        auto non_zero_global_prod = std::accumulate(
            nums.begin(), nums.end(), 1, [&zeros_count](auto acc, auto n)
            {
                if (n == 0) {
                    ++zeros_count;
                    return acc;
                }

                return acc * n; });

        if (zeros_count > 1)
        {
            return ans;
        }

        if (zeros_count == 1)
        {
            std::transform(nums.begin(), nums.end(), ans.begin(),
                           [non_zero_global_prod](auto n)
                           {
                               return n == 0 ? non_zero_global_prod : 0;
                           });
        }

        if (zeros_count == 0)
        {
            std::transform(nums.begin(), nums.end(), ans.begin(),
                           [non_zero_global_prod](auto n)
                           {
                               return non_zero_global_prod / n;
                           });
        }

        return ans;
    }
};