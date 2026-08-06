#include <iostream>

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
    if(raiz == nullptr){
        return false;
    }
    return remove(raiz, valor);
}

template<typename T>
bool BinarySearchTree<T>::remove(TreeNode<T>*& actual, T valor){
    if(actual == nullptr){
        return false;
    }else if(valor < actual -> valor){
        return remove(actual -> izquierda, valor);

    }else if(valor > actual -> valor){
        return remove(actual -> derecha, valor);

    }else if(valor == actual -> valor){

        if(actual -> izquierda == nullptr && actual -> derecha == nullptr){
            delete actual;
            actual = nullptr;

        }else if(actual -> izquierda != nullptr && actual -> derecha != nullptr){
            TreeNode<T>* padrasto = findMin(actual -> derecha);
            actual -> valor = padrasto -> valor;
        
            return remove(actual -> derecha, padrasto -> valor);

        }else if(actual -> izquierda != nullptr || actual -> derecha != nullptr){
            TreeNode<T>* huerfanito;
        
            if(actual -> izquierda != nullptr && actual -> derecha == nullptr){
                huerfanito = actual -> izquierda;
        
            }else{
                huerfanito = actual -> derecha;
            }
        
            delete actual;
            actual = huerfanito;
        }

        return true;
    }
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
    if(raiz == nullptr){
        return nullptr;
    }
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
    if(raiz == nullptr){
        return nullptr;
    }
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
    inorder(raiz);
}

template<typename T>
void BinarySearchTree<T>::inorder(TreeNode<T>* actual){
    if(actual == nullptr){
        return;
    }

    inorder(actual -> izquierda);
    std::cout << actual -> valor << " ";
    inorder(actual -> derecha);

}

template<typename T>
void BinarySearchTree<T>::preorder(){
    preorder(raiz);
}

template<typename T>
void BinarySearchTree<T>::preorder(TreeNode<T>* actual){
    if(actual == nullptr){
        return;
    }

    std::cout << actual -> valor << " ";
    preorder(actual -> izquierda);
    preorder(actual -> derecha);
}

template<typename T>
void BinarySearchTree<T>::postorder(){
    postorder(raiz);
}

template<typename T>
void BinarySearchTree<T>::postorder(TreeNode<T>* actual){
    if(actual == nullptr){
        return;
    }

    postorder(actual -> izquierda);
    postorder(actual -> derecha);
    std::cout << actual -> valor << " ";
}


template<typename T>
void BinarySearchTree<T>::clear(){
    clear(raiz);
    raiz = nullptr;
}

template<typename T>
void BinarySearchTree<T>::clear(TreeNode<T>*& actual){
    if(actual == nullptr){
        return;
    }

    clear(actual -> izquierda);
    clear(actual -> derecha);
    delete actual;
    actual = nullptr;

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

template<typename T>
int BinarySearchTree<T>::maximo(int val1, int val2){
    if(val1 > val2){
        return val1;
    }else{
        return val2;
    }
}

template<typename T>
int BinarySearchTree<T>::altura(){
    return altura(raiz);
}

template<typename T>
int BinarySearchTree<T>::altura(TreeNode<T>* actual){
    if(actual == nullptr){
        return -1;
    }else{
        int altIzquierda = altura(actual -> izquierda);
        int altDerecha = altura(actual -> derecha);

        return maximo(altIzquierda, altDerecha) + 1;
    }
}

template<typename T>
void BinarySearchTree<T>::printTree(){
    int arboltura = altura();


    for(int nivel = 0; nivel <= arboltura; nivel++){ 
        int formato = power(2, arboltura - nivel);

        for(int i = 0; i < formato; i++){
            std::cout << " ";
        }

        printNivel(raiz, nivel, formato);
        std::cout << std::endl;
        printConecciones(raiz, nivel, formato);
        std::cout << std::endl;
    }
}

template<typename T>
void BinarySearchTree<T>::printNivel(TreeNode<T>* actual, int nivel, int formato){
    if(actual == nullptr){
        return;

    }else if(nivel == 0){
        std::cout << actual -> valor;
        for(int i = 0; i < formato; i++){
            std::cout << " ";
        }

    }else if(nivel > 0){
        printNivel(actual -> izquierda, nivel - 1, formato);
        printNivel(actual -> derecha, nivel - 1, formato);


    }
}

template<typename T>
void BinarySearchTree<T>::printConecciones(TreeNode<T>* actual, int nivel, int formato){
    int espacioExt = formato - 1;

    if(actual == nullptr){
        return;

    }else if(nivel == 0){
        if(actual -> izquierda != nullptr){
            for(int i = 0; i < espacioExt; i++){
                std::cout << " ";
            }
            std::cout << "/ ";
        }

        if(actual -> derecha != nullptr){
            std::cout << "\\  ";
        }

    }else if(nivel > 0){
        printConecciones(actual -> izquierda, nivel - 1, formato);
        printConecciones(actual -> derecha, nivel - 1, formato);
    }
}

template<typename T>
int BinarySearchTree<T>::power(int base, int exponencial){
    int resultado = 1;
    for(int i = 0; i < exponencial; i++){
        resultado *= base;
    }

    return resultado;
}