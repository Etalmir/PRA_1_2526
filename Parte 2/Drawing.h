#ifndef DRAWING_H
#define DRAWING_H
#include "Shape.h"
#include "../Generic_list.h"
#include "../ListArray.h"
#include "../ListLinked.h"

class Drawing {
    private:
        GenericList<Shape*>* shapes;
    
    public:
        Drawing(); // Constructor
        ~Drawing(); // Destructor

        void add_front(Shape* shape); // Añade una figura al principio
        void add_back(Shape* shape); // Añade una figura al final
        void print_all() const; // Imprime todas las figuras
        double get_area_all_circles() const; // Devuelve el área total de todas las figuras
        void move_squares(double incX, double incY); // Mueve todos los cuadrados
};

#endif