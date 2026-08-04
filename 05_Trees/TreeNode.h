template<typename T>
struct TreeNode{
    T valor;

    TreeNode<T>* izquierda = nullptr;
    TreeNode<T>* derecha = nullptr;

    TreeNode(T valor){
        this -> valor = valor;
    }
};