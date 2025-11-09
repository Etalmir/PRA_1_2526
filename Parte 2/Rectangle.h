#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"
#include "Point2D.h"
#include <ostream>

class Rectangle : public Shape {
    private:
    static bool check(const Point2D* vertices);
    
    protected:  
        Point2D* vs;

    public: 
        static const int N_VERTICES = 4;

        // Constructores
        Rectangle();
        Rectangle(std::string color, Point2D* vertices);
        Rectangle(const Rectangle& r); // Constructor de copia
        ~Rectangle(); // Destructor

        // Getters
        Point2D get_vertex(int ind) const;
        double area() const override;
        double perimeter() const override;
        void print() const override;

        // Setters
        void translate(double incX, double incY) override;
        virtual void set_vertices(const Point2D* vertices);

        // Operadores
        Rectangle& operator=(const Rectangle& r); // Operador de asignación de copia
        friend std::ostream& operator<<(std::ostream& out, const Rectangle& r); // Sobrecarga del operador de salida
        Point2D operator[](int ind) const; // Operador de acceso al vertice
    
};

#endif