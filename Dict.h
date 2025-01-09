#ifndef DICT_H
#define DICT_H

#include <stdexcept>
#include <string>

// Clase abstracta pura y genérica Dict<V>
template <typename V>
class Dict {
public:
    // Destructor virtual
    virtual ~Dict() {}

    // Método para insertar un par clave-valor en el diccionario
    virtual void insert(std::string key, V value) = 0;

    // Método para buscar un valor correspondiente a una clave en el diccionario
    virtual V search(std::string key) = 0;

    // Método para eliminar un par clave-valor del diccionario
    virtual V remove(std::string key) = 0;

    // Método para obtener el número de elementos en el diccionario
    virtual int entries() = 0;
};

#endif // DICT_H

