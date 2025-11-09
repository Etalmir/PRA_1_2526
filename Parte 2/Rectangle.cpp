#include "Rectangle.h"
#include <iostream>
#include <stdexcept>

bool Rectangle::check(const Point2D* vertices) {
    // Generamos las distancias entre todos los puntos
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);
    double d02 = Point2D::distance(vertices[0], vertices[2]);
    double d13 = Point2D::distance(vertices[1], vertices[3]);

    // Devolvemos que todas las distancias sean mayores que 0, que los lados opuestos sean iguales.
    return (d01 > 0 && d12 > 0 && d23 > 0 && d30 > 0 &&
            d01 == d23 && d12 == d30);
}

Rectangle::Rectangle() : Shape() {
    vs = new Point2D[N_VERTICES];
    vs[0] = Point2D(-1, 0.5); 
    vs[1] = Point2D(1, 0.5); 
    vs[2] = Point2D(1, -0.5); 
    vs[3] = Point2D(-1, -0.5);
}

Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color) {
    if (!check(vertices)){
        throw std::invalid_argument("Los vértices no forman un rectángulo válido.");
    }
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; i++){
        vs[i] = vertices[i];
    }
}

Rectangle::Rectangle(const Rectangle& r) : Shape(r.color) {
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; i++){
        vs[i] = r.vs[i];
    }
}

Rectangle::~Rectangle() {
    delete[] vs;
}

Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind >= N_VERTICES){
        throw std::out_of_range("Índice de vértice fuera de rango.");
    }
    return vs[ind];
}

double Rectangle::area() const {
    double ancho = Point2D::distance(vs[0], vs[1]);
    double alto = Point2D::distance(vs[1], vs[2]);
    return ancho * alto;
}

double Rectangle::perimeter() const {
    double ancho = Point2D::distance(vs[0], vs[1]);
    double alto = Point2D::distance(vs[1], vs[2]);
    return 2 * (ancho + alto);
}

void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; i++){
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

void Rectangle::set_vertices(const Point2D* vertices) {
    if (!check(vertices)){
        throw std::invalid_argument("Los vértices no forman un rectángulo válido.");
    }
    for (int i = 0; i < N_VERTICES; i++){
        vs[i] = vertices[i];
    }
}

Rectangle& Rectangle::operator=(const Rectangle& r) {
    if (this != &r) { // Si no es el mismo objeto
        Shape::setColor(r.color);
        for (int i = 0; i < N_VERTICES; i++){
            vs[i] = r.vs[i];
        }
    }
    return *this; // Devolvemos el objeto actual
}

Point2D Rectangle::operator[](int ind) const {
    if (ind < 0 || ind >= N_VERTICES){
        throw std::out_of_range("Índice de vértice fuera de rango.");
    }
    return vs[ind];
}

std::ostream& operator<<(std::ostream& out, const Rectangle& r) {
    out << "Color del rectángulo: " << r.getColor() << ", vértices: ";
    for (int i = 0; i < Rectangle::N_VERTICES; i++) {
        out << r.vs[i];
        if (i < Rectangle::N_VERTICES - 1) {
            out << ", ";
        }
    }
    out << ")" << std::endl;
    return out;
}

void Rectangle::print() const {
    std::cout << *this; // Usamos la sobrecarga anterior del operador de salida
}