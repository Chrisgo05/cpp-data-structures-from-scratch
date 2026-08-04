#include <iostream>
#include "BinarySearchTree.h"

template<typename T>
BinarySearchTree<T>::BinarySearchTree(){
    raiz = nullptr;
}


template<typename T>
BinarySearchTree<T>::~BinarySearchTree(){
    clear();
}

template<typename T>
void BinarySearchTree<T>::insert(T valor){
    insert(raiz, valor);
}

template<typename T>
void BinarySearchTree<T>::insert(TreeNode<T>*& actual, T valor){
    if(actual == nullptr){
        actual = new TreeNode<T>(valor);

    }else if(valor < actual -> valor){
        insert(actual -> izquierda, valor);

    }else if(valor > actual -> valor){
        insert(actual -> derecha, valor);
        
    }
}

template<typename T>
bool BinarySearchTree<T>::remove(T valor){

}


template<typename T>
TreeNode<T>* BinarySearchTree<T>::search(T valor){
    return search(raiz, valor);
}

template<typename T>
TreeNode<T>* BinarySearchTree<T>::search(TreeNode<T>* actual, T valor){
    if(actual != nullptr && actual -> valor == valor){
        return actual;

    }else if(actual != nullptr && actual -> valor > valor){
        return search(actual -> izquierda, valor);

    }else if(actual != nullptr && actual -> valor < valor){
        return search(actual -> derecha, valor);

    }else{
        return nullptr;
    }
}

template<typename T>
TreeNode<T>* BinarySearchTree<T>::findMin(){
    TreeNode<T>* minimo = raiz;
    while(minimo != nullptr){
        if(minimo -> izquierda == nullptr){
            return minimo;
        }
        minimo = minimo -> izquierda;
    }
}

template<typename T>
TreeNode<T>* BinarySearchTree<T>::findMax(){
    TreeNode<T>* maximo = raiz;
    while(maximo != nullptr){
        if(maximo -> derecha == nullptr){
            return maximo;
        }
        maximo = maximo -> derecha;
    }
}


template<typename T>
void BinarySearchTree<T>::inorder(){

}

template<typename T>
void BinarySearchTree<T>::preorder(){

}
template<typename T>
void BinarySearchTree<T>::postorder(){

}


template<typename T>
void BinarySearchTree<T>::clear(){

}

template<typename T>
bool BinarySearchTree<T>::empty(){
    return raiz == nullptr;
}

template<typename T>
int BinarySearchTree<T>::size(){
    return size(raiz);
}

template<typename T>
int BinarySearchTree<T>::size(TreeNode<T>* actual){
    if(actual == nullptr){
        return 0;
    }
    
    return 1 + size(actual -> izquierda) + size(actual -> derecha);
}