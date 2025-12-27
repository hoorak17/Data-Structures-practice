#ifndef __TREENODE_H__
#define __TREENODE_H__
#include <memory>


template <typename T>
class TreeNode {

private:
    T item;
    std::shared_ptr<TreeNode<T>> leftChildPtr;
    std::shared_ptr<TreeNode<T>> rightChildPtr;

public:
    TreeNode();
    TreeNode(const T& anItem);
    TreeNode(const T& anItem, std::shared_ptr<TreeNode<T>> leftPtr, std::shared_ptr<TreeNode<T>> rightPtr);
    //생성자

    void setItem(const T& nodeItem);
    T getItem() const;
    //아이템

    void setLeftChildPtr(std::shared_ptr<TreeNode<T>> leftPtr);
    auto getLeftChildPtr() const;
    //왼쪽

    void setRightChildPtr(std::shared_ptr<TreeNode<T>> rightPtr);
    auto getRightChildPtr() const;
    //오른쪽

}; // end TreeNode

#include "TreeNode.cpp"
#endif