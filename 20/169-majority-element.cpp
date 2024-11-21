#include <vector>

class Solution
{
public:
    int majorityElement(std::vector<int> &nums)
    {
        int ocurencs{0}, curr_num{0};

        for (auto n : nums)
        {
            if (ocurencs == 0)
            {
                curr_num = n;
                ocurencs = 1;
            }
            else if (curr_num == n)
            {
                ocurencs++;
            }
            else
            {
                ocurencs--;
            }
        }

        return curr_num;
    }
};