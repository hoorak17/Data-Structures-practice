#include <memory>
#include "TreeNode.h"


template <typename T>
TreeNode<T>::TreeNode();

template <typename T>
TreeNode<T>::TreeNode(const T& anItem);

template <typename T>
TreeNode<T>::TreeNode(const T& anItem, std::shared_ptr<TreeNode<T>> leftPtr, std::shared_ptr<TreeNode<T>> rightPtr);
//생성자

template <typename T>
void TreeNode<T>::setItem(const T& nodeItem);

template <typename T>
T TreeNode<T>::getItem() const;

//아이템
template <typename T>
void TreeNode<T>::setLeftChildPtr(std::shared_ptr<TreeNode<T>> leftPtr);

template <typename T>
auto TreeNode<T>::getLeftChildPtr() const;
//왼쪽

template <typename T>
void TreeNode<T>::setRightChildPtr(std::shared_ptr<TreeNode<T>> rightPtr);

template <typename T>
auto TreeNode<T>::getRightChildPtr() const;
    //오른쪽

