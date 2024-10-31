#include <string>
#include <cmath>
#include <iterator>

class Solution
{
public:
  int scoreOfString(std::string s) {
    int score = 0;

    for (size_t i = 0; i < s.length() - 1; i++) {
      score += abs(s[i] - s[i + 1]);
    }

    return score;
  }
};
