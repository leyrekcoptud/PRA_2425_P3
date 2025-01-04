#ifndef DICT_H
#define DICT_H

#include <string>
#include <stdexcept>

// Clase abstracta pura y genérica Dict<V>
template <typename V>
class Dict {
	public:
    		virtual ~Dict() = default;

    		// Métodos virtuales puros
    		virtual void insert(std::string key, V value) = 0;
    		virtual V search(std::string key) = 0;
    		virtual V remove(std::string key) = 0;
    		virtual int entries() = 0;
};
#endif

