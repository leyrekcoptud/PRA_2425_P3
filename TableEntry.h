#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <iostream>
#include <string>

// Clase genérica TableEntry<V> para pares clave-valor
template <typename V>
class TableEntry {
public:
    std::string key; // Clave del par
    V value;         // Valor del par

    // Constructor con clave y valor
    TableEntry(std::string key, V value) : key(key), value(value) {}

    // Constructor solo con clave
    TableEntry(std::string key) : key(key), value(V()) {}

    // Constructor por defecto
    TableEntry() : key(""), value(V()) {}

    // Sobrecarga del operador ==
    friend bool operator==(const TableEntry<V>& te1, const TableEntry<V>& te2) {
        return te1.key == te2.key;
    }

    // Sobrecarga del operador !=
    friend bool operator!=(const TableEntry<V>& te1, const TableEntry<V>& te2) {
        return !(te1 == te2);
    }

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream& out, const TableEntry<V>& te) {
        out << "(" << te.key << " => " << te.value << ")";
        return out;
    }
};

#endif // TABLEENTRY_H

