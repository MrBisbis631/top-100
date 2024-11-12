#include <cmath>
#include <ranges>
#include <vector>
#include <climits>

class Solution
{
public:
    int minCostConnectPoints(std::vector<std::vector<int>> &points)
    {
        int n{static_cast<int>(points.size())}, ans{0}, j{0};
        std::vector<int> distances(n, INT_MAX), vertexes(n);

        distances[0] = 0;
        vertexes[0] = 1;

        for (int _ : std::views::iota(0, n - 1))
        {
            int mini{INT_MAX}, mini_i{0};
            for (const auto &[i, p] : std::views::enumerate(points))
            {
                distances[i] =
                    std::min(distances[i], manhattan_distance(p, points[j]));

                if (vertexes[i] == 0 && mini > distances[i])
                {
                    mini = distances[i];
                    mini_i = i;
                }
            }

            vertexes[mini_i] = 1;
            ans += distances[mini_i];
            j = mini_i;
        }

        return ans;
    }

    int inline manhattan_distance(std::vector<int> p1, std::vector<int> p2)
    {
        return std::abs(p1[0] - p2[0]) + std::abs(p1[1] - p2[1]);
    }
};