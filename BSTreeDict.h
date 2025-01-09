#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <stdexcept>
#include <string>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict : public Dict<V> {
private:
    BSTree<TableEntry<V>>* tree; // ABB con elementos de tipo TableEntry<V>

public:
    // Constructor
    BSTreeDict() {
        tree = new BSTree<TableEntry<V>>();
    }

    // Destructor
    ~BSTreeDict() {
        delete tree;
    }

    // Método insert
    void insert(std::string key, V value) override {
        TableEntry<V> entry(key, value);
        tree->insert(entry);
    }

    // Método search
    V search(std::string key) override {
        TableEntry<V> entry(key);
        TableEntry<V> result = tree->search(entry);
        return result.value;
    }

    // Método remove
    V remove(std::string key) override {
        TableEntry<V> entry(key);
        TableEntry<V> result = tree->search(entry);
        tree->remove(entry);
        return result.value;
    }

    // Método entries
    int entries() override {
        return tree->size();
    }

    // Método capacity (no aplica para ABB, pero lo incluimos para mantener la interfaz)
    int capacity() {
        return -1; // No aplica
    }

    // Sobrecarga del operador []
    V operator[](std::string key) {
        return search(key);
    }

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs) {
        out << *(bs.tree);
        return out;
    }
};

#endif // BSTREEDICT_H

