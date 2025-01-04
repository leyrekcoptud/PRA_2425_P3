#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"
#include "../../P1/PRA_2425_P1/ListLinked.h"  // ¡¡¡¡MODIFICAR!!!! asegúrate de que la ruta es correcta

template <typename V>
class HashTable : public Dict<V> {
	private:
    		int n; // Número de elementos almacenados actualmente en la tabla hash
    		int max; // Tamaño de la tabla hash (número total de cubetas)
    		ListLinked<TableEntry<V>>* table; // Tabla de cubetas, representada por un array de punteros a listas enlazadas

    		// Función hash que devuelve la posición (cubeta) en la tabla hash de key
    		int h(std::string key) {
        		int sum = 0;
        		for (char c : key) {
            			sum += static_cast<int>(c);
        		}
        		return sum % max;
    		}

	public:
    		// Método constructor
    		HashTable(int size) : n(0), max(size) {
        		table = new ListLinked<TableEntry<V>>[max];
    		}

    		// Método destructor
    		~HashTable() {
        		delete[] table;
    		}

    		// Devuelve el número total de cubetas de la tabla
    		int capacity() {
        		return max;
    		}

    		// Sobrecarga del operador []
    		V operator[](std::string key) {
        		int index = h(key);
        		// Utilizar iteradores específicos de ListLinked
        		for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            			if (it->key == key) {
                			return it->value;
            			}
        		}
        		throw std::runtime_error("Key not found");
    		}

    		// Implementación de los métodos de Dict<V>
    		void insert(std::string key, V value) override {
        		int index = h(key);
        		// Utilizar iteradores específicos de ListLinked
        		for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            			if (it->key == key) {
                			throw std::runtime_error("Key already exists");
            			}
        		}
        		table[index].insert(TableEntry<V>(key, value));
        		n++;
    		}

    		V search(std::string key) override {
        		int index = h(key);
        		// Utilizar iteradores específicos de ListLinked
        		for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            			if (it->key == key) {
                			return it->value;
            			}
        		}
        		throw std::runtime_error("Key not found");
    		}

    		V remove(std::string key) override {
        		int index = h(key);
        		// Utilizar iteradores específicos de ListLinked
        		for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            			if (it->key == key) {
                			V value = it->value;
                			table[index].erase(it);
                			n--;
                			return value;
            			}
        		}
        		throw std::runtime_error("Key not found");
    		}

    		int entries() override {
        		return n;
    		}

    		// Sobrecarga del operador << con declaración de plantilla
		friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &ht) {
    			for (int i = 0; i < ht.max; ++i) {
        			out << "Cubeta " << i << ": ";
        			for (auto it = ht.table[i].begin(); it != ht.table[i].end(); ++it) {
            				out << *it << " ";
        			}
        			out << "\n";
    			}
    			return out;
		}
};
#endif // HASHTABLE_H

