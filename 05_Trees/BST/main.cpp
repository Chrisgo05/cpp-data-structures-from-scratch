#include "BinarySearchTree.h"

int main() {
    BinarySearchTree<int> arbol;

    arbol.insert(100);

    arbol.insert(50);
    arbol.insert(150);

    arbol.insert(25);
    arbol.insert(75);
    arbol.insert(125);
    arbol.insert(175);

    arbol.insert(12);
    arbol.insert(37);
    arbol.insert(62);
    arbol.insert(87);
    arbol.insert(112);
    arbol.insert(137);
    arbol.insert(162);
    arbol.insert(187);

    arbol.insert(6);
    arbol.insert(18);
    arbol.insert(31);
    arbol.insert(43);
    arbol.insert(56);
    arbol.insert(68);
    arbol.insert(81);
    arbol.insert(93);
    arbol.insert(106);
    arbol.insert(118);
    arbol.insert(131);
    arbol.insert(143);
    arbol.insert(156);
    arbol.insert(168);
    arbol.insert(181);
    arbol.insert(193);

    arbol.insert(3);
    arbol.insert(9);
    arbol.insert(15);
    arbol.insert(21);
    arbol.insert(28);
    arbol.insert(34);
    arbol.insert(40);
    arbol.insert(46);
    arbol.insert(53);
    arbol.insert(59);
    arbol.insert(65);
    arbol.insert(71);
    arbol.insert(78);
    arbol.insert(84);
    arbol.insert(90);
    arbol.insert(96);
    arbol.insert(103);
    arbol.insert(109);
    arbol.insert(115);
    arbol.insert(121);
    arbol.insert(128);
    arbol.insert(134);
    arbol.insert(140);
    arbol.insert(146);
    arbol.insert(153);
    arbol.insert(159);
    arbol.insert(165);
    arbol.insert(171);
    arbol.insert(178);
    arbol.insert(184);
    arbol.insert(190);
    arbol.insert(196);

    std::cout << "Inorder: ";
    arbol.inorder();
    std::cout << "\n\n";

    std::cout << "Preorder: ";
    arbol.preorder();
    std::cout << "\n\n";

    std::cout << "Postorder: ";
    arbol.postorder();
    std::cout << "\n\n";

    std::cout << "Altura: " << arbol.altura() << "\n";
    std::cout << "Size: " << arbol.size() << "\n\n";

    std::cout << "Tree:\n";
    arbol.printTree();
}