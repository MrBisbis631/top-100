/*
Exercise:
You are given a string consisting of the characters (, ), {, }, [, ], <, and >.
Your task is to determine whether the string is valid. A string is considered valid if:
1. Every opening parenthesis has a corresponding closing parenthesis of the same type.
    • For example: ( matches ), { matches }, [ matches ], and < matches >.
2. Parentheses are closed in the correct order.
    • For example: <({[]})> is valid, but <({[})]> is not.
*/

#include <stack>
#include <string>
#include <iostream>
#include <iomanip>

bool is_valid_parentheses(const std::string &);

int main(int argc, char const *argv[])
{
    std::string input;

    std::cin >> input;

    std::cout << (is_valid_parentheses(input) ? "legal" : "illegal");

    return 0;
}

bool is_valid_parentheses(const std::string &str)
{
    std::stack<char> s;

    for (char c : str)
    {
        if (c == '(' || c == '{' || c == '[' || c == '<')
        {
            s.push(c);
        }
        else if (c == ')' || c == '}' || c == ']' || c == '>')
        {
            if (s.empty())
            {
                return false;
            }

            auto last_par{s.top()};

            if ((c == ')' && last_par != '(') || (c == '}' && last_par != '{') || (c == ']' && last_par != '[') || (c == '>' && last_par != '<'))
            {
                return false;
            }

            s.pop();
        }
    }

    return s.empty();
}