#ifndef LIST_LINKED_H
#define LIST_LINKED_H
#include "Generic_list.h"
#include "Node.h"
#include <ostream>

template <typename T>
class ListLinked : public GenericList<T> {
    private:
        Node<T>* first;
        int n;
    public:
        // Constructor y Destructor
        ListLinked() : first(nullptr), n(0) {}
        ~ListLinked() {
            while (first != nullptr){
                Node<T>* aux = first;
                first = first->next;
                delete aux;
            }
        }

        void insert(int pos, const T& e) override {
            // Si está fuera del rango, lanzamos excepción.
            if (pos < 0 || pos > n){
                throw std::out_of_range("Posición dada fuera de rango");
            }
            if (pos == 0){
                 // Creamos un nuevo nodo que tenga como siguiente al primero
                Node<T>* nuevo = new Node<T>(e, first);
                // Actualizamos el puntero del primero al nodo nuevo.
                first = nuevo;
                ++n;
            }
            else if(pos == n){
                Node<T>* aux = first;
                Node<T>* nuevo = new Node<T>(e);
                while (aux->next != nullptr){
                    aux = aux->next;
                }
                aux->next = nuevo;
                ++n;
            }
            else{
                int i = 0;
                Node<T>* aux = first;
                Node<T>* nuevo = new Node<T>(e);
                while(i != pos - 1){
                    aux = aux->next;
                    i++;
                }
                nuevo->next = aux->next;
                aux->next = nuevo;
                ++n;
            }
        }

        void append(const T& e) override{
            insert(n, e);
        }

        void prepend(const T& e) override{
            insert(0, e);
        }

        T remove(int pos) override{
            // Si está fuera del rango, lanzamos excepción.
            if (pos < 0 || pos >= n){
                throw std::out_of_range("Posición dada fuera de rango");
            }
            // Creamos un puntero a nodo que servirá para obtener el nodo a eliminar.
            Node<T>* toDelete;
            T eliminado;
            // Si es el primero, igualamos al primero, capturamos el data y movemos first a la siguiente posición.
            if (pos == 0){
                toDelete = first;
                eliminado = toDelete->data;
                first = first->next;
            }
            // Si no es el primero, buscamos el anterior al que queremos eliminar, capturamos el data del que queremos eliminar e igualamos toDelete a la posición deseada
            // Pasamos el next del anterior al next del elemento a eliminar.
            else {
                Node<T>* aux = first;
                for (int i = 0; i < pos - 1; ++i){
                    aux = aux->next;
                }
                toDelete = aux->next;
                eliminado = toDelete->data;
                aux->next = toDelete->next;
            }
            // Eliminamos el nodo a elmininar
            delete toDelete;
            n--;
            // Devolvemos el elemento capturado.
            return eliminado;
        }

        T get(int pos) const override{
            // Si está fuera del rango, lanzamos excepción.
            if (pos < 0 || pos >= n){
                throw std::out_of_range("Posición dada fuera de rango");
            }
            // Creamos un puntero para viajar a lo largo de la lista
            Node<T>* aux = first;
            for (int i = 0; i < pos; i++){
                aux = aux->next;
            }
            // Devolvemos el data de la posición deseada
            return aux->data;
        }

        int search(const T& e) const override{
            // Creamos un puntero para la búsqueda y un contador
            Node<T>* toSearch = first;
            int i = 0;
            // Buscamos el elemento deseado
            while(toSearch != nullptr){
                if(toSearch->data == e){
                    break;
                }
                toSearch = toSearch->next;
                i++;
            }
            // Si se ha encontrado devolvmos posición
            if (toSearch != nullptr){
                return i;
            }
            // SI no, devolvemos -1;
            return -1;
        }

        bool empty() const override {
            return n == 0;
        }
        int size() const override {
            return n;
        }

        T operator[](int pos){
            return get(pos);
        }
        
        friend std::ostream& operator<<(std::ostream &out , const ListLinked<T>& list){
            Node<T>* aux = list.first;
            while(aux != nullptr){
                out << aux->data;
                if(aux->next != nullptr){
                    out << ", ";
                }
                aux = aux->next;
            }
            out << "\n";
            return out;
        }
};

#endif