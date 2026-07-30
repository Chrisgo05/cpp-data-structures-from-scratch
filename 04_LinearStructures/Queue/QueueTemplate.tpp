template<typename T>
QueueTemplate<T>::QueueTemplate(){}

template<typename T>
void QueueTemplate<T>::enqueue(T valor){
    lista.pushBack(valor);
}

template<typename T>
bool QueueTemplate<T>::dequeue(T& valor){
    return lista.popFront(valor);
}

template<typename T>
bool QueueTemplate<T>::front(T& valor){
    return lista.front(valor);
}

template<typename T>
bool QueueTemplate<T>::back(T& valor){
    return lista.back(valor);
}

template<typename T>
int QueueTemplate<T>::size(){
    return lista.size();
}

template<typename T>
bool QueueTemplate<T>::empty(){
    return lista.size() == 0;
}