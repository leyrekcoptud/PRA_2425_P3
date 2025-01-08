#ifdef HASHTABLE_H
#define HASHTABLE_H

#include "/mnt/c/Users/Usuario/Desktop/Programacion_segundo/Pro_avanzada/Practica_1/ListLinked.h"
#include "Dict.h"
#include "TableEntry.h"
#include <ostream>
#include <stdexcept>
#include <iostream>
#include <string>

typename<typename V>
class HashTable<V> : Dict<V> {
	private:
		int n;
		int max;
		ListLinked<TableEntry<V>> *table;
		int h(std::string key){
			int sum = 0;
			size_str = key.size();
			for( int i = 1; i <= size_str; ++i){
				char aux = key.at(i)
				sum = sum + std:string::int(aux);
			}
			pos = sum % max;
			return pos;
		};
	public:
		HashTable(int size){
			n = 0;
			max = size;
			table = new ListLinked<TableEntry<V>>[max];
		};
		~HashTable(){
			detele[] table;;
		};
		int capacity(){
			return max;
		};

		friend std::ostream&operator<<(std::ostream out, const HashTable<V> &th){
			out << "Contenido de las cubetas de la tabla: \n";
			for(int i = 0;i < th.max; i++){
				out << th.table[i] << "\n";
			}
			return out
		};
		V operator[](std::string key){
			int pos = h(key);
			confir = table[pos].search(TableEntry<V>(key)); // Search para vee si existe la clave // 
			if(confir == -1){
				throw std::runtime_error("LLave no encontrada")
			}
			return table[pos][confir].value;
		};
		void insert(std::string key, V value) override{
			int pos = h(key);
			confir = table[pos].search(TableEntry<V>(key));
			if(confir != -1){
				throw std::runtime_error("La llave ya existe");
			}
			TableEntry<V> Cubeta_nueva(key, value);
			table[pos].prepend(Cubeta_nueva);
			n++;
		};
		V search(std::string key) override{
			int pos = h(key);
			confir = table[pos].search(TableEntry<V>(key));
			if(confir == -1){
				throw std::runtime_error("llave no encontrada");
			}
			return confir;
		};
		V remove(std::string key) override{
			int pos = h(key);
			confir = table[pos].search(TableEntry<V>(key));
			if(confir == -1){
				throw std::runtime_error;
			}
			V data_eliminada = table[pos][confir].value;
			table[pos].remove();
			n--;
			return data_eliminada;
		};
		int entries() override{
			return n;
		};
};

#endif

