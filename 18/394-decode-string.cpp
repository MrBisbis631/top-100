#include <cctype>
#include <ranges>
#include <sstream>
#include <stack>
#include <string>

class Solution
{
public:
    std::string decodeString(std::string &s)
    {
        std::stack<std::string> str_stack;
        std::stack<int> num_stack;
        std::string curr_str;
        int multiplier{0};

        for (char c : s)
        {
            if (std::isdigit(c))
            {
                multiplier = multiplier * 10 + (c - '0');
            }
            else if (c == '[')
            {
                num_stack.push(multiplier);
                str_stack.push(curr_str);

                multiplier = 0;
                curr_str.clear();
            }
            else if (c == ']')
            {
                int repeat_times{num_stack.top()};
                std::string decodedSegment{str_stack.top()};

                str_stack.pop();
                num_stack.pop();

                for (auto _ : std::views::iota(0, repeat_times))
                {
                    decodedSegment += curr_str;
                }

                curr_str = decodedSegment;
            }
            else
            {
                curr_str += c;
            }
        }

        return curr_str;
    }
};
