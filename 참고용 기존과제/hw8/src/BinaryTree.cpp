#include <memory>
#include <functional> 
#include "BinaryTree.h"

template <typename T>
using TreePtr = std::shared_ptr<TreeNode<T>>;


/*
 생성자 구현
*/
template <typename T>
BinaryTree<T>::BinaryTree() : rootPtr(nullptr) {
}

template <typename T>
BinaryTree<T>::BinaryTree(const T& rootItem) 
    : rootPtr(std::make_shared<TreeNode<T>>(rootItem)) {
}

template <typename T>
BinaryTree<T>::BinaryTree(const T& rootItem, const TreePtr LeftTreePtr, const TreePtr rightTreePtr)
    : rootPtr(std::make_shared<TreeNode<T>>(rootItem, LeftTreePtr, rightTreePtr)) {
}

template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& aTree) {
    rootPtr = copyTree(aTree.rootPtr);
}

/*
 Interface 함수 구현
*/

template <typename T>
bool BinaryTree<T>::add(const T& newData) {
    auto itemNodePtr = std::make_shared<TreeNode<T>>(newData);
    if (rootPtr == nullptr) {
        rootPtr = itemNodePtr;
    } else {
        rootPtr = balancedAdd(rootPtr, itemNodePtr);
    }
    return true;
}

/*
 protected 헬퍼 함수 구현
*/

template <typename T>
int BinaryTree<T>::getHeightHelper(TreePtr subTreePtr) const {
    if (subTreePtr == nullptr) {
        return 0;
    } else {
        // std::max 대신 직접 비교
        int leftHeight = getHeightHelper(subTreePtr->getLeftChildPtr());
        int rightHeight = getHeightHelper(subTreePtr->getRightChildPtr());
        
        if (leftHeight > rightHeight) {
            return 1 + leftHeight;
        } else {
            return 1 + rightHeight;
        }
    }
}

template <typename T>
auto BinaryTree<T>::balancedAdd(TreePtr subTreePtr, TreePtr itemNodePtr) {
    TreePtr<T> left = subTreePtr->getLeftChildPtr();
    TreePtr<T> right = subTreePtr->getRightChildPtr();

    if (getHeightHelper(left) <= getHeightHelper(right)) {
        if (left == nullptr) {
            subTreePtr->setLeftChildPtr(itemNodePtr);
        } else {
            subTreePtr->setLeftChildPtr(balancedAdd(left, itemNodePtr));
        }
    } 
    else {
        if (right == nullptr) {
            subTreePtr->setRightChildPtr(itemNodePtr);
        } else {
            subTreePtr->setRightChildPtr(balancedAdd(right, itemNodePtr));
        }
    }
    return subTreePtr;
}

template <typename T>
TreePtr<T> BinaryTree<T>::copyTree(const TreePtr oldTreeRootPtr) const {
    if (oldTreeRootPtr == nullptr) {
        return nullptr;
    }
void BinaryTree<T>::preorderHelper(std::function<void(T&)> visit, TreePtr treePtr) const {
    if (treePtr != nullptr) {
        T item = treePtr->getItem();
        visit(item); // Root
        preorderHelper(visit, treePtr->getLeftChildPtr()); // Left
        preorderHelper(visit, treePtr->getRightChildPtr()); // Right
    }
}

template <typename T>
void BinaryTree<T>::inorderHelper(std::function<void(T&)> visit, TreePtr treePtr) const {
    if (treePtr != nullptr) {
        inorderHelper(visit, treePtr->getLeftChildPtr()); // Left
        T item = treePtr->getItem();
        visit(item); // Root
        inorderHelper(visit, treePtr->getRightChildPtr()); // Right
    }
}

template <typename T>
void BinaryTree<T>::postorderHelper(std::function<void(T&)> visit, TreePtr treePtr) const {
    if (treePtr != nullptr) {
        postorderHelper(visit, treePtr->getLeftChildPtr()); // Left
        postorderHelper(visit, treePtr->getRightChildPtr()); // Right
        T item = treePtr->getItem();
        visit(item); // Root
    }
}    
    TreePtr<T> newTreePtr = std::make_shared<TreeNode<T>>(oldTreeRootPtr->getItem());
    newTreePtr->setLeftChildPtr(copyTree(oldTreeRootPtr->getLeftChildPtr()));
    newTreePtr->setRightChildPtr(copyTree(oldTreeRootPtr->getRightChildPtr()));
    
    return newTreePtr;
}

/*
 재귀 순회 헬퍼 함수 구현 (std::function 사용)
*/
