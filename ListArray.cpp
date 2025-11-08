#include "ListArray.h"
#include <stdexcept>
#include <iostream>


template <typename T>
ListArray<T>::ListArray() : max(MINSIZE), n(0) {
    arr = new T[max];
}

template <typename T>
ListArray<T>::~ListArray() {    
    delete[] arr;
}

template <typename T>
void ListArray<T>::resize(int newSize) {
    // Creamos una nueva lista con el nuevo tamaño
    T* newArr = new T[newSize];
    // Copiamos los elementos de la lista anitgua a la nueva
    for (int i = 0; i < n; ++i){
        newArr[i] = arr[i];
    }
    // Eliminamos la lista anituga
    delete[] arr;
    // Actualizamos el puntero a la nueva lista
    arr = newArr;
    // Actualizamos el tamaño mázimo al nuevo.
    max = newSize;
}

template <typename T>
void ListArray<T>::insert(int pos, const T& e) {
    if (pos < 0 || pos > n){
        throw std::out_of_range("Posición dada fuera de rango");
    }
    if (n >= max){
        resize(max * 2);
    }
    for (int i = n; i > pos; --i){
        arr[i] = arr[i - 1];
    }
    arr[pos] = e;
    ++n;
}

template <typename T>
void ListArray<T>::append(const T& e) {
    insert(n, e);
}

template <typename T>
void ListArray<T>::prepend(const T& e) {
    insert(0, e);
}

template <typename T>
T ListArray<T>::remove(int pos) {
    if (pos < 0 || pos >= n){
        throw std::out_of_range("Posición dada fuera de rango");
    }
    // Capturamos el elemento a eliminar
    T eliminado = arr[pos];
    // Desplazamos los elementos una posiión hacia la izquierda
    for (int i = pos; i < n - 1; ++i){
        arr[i] = arr[i + 1];
    }
    // Reducimos el total de elementos activos en la lista.
    --n;
    // Si el total de elementos libres son muy pocos (siempre respetando el mínimo), redimensionamos la lista.
    if (n <= max / 4 && max / 2 >= MINSIZE) resize(max / 2);
    // Devolvemos el elemento eliminado.
    return eliminado;
}

template <typename T>
T ListArray<T>::get(int pos) const {
    // Comprobamos que sea válida
    if (pos < 0 || pos >= n){
        throw std::out_of_range("Posición dada fuera de rango");
    }
    // Devolvemos ele elemento pedido.
    return arr[pos];
}

template <typename T>
int ListArray<T>::search(const T& e) const {
    for (int i = 0; i < n; ++i){
        if (arr[i] == e){
            return i;
        }
    }
    return -1; // No encontrado
}

template <typename T>
bool ListArray<T>::empty() const {
    return n == 0;
}

template <typename T>
int ListArray<T>::size() const {
    return n;
}

template <typename T>
T ListArray<T>::operator[](int pos) const {
    // Simplemente devuelve el elemento dentro de la posición dada.
    return get(pos);
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const ListArray<T>& list){
    for (int i = 0; i < list.n; i++){
        if (i < list.n - 1)
            out << list.arr[i] << ", ";
        else
            out << list.arr[i] << "\n";
    }
    return out;
}