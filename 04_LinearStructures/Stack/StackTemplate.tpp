template<typename T>
StackTemplate<T>::StackTemplate(){}


template<typename T>
void StackTemplate<T>::push(T valor){
    lista.pushFront(valor);
}

template<typename T>
bool StackTemplate<T>::pop(T& valor){
    return lista.popFront(valor);
}

template<typename T>
bool StackTemplate<T>::top(T& valor){
    return lista.front(valor);
}

template<typename T>
int StackTemplate<T>::size(){
    return lista.size();
}
template<typename T>
bool StackTemplate<T>::empty(){
    return lista.size() == 0;
}