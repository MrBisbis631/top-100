#include "BinarySearchTree.h"
#include <iostream>

int main()
{
    BinarySearchTree bst;

    // Test insert
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    std::cout << "Inserted 10, 5, 15" << std::endl;

    // Test contains
    std::cout << "Contains 10: " << bst.contains(10) << " (should return 1)" << std::endl;
    std::cout << "Contains 5: " << bst.contains(5) << " (should return 1)" << std::endl;
    std::cout << "Contains 15: " << bst.contains(15) << " (should return 1)" << std::endl;
    std::cout << "Contains 20: " << bst.contains(20) << " (should return 0)" << std::endl;

    // // Test remove
    bst.remove(10);
    std::cout << "Removed 10" << std::endl;
    std::cout << "Contains 10: " << bst.contains(10) << " (should return 0)" << std::endl;

    // Test min and max
    std::cout << "Min: " << bst.min() << " (should return 5)" << std::endl;
    std::cout << "Max: " << bst.max() << " (should return 15)" << std::endl;

    // Test size
    std::cout << "Size: " << bst.size() << " (should return 2)" << std::endl;

    return 0;
}
