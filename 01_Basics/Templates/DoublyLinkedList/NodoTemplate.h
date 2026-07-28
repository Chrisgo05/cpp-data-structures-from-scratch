template<typename T>
struct Nodo{
    T valor;
    Nodo<T>* siguiente = nullptr;
    Nodo<T>* anterior = nullptr;
};