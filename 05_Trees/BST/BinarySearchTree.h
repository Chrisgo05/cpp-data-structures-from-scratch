#pragma once
#include "../TreeNode.h"

template<typename T>
class BinarySearchTree{
    private:
        TreeNode<T>* raiz;

        void insert(TreeNode<T>*& actual, T valor);

        TreeNode<T>* search(TreeNode<T>* actual, T valor);

        void inorder(TreeNode<T>* actual);
        void preorder(TreeNode<T>* actual);
        void postorder(TreeNode<T>* actual);

        void clear(TreeNode<T>*& actual);
        int size(TreeNode<T>* actual);

    public:
        BinarySearchTree();
        ~BinarySearchTree();

        void insert(T valor);
        bool remove(T valor);

        TreeNode<T>* search(T valor);
        TreeNode<T>* findMin();
        TreeNode<T>* findMax();

        void inorder();
        void preorder();
        void postorder();

        void clear();
        bool empty();
        int size();
};

#include "BinarySearchTree.tpp"