#ifndef LIST_ARRAY_H
#define LIST_ARRAY_H
#include "Generic_list.h"
#include <ostream>

template <typename T>
class ListArray : public GenericList<T> {
    private:
        T* arr;
        int max;
        int n;
        static const int MINSIZE = 2;
    public:
        // Constructor y Destructor
        ListArray();
        ~ListArray();
        
        // Método para añadir elementos a la lista
        void insert(int pos, const T& e) override;

        // Método para añadir elementos al final de la lista
        void append(const T& e) override;

        // Método para añadir elementos al principio de la lista
        void prepend(const T& e) override;

        // Método para eliminar elementos de la lista
        T remove(int pos) override;

        // Método para obtener un elemento de la lista
        T get(int pos) const override;

        // Método para buscar un elemento en la lista
        int search(const T& e) const override;

        // Método para comprobar si la lista está vacía
        bool empty() const override;

        // Método para obtener el tamaño de la lista
        int size() const override;

        // Sobrecarga del operador de acceso, devuelve el elemento en la posición dada
        T operator[](int pos) const;

        // Sobrecarga del operador de salida para imprimir la lista, devuelve la lista en un flujo de salida, imprime los elementos separados por espacios y comas
        friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list);

        // Metodo para redimensionar el array
        void resize(int newSize);
};

#endif