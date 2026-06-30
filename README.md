# C++ Data Structures (From Scratch)

Repositorio personal donde documento mi aprendizaje de **C++** y la implementación manual de estructuras de datos desde cero, como parte de un curso guiado con ChatGPT.

El objetivo no es solo implementar estructuras funcionales, sino comprender su funcionamiento interno, practicar punteros y memoria dinámica, y analizar la complejidad de cada operación.

---

# 📊 Estado del proyecto

## 🧠 Fundamentos de C++

Ubicado en:


Basics/

Punteros  
- [✔️] Concepto y uso básico de punteros  
- [x] Punteros con nodos (linked list base)  
- [x] Uso de nullptr  
- [x] Paso por referencia con punteros  

Referencias  
- [x] Referencias simples (&)  
- [x] Referencias a punteros (Nodo*&)  
- [x] Modificación directa de variables externas  
- [x] Uso en estructuras dinámicas  

Memoria dinámica  
- [x] new y delete  
- [x] creación de nodos dinámicos  
- [x] liberación de memoria  
- [x] manejo de memoria en listas enlazadas  
- [x] prevención básica de memory leaks  

Stack (Array-based)  
- [x] push  
- [x] pop  
- [x] top  
- [x] empty  
- [x] size  

Queue (Array-based)  
- [x] enqueue  
- [x] dequeue  
- [x] front  
- [x] back  
- [x] empty  
- [x] size  

Templates  
- [ ] Concepto de templates  
- [ ] template<typename T>  
- [ ] estructuras genéricas (pendiente implementación)  

Ejercicios de repaso  
- [x] punteros básicos  
- [x] memoria dinámica  
- [x] listas enlazadas simples  
- [x] problemas de arrays  
- [x] segundo mayor en un arreglo  
- [ ] problemas mixtos de estructuras
---

## 🔗 Linked Lists/

### Singly Linked List
- [x] pushFront
- [x] popFront
- [x] pushBack
- [x] popBack
- [x] find
- [x] insertAfter
- [ ] insertBefore
- [ ] erase
- [ ] clear
- [ ] size
- [ ] reverse

### Doubly Linked List
- [ ] pushFront
- [ ] popFront
- [ ] pushBack
- [ ] popBack
- [ ] find
- [ ] insertAfter
- [ ] insertBefore
- [ ] erase
- [ ] clear
- [ ] size
- [ ] reverse

### Circular Linked List
- [ ] pushFront
- [ ] popFront
- [ ] pushBack
- [ ] popBack
- [ ] find
- [ ] insertAfter
- [ ] insertBefore
- [ ] erase
- [ ] clear
- [ ] size
- [ ] reverse

---

## 📦 Linear Structures/

### Stack
- [ ] push
- [ ] pop
- [ ] top
- [ ] empty
- [ ] size

### Queue
- [ ] enqueue
- [ ] dequeue
- [ ] front
- [ ] back
- [ ] empty
- [ ] size

---

## 🌳 Trees/

### Binary Search Tree (BST)
- [ ] insert
- [ ] remove
- [ ] search
- [ ] findMin
- [ ] findMax
- [ ] traversal (inorder / preorder / postorder)

### AVL Tree
- [ ] insert
- [ ] remove
- [ ] rotations (LL, RR, LR, RL)
- [ ] balance factor
- [ ] search

### Heap
- [ ] insert
- [ ] remove (extract min/max)
- [ ] heapify
- [ ] peek
- [ ] buildHeap

---

## 🗂 Hashing/

### Hash Table
- [ ] insert
- [ ] remove
- [ ] search
- [ ] hash function
- [ ] collision handling (chaining / open addressing)

---

## 🌐 Graphs/

### Graph
- [ ] addVertex
- [ ] addEdge
- [ ] removeVertex
- [ ] removeEdge
- [ ] BFS
- [ ] DFS
- [ ] shortest path (Dijkstra básico)

---

## 📂 Estructura del proyecto

```text
cpp-data-structures/
│
├── README.md
│
├── 01_Basics/
│   ├── Pointers/
│   ├── References/
│   ├── DynamicMemory/
│   ├── Templates/
│   ├── Arrays/
│   │   ├── stack_array.cpp
│   │   └── queue_array.cpp
│   └── Exercises/
│
├── 02_LinkedLists/
│   ├── SinglyLinkedList/
│   ├── DoublyLinkedList/
│   └── CircularLinkedList/
│
├── 03_LinearStructures/
│   ├── Stack/
│   └── Queue/
│
├── 04_Trees/
│   ├── BinarySearchTree/
│   ├── AVL/
│   └── Heap/
│
├── 05_HashTable/
│
└── 06_Graphs/
```

---

# 🎯 Objetivos

- Comprender el funcionamiento interno de las estructuras de datos.
- Implementarlas desde cero sin STL.
- Dominar punteros, referencias y memoria dinámica.
- Analizar complejidad temporal y espacial.
- Mejorar diseño de código y organización de proyectos.
- Documentar el proceso de aprendizaje.

---

# 🛠 Tecnologías

- C++17
- g++
- Visual Studio Code
- Git / GitHub

---

# 📖 Contenido del proyecto

Cada estructura incluye:

- Implementación desde cero
- Explicación de cada operación
- Casos especiales (`head`, `tail`, lista vacía`)
- Análisis de complejidad
- Código de prueba

---

# 🚀 Estado actual

Actualmente trabajando en:

## 🔗 Singly Linked List
- Operaciones básicas completadas parcialmente
- Próximos pasos: `erase` e `insertBefore`

---

# 📄 Nota

Este repositorio es educativo y documenta mi progreso en estructuras de datos mediante implementación manual en C++, sin uso de la STL.
