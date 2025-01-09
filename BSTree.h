#ifndef BSTREE_H
#define BSTREE_H

#include <stdexcept>
#include <iostream>
#include "BSNode.h"

// Clase genérica BSTree<T>
template <typename T>
class BSTree {
private:
    int nelem;            // Número de elementos almacenados en el ABB
    BSNode<T>* root;      // Nodo raíz del ABB

    // Método recursivo para la búsqueda de elementos
    BSNode<T>* search(BSNode<T>* n, T e) const {
        if (n == nullptr) {
            throw std::runtime_error("Element not found!");
        }
        if (e < n->elem) {
            return search(n->left, e);
        } else if (e > n->elem) {
            return search(n->right, e);
        } else {
            return n;
        }
    }

    // Método recursivo para la inserción de elementos
    BSNode<T>* insert(BSNode<T>* n, T e) {
        if (n == nullptr) {
            return new BSNode<T>(e);
        }
        if (e < n->elem) {
            n->left = insert(n->left, e);
        } else if (e > n->elem) {
            n->right = insert(n->right, e);
        } else {
            throw std::runtime_error("Element already exists!");
        }
        return n;
    }

    // Método recursivo para la eliminación de elementos
    BSNode<T>* remove(BSNode<T>* n, T e) {
        if (n == nullptr) {
            throw std::runtime_error("Element not found!");
        }
        if (e < n->elem) {
            n->left = remove(n->left, e);
        } else if (e > n->elem) {
            n->right = remove(n->right, e);
        } else {
            // Element found
            if (n->left == nullptr) {
                BSNode<T>* temp = n->right;
                delete n;
                return temp;
            } else if (n->right == nullptr) {
                BSNode<T>* temp = n->left;
                delete n;
                return temp;
            } else {
                // Node with two children
                n->elem = max(n->left);
                n->left = remove_max(n->left);
            }
        }
        return n;
    }

    // Método recursivo para encontrar el elemento de mayor valor
    T max(BSNode<T>* n) const {
        while (n->right != nullptr) {
            n = n->right;
        }
        return n->elem;
    }

    // Método recursivo para eliminar el elemento de mayor valor
    BSNode<T>* remove_max(BSNode<T>* n) {
        if (n->right == nullptr) {
            BSNode<T>* temp = n->left;
            delete n;
            return temp;
        }
        n->right = remove_max(n->right);
        return n;
    }

    // Método recursivo para el recorrido inorden
    void print_inorder(std::ostream &out, BSNode<T>* n) const {
        if (n != nullptr) {
            print_inorder(out, n->left);
            out << n->elem << " ";
            print_inorder(out, n->right);
        }
    }

    // Método recursivo para la liberación de memoria
    void delete_cascade(BSNode<T>* n) {
        if (n != nullptr) {
            delete_cascade(n->left);
            delete_cascade(n->right);
            delete n;
        }
    }

public:
    // Constructor
    BSTree() : nelem(0), root(nullptr) {}

    // Destructor
    ~BSTree() {
        delete_cascade(root);
    }

    // Devuelve el número de elementos en el ABB
    int size() const {
        return nelem;
    }

    // Busca un elemento en el ABB
    T search(T e) const {
        BSNode<T>* result = search(root, e);
        return result->elem;
    }

    // Sobrecarga del operador[]
    T operator[](T e) const {
        return search(e);
    }

    // Inserta un elemento en el ABB
    void insert(T e) {
        root = insert(root, e);
        ++nelem;
    }

    // Elimina un elemento del ABB
    void remove(T e) {
        root = remove(root, e);
        --nelem;
    }

    // Sobrecarga del operador<< para imprimir el ABB
    friend std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst) {
        bst.print_inorder(out, bst.root);
        return out;
    }
};

#endif // BSTREE_H

