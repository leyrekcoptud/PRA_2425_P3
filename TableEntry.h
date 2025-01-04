#ifndef TABLEENTRY_H
#define TABLEENTRY_H
#include <string>
#include <ostream>

// Clase genérica TableEntry<V>
template <typename V>
class TableEntry {
	public:
    		std::string key; // Clave del par
    		V value; // Valor del par

    		// Constructor con el par clave->valor
    		TableEntry(std::string key, V value) : key(key), value(value) {}

    		// Constructor solo con clave (sin valor)
    		TableEntry(std::string key) : key(key) {}

    		// Constructor con clave vacía y sin valor
    		TableEntry() : key(""), value(V()) {}

    		// Sobrecarga global del operador ==
    		friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2) {
        		return te1.key == te2.key;
    		}

    		// Sobrecarga global del operador !=
    		friend bool operator!=(const TableEntry<V> &te1, const TableEntry<V> &te2) {
        		return !(te1 == te2);
    		}

    		// Sobrecarga global del operador <<
    		friend std::ostream& operator<<(std::ostream &out, const TableEntry<V> &te) {
        		out << "Clave: " << te.key << ", Valor: " << te.value;
        		return out;
    		}
};
#endif
