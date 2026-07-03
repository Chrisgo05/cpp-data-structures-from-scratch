# C++ Data Structures (From Scratch)

Repositorio personal donde documento mi aprendizaje de **C++** y la implementación manual de estructuras de datos desde cero, como parte de un curso guiado con ChatGPT.

El objetivo no es solo implementar estructuras funcionales, sino comprender su funcionamiento interno, practicar punteros y memoria dinámica, y analizar la complejidad de cada operación.

---

# 📊 Estado del proyecto

## 🧠 Fundamentos de C++

Ubicado en:


## Basics/

Punteros  
- ✔️ Concepto y uso básico de punteros  
- ✔️ Punteros con nodos (linked list base)  
- ✔️ Uso de nullptr  
- ✔️ Paso por referencia con punteros  

Referencias  
- ✔️ Referencias simples (&)  
- ✔️ Referencias a punteros (Nodo*&)  
- ✔️ Modificación directa de variables externas  
- ✔️ Uso en estructuras dinámicas  

Memoria dinámica  
- ✔️ new y delete  
- ✔️ creación de nodos dinámicos  
- ✔️ liberación de memoria  
- ✔️ manejo de memoria en listas enlazadas  
- ✔️ prevención básica de memory leaks  

Stack (Array-based)  
- ✔️ push  
- ✔️ pop  
- ✔️ peek  
- [ ] empty  
- [ ] size  

Queue (Array-based)  
- ✔️ enqueue  
- ✔️ dequeue  
- [ ] front  
- [ ] back  
- [ ] empty  
- [ ] size  

Templates  
- [ ] Concepto de templates  
- [ ] template<typename T>  
- [ ] estructuras genéricas (pendiente implementación)  

Ejercicios de repaso  
- ✔️ buscar y modifcar con punteros en un arrya
- ✔️ buscar y modificar con referencias en un array
- ✔️ encontrar primera aparicion en un arreglo
- ✔️ encontrar mayor y poscicion
- ✔️ encontrar mayor en un arreglo
- ✔️ encontrar segundo mayor en un arreglo  
- ✔️ repaso arrays  
- [ ] problemas mixtos de estructuras
---

## 🔗 Linked Lists/

### Singly Linked List
- ✔️ pushFront
- ✔️ popFront
- ✔️ pushBack
- ✔️ popBack
- ✔️ find
- ✔️ insertAfter
- ✔️ print
- ✔️ findBefore
- ✔️ insertBefore
- ✔️ erase
- ✔️ clear
- ✔️ size
- ✔️ reverse

### Doubly Linked List
- ✔️ pushFront
- ✔️ popFront
- ✔️ pushBack
- ✔️ popBack
- ✔️ find
- ✔️ insertAfter
- ✔️ insertBefore
- ✔️ erase
- ✔️ clear
- ✔️ size
- ✔️ reverse

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
## Sorting/

### Sorting Algorithms (Arrays - Básico)

- [ ] bubble sort
- [ ] selection sort
- [ ] insertion sort

### Sorting Algorithms (Intermedio)

- [ ] merge sort (arrays)
- [ ] quick sort (arrays)
- [ ] heap sort

### Sorting Algorithms (Avanzado - optimizados)

- [ ] counting sort
- [ ] radix sort
- [ ] bucket sort

### Sorting con estructuras (SIN arrays directos)

- [ ] merge sort (linked list)
- [ ] insertion sort (linked list)
- [ ] quick sort (linked list optimized)

### Extras (muy avanzados / opcionales)

- [ ] external sorting (grandes datos)
- [ ] stable vs unstable analysis
- [ ] in-place vs out-of-place implementations
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

## 🔗 Doubly Linked List
- Implementación completada y probada
- Próximos pasos: Circular Singly Linked List


---

# 📄 Nota

Este repositorio es educativo y documenta mi progreso en estructuras de datos mediante implementación manual en C++, sin uso de la STL.
