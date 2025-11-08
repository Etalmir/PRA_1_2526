#ifndef POINT2D_H
#define POINT2D_H
#include <ostream>

class Point2D{
    public:
        double x;
        double y;

        //Constructor de la clase
        Point2D(double x=0, double y=0) : x(x), y(y) {}

        // Cálculo de la distancia euclidiana entre a y b
        static double distance(const Point2D &a, const Point2D &b);

        friend bool operator!=(const Point2D &a, const Point2D &b);

        // Operador global ==
        friend bool operator==(const Point2D &a, const Point2D &b);

        friend std::ostream& operator<<(std::ostream& out , const Point2D& point);

};



#endif