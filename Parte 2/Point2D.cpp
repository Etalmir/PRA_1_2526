#include <Point2D.h>
#include <cmath>

double Point2D::distance(const Point2D &a, const Point2D &b){
    return sqrt(pow(a.x-b.x, 2) + pow(a.y - b.y, 2));
} 

bool operator==(const Point2D &a, const Point2D &b){
    return (b.x == a.x && b.y == a.y);
}

bool operator!=(const Point2D &a, const Point2D &b){
    return !(a == b);
}

std::ostream& operator<<(std::ostream& out , const Point2D& point){
    out << "(" << point.x << ", " << point.y << ")";
    return out;
}