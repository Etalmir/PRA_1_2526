# PRA_2425

Repositorio de la práctica para la asignatura de Ingeniería de Robótica (curso 2024-2025).

## Descripción del proyecto

El proyecto implementa un sistema orientado a objetos para modelar dibujos compuestos por figuras 2D.  
La clase abstracta `Shape` define la interfaz común para todas las figuras, incluyendo métodos para calcular el área, perímetro, realizar traslaciones y mostrar información.  
Las clases derivadas, como `Rectangle` o `Square`, implementan estas operaciones y añaden comportamientos específicos.  
La clase `Drawing` gestiona una lista de figuras mediante la interfaz genérica `List<T>`, que puede estar implementada por `ListArray<T>` o `ListLinked<T>`.

# Ejemplo de Salida
Figura 1: Rectangle (color = red)
Vértices: (0,0), (4,0), (4,3), (0,3)
Área = 12
Perímetro = 14
Traslación: incX = 2, incY = 1
Nueva posición: (2,1), (6,1), (6,4), (2,4)
