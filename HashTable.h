#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdexcept>
#include <string>
#include <iostream>
#include "../../P1/PRA_2425_P1/ListLinked.h"
#include "TableEntry.h"
#include "Dict.h"

template <typename V>
class HashTable : public Dict<V> {
private:
    int n; // Número de elementos
    int max; // Tamaño de la tabla hash
    ListLinked<TableEntry<V>>* table; // Tabla de cubetas

    // Función hash
    int h(std::string key) {
        int sum = 0;
        for (char c : key) {
            sum += static_cast<int>(c);
        }
        return sum % max;
    }

public:
    // Constructor
    HashTable(int size) : n(0), max(size) {
        table = new ListLinked<TableEntry<V>>[max];
    }

    // Destructor
    ~HashTable() {
        delete[] table;
    }

    // Método insert
    void insert(std::string key, V value) override {
        int index = h(key);
        TableEntry<V> entry(key, value);
        for (int i = 0; i < table[index].size(); ++i) {
            if (table[index].get(i) == entry) {
                throw std::runtime_error("Key already exists in the hash table.");
            }
        }
        table[index].insert(0, entry); // Insertar al inicio
        ++n;
    }

    // Método search
    V search(std::string key) override {
        int index = h(key);
        TableEntry<V> entry(key);
        for (int i = 0; i < table[index].size(); ++i) {
            if (table[index].get(i) == entry) {
                return table[index].get(i).value;
            }
        }
        throw std::runtime_error("Key not found in the hash table.");
    }

    // Método remove
    V remove(std::string key) override {
        int index = h(key);
        TableEntry<V> entry(key);
        for (int i = 0; i < table[index].size(); ++i) {
            if (table[index].get(i) == entry) {
                V value = table[index].get(i).value;
                table[index].remove(i);
                --n;
                return value;
            }
        }
        throw std::runtime_error("Key not found in the hash table.");
    }

    // Método entries
    int entries() override {
        return n;
    }

    // Método capacity
    int capacity() {
        return max;
    }

    // Sobrecarga del operador []
    V operator[](std::string key) {
        return search(key);
    }

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &ht) {
        out << "HashTable [entries: " << ht.n << ", capacity: " << ht.max << "]\n";
        out << "==============\n\n";
        for (int i = 0; i < ht.max; ++i) {
            out << "== Cubeta " << i << " ==\n\n";
            out << "List => [\n";
            for (int j = 0; j < ht.table[i].size(); ++j) {
                out << "  " << ht.table[i].get(j);
                if (j < ht.table[i].size() - 1) out << "\n";
            }
            if (ht.table[i].size() == 0) out << "]";
            out << "\n]\n\n";
        }
        out << "==============\n";
        return out;
    }
};

#endif // HASHTABLE_H

