#include <iostream>
#include <sstream>

struct info
{
    int _data;
    info *next;

    info(int data) : _data(data), next(nullptr) {}
};

void sort(info *&head)
{
    if (!head || !head->next)
        return;

    info *sorted = nullptr;

    while (head)
    {
        info *current = head;
        head = head->next;

        if (!sorted || sorted->_data >= current->_data)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            info *temp = sorted;
            while (temp->next && temp->next->_data < current->_data)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }

    head = sorted;
}

int main(int argc, char const *argv[])
{
    info *head{nullptr};

    int number;
    while (std::cin >> number)
    {
        info *new_node = new info(number);
        new_node->next = head;
        head = new_node;
    }

    sort(head);

    for (info *node = head; node != nullptr; node = node->next)
    {
        std::cout << node->_data << " ";
    }

    return 0;
}
