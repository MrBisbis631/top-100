#include <vector>
#include <numeric>
#include <unordered_map>

class Solution
{
public:
  int minImpossibleOR(std::vector<int> &nums)
  {
    std::unordered_map<int, int> dp;
    for (int i: nums) dp[i] = 1;

    for (size_t i = 0; i < 32; i++)
    {
      if (!dp[1 << i]) return (1 << i);
    }

    return std::accumulate(nums.begin(), nums.end(), 0, std::bit_or<int>()) + 1;
  }
};
