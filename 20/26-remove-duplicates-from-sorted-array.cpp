#include <vector>
#include <ranges>

class Solution
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        // `prev_number`:= 101, 101 is out of range of posabilities for any `n` in `nums`
        int k{0}, prev_number{101};

        for (const auto &[i, n] : std::views::enumerate(nums))
        {
            if (n == prev_number)
            {
                k++;
            }

            nums[i - k] = n;
            prev_number = n;
        }

        return nums.size() - k;
    }
};