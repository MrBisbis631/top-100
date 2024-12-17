#include <iostream>

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

int main()
{
    info *head = new info(3);
    head->next = new info(1);
    head->next->next = new info(2);
    head->next->next->next = new info(4);

    std::cout << "Original list: ";
    for (info *node = head; node != nullptr; node = node->next)
    {
        std::cout << node->_data << " ";
    }
    std::cout << std::endl;

    sort(head);

    std::cout << "Sorted list: ";
    for (info *node = head; node != nullptr; node = node->next)
    {
        std::cout << node->_data << " ";
    }
    std::cout << std::endl;

    // Free allocated memory
    while (head != nullptr)
    {
        info *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

// int main(int argc, char const *argv[])
// {
//     info *head{nullptr};

//     int number;
//     while (std::cin >> number)
//     {
//         info *new_node = new info(number);
//         new_node->next = head;
//         head = new_node;
//     }

//     sort(head);

//     for (info *node = head; node != nullptr; node = node->next)
//     {
//         std::cout << node->_data << " ";
//     }

//     return 0;
// }
