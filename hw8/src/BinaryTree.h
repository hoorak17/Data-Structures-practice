#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__
#include <memory>

#include "TreeNode.h"

template <typename T>
class BinaryTree {
   using TreePtr = std::shared_ptr<TreeNode<T>>;

private:

 TreePtr rootPtr;


protected:

   int getHeightHelper(TreePtr subTreePtr) const;
 // 재귀적으로 새로운 노드를 좌 -> 우 순서로 추가하여 트리의 균형을 유지한다.
   auto balancedAdd(TreePtr subTreePtr, TreePtr itemNodePtr);
 // oldTreeRootPtr 를 루트로 하는 트리를 복사하고 그 복사본의 포인터를 반환한다.
   TreePtr copyTree(const TreePtr oldTreeRootPtr) const;
 // 재귀 순회 헬퍼 함수
   void preorderHelper(std::function<void(T&)> visit, TreePtr treePtr) const;
   void inorderHelper(std::function<void(T&)> visit, TreePtr treePtr) const;
   void postorderHelper(std::function<void(T&)> visit, TreePtr treePtr) const;


public:
 /*
 생성자
 */
   BinaryTree();
   BinaryTree(const T& rootItem);
   BinaryTree(const T& rootItem, const TreePtr leftTreePtr,
               const TreePtr rightTreePtr);
   BinaryTree(const BinaryTree<T>& aTree);
 /*
 Interface
 */
   int getHeight() const { return getHeightHelper(rootPtr); }
   bool add(const T& newData);
/*
 순회 함수
 */
   void preorderTraverse(void visit(T&)) const {
      preorderHelper(visit, rootPtr);
   };
   void inorderTraverse(void visit(T&)) const { inorderHelper(visit, rootPtr); };
   void postorderTraverse(void visit(T&)) const {
   postorderHelper(visit, rootPtr);
   };
 // 추가 실습(optional)
 // void iterativeInorderTraverse(std::function<void(T&)> visit) const;

};

#include "BinaryTree.cpp"
#endif // __BINARYTREE_H__