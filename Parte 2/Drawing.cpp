#include "Drawing.h"
#include "Circle.h"

// Creamos una nueva ListLinked
Drawing::Drawing() {
    shapes = new ListLinked<Shape*>();
}

Drawing::~Drawing() {
    delete shapes;
}

// Usamos la función prepend() disponible en la clase ListLinked
void Drawing::add_front(Shape* shape) {
    shapes->prepend(shape);
}

void Drawing::add_back(Shape* shape) {
    shapes->append(shape);
}

// Imprimimos todas las figuras, usamos get() de ListLinked para obtener el objeto y usamos su método print();
void Drawing::print_all() const {
    for (int i = 0; i < shapes->size(); i++){
        shapes->get(i)->print();
    }
}

// Obtenemos el área total de las figuras
double Drawing::get_area_all_circles() const {
    double area = 0.0;
    for (int i = 0; i < shapes->size(); i++){
        Shape* s = shapes->get(i);
        if (dynamic_cast<Circle*>(s)) {
            area += s->area();
        }
    }
    return area;
}

// Hacemos translate a todas las figuras.
void Drawing::move_squares(double incX, double incY) {
    for(int i = 0; i < shapes->size(); i++) {
        shapes->get(i)->translate(incX, incY);
    }
}