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
void test_is_valid_parentheses(const std::string &, bool);

int main(int argc, char const *argv[])
{
    test_is_valid_parentheses("()", true);
    test_is_valid_parentheses("()[]{}", true);
    test_is_valid_parentheses("(]", false);
    test_is_valid_parentheses("([)]", false);
    test_is_valid_parentheses("{[]}", true);
    test_is_valid_parentheses("<({[]})>", true);
    test_is_valid_parentheses("<({[})]>", false);
    test_is_valid_parentheses("", true);
    test_is_valid_parentheses("(", false);
    test_is_valid_parentheses(")", false);
    test_is_valid_parentheses("({[<]})", false);
    test_is_valid_parentheses("a(bc", false);
    test_is_valid_parentheses("a{b}c", true);
    test_is_valid_parentheses("a[b]c", true);
    test_is_valid_parentheses("a<b>c", true);
    return 0;
}

void test_is_valid_parentheses(const std::string &input, bool expected)
{
    int width{8};

    std::cout << "input: " << std::setw(width) << input
              << ", result: " << std::setw(width) << (is_valid_parentheses(input) ? "valid" : "invalid")
              << ", should be: " << std::setw(width) << (expected ? "valid" : "invalid")
              << std::endl;
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