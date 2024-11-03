#include <ranges>
#include <algorithm>
#include <vector>

class Solution
{
public:
    int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost)
    {
        int start_index{0}, tank{0};
        auto total_gas = std::accumulate(gas.begin(), gas.end(), 0);
        auto total_cost = std::accumulate(cost.begin(), cost.end(), 0);

        if (total_cost > total_gas)
        {
            return -1;
        }

        for (const auto &[i, gas_i] : std::views::enumerate(gas))
        {
            tank += gas_i - cost[i];

            if (tank < 0)
            {
                tank = 0;
                start_index = i + 1;
            }
        }

        return start_index;
    }
};
