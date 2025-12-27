#include <iostream>
#include "BinaryTree.h"
void visit(double& value) { std::cout << value << " "; }

int main() {
    BinaryTree<double> tree;
    double value;
    std::cout << "Enter doubles:\n";
    
    while (std::cin >> value) {
        tree.add(value);
    }

    std::cout << "Preorder traversal: ";
    tree.preorderTraverse(visit);
    std::cout << std::endl;

    std::cout << "Inorder traversal: ";
    tree.inorderTraverse(visit);
    std::cout << std::endl;

    std::cout << "Postorder traversal: ";
    tree.postorderTraverse(visit);
    std::cout << std::endl;

    return 0;
}