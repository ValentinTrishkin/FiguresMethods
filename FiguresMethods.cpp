// FiguresMethods.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include "Figures.h"


int main()
{
    setlocale(LC_ALL, "Rus");
    Figure* a = nullptr;
    Triangle triangle(10, 25, 40, 30, 10, 60);
    IsosTriangle isos_triangle(10, 10, 20, 30, 40, 30);
    RectTriangle rect_triangle(10, 30, 20, 30, 30);
    EquilTriangle equil_triangle(10);
    Quadrilateral quadrilateral(10, 20, 10, 20, 90, 90, 90, 90);
    Rectangle rectangle(30, 15, 30, 20);
    Square square(25);
    Parallelogram parallelogram(20, 30, 20, 30, 30, 50, 30, 30);
    Rhomb rhomb(20, 30, 50, 30, 50);
    a = &triangle;
    a->print_info();
    a = &isos_triangle;
    a->print_info();
    a = &rect_triangle;
    a->print_info();
    a = &equil_triangle;
    a->print_info();        
    a = &quadrilateral;
    a->print_info();        
    a = &rectangle;
    a->print_info();
    a = &square;
    a->print_info();
    a = &parallelogram;
    a->print_info();
    a = &rhomb;
    a->print_info();
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
