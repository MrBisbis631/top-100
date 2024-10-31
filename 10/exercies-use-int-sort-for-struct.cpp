// Exercise: Implement a struct sorting using int sorting and the sorting must be stable
// This exercise demonstrates how to implement a stable sort for a struct using integer sorting.
// The strategy involves creating a delegate array where each element is a combination of the salary and the original index.
// This ensures that the sorting is stable, as the original indices are preserved in case of ties in salary.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ranges>
#include <climits>

typedef struct
{
    std::string name;
    int salary;
} employee;

const int index_size = sizeof(char) * 8;

void print_sort_employees(std::vector<employee> &employees)
{
    auto delegates = std::vector<int>(employees.size());

    for (auto i = 0; i < employees.size(); i++)
    {
        delegates[i] = ((employees[i].salary << index_size) | i);
        std::cout << ((employees[i].salary << index_size) | i) << " " << std::endl;
    }

    std::sort(delegates.begin(), delegates.end());

    for (auto i = 0; i < employees.size(); i++)
    {
        std::cout
            << "Name: "
            << employees[delegates[i] & CHAR_MAX].name
            << ", Salary: "
            << employees[delegates[i] & CHAR_MAX].salary
            << std::endl;
    }
}

int main()
{
    std::vector<employee> employees_vec = {
        {"John Doe", 50000},
        {"Jane Smith", 60000},
        {"John D", 50000},
        {"Emily Davis", 55000},
        {"Michael Brown", 70000}};

    print_sort_employees(employees_vec);

    return 0;
}
