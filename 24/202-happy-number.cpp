#include <unordered_set>

class Solution
{
public:
    int sub_sqr_digest(int n)
    {
        int sum{0}, dig{0};

        while (n > 0)
        {
            dig = n % 10;
            n /= 10;
            sum += dig * dig;
        }

        return sum;
    }

    bool isHappy(int n)
    {
        std::unordered_set prevs({n});
        int next{sub_sqr_digest(n)};

        while (next != 1)
        {
            if (prevs.contains(next))
            {
                return false;
            }

            prevs.insert(next);
            next = sub_sqr_digest(next);
        }

        return true;
    }
};