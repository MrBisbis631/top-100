#include <vector>
#include <string>
#include <numeric>

class Solution
{
public:
  int finalValueAfterOperations(std::vector<std::string> &operations)
  {
    return std::accumulate(operations.begin(), operations.end(), 0, [](int acc, std::string &op) {
      return acc + (op[1] == '+' ? 1 : -1);
    });
  }
};