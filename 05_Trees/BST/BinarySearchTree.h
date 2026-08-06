#pragma once
#include "../TreeNode.h"

template<typename T>
class BinarySearchTree{
    private:
        TreeNode<T>* raiz;

        void insert(TreeNode<T>*& actual, T valor);
        bool remove(TreeNode<T>*& actual, T valor);

        TreeNode<T>* search(TreeNode<T>* actual, T valor);

        void inorder(TreeNode<T>* actual);
        void preorder(TreeNode<T>* actual);
        void postorder(TreeNode<T>* actual);

        void clear(TreeNode<T>*& actual);
        int size(TreeNode<T>* actual);
        int altura(TreeNode<T>* actual);

        int maximo(int val1, int val2);
        void printNivel(TreeNode<T>* actual, int nivel, int formato);
        void printConecciones(TreeNode<T>* actual, int nivel, int formato);
        int power(int base, int exponencial);

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
        int altura();

        void printTree();

};

#include "BinarySearchTree.tpp"