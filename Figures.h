#pragma once

class Figure
{
public:
    virtual bool check()
    {
        if (num_side == 0)
        {
            return true;
        }
        return false;
    };
    virtual void print_info()
    {
        std::cout << get_name() << std::endl;
        if (check() == true)
        {
            std::cout << "Правильная" << std::endl;
        }
        else(std::cout << "Неправильная" << std::endl);
        std::cout << "Количество сторон: " << get_num_side() << std::endl;
    }
    virtual std::string get_name() { return name; };
    virtual int get_num_side() { return num_side; };
private:
    int num_side = 0;
    std::string name = "Фигура";
};

class Quadrilateral: public Figure // Четырехугольник
{
public:
    Quadrilateral(int side_a = 0, int side_b = 0, int side_c = 0, int side_d = 0, int corner_a = 0, int corner_b = 0, int corner_c = 0, int corner_d = 0)
    {
        side_a_ = side_a;
        side_b_ = side_b;
        side_c_ = side_c;
        side_d_ = side_d;
        corner_a_ = corner_a;
        corner_b_ = corner_b;
        corner_c_ = corner_c;
        corner_d_ = corner_d;
    };
    int get_side_a() { return side_a_; }
    int get_side_b() { return side_b_; }
    int get_side_c() { return side_c_; }
    int get_side_d() { return side_d_; }
    int get_corner_a() { return corner_a_; }
    int get_corner_b() { return corner_b_; }
    int get_corner_c() { return corner_c_; }
    int get_corner_d() { return corner_d_; }
    int get_num_side() { return num_side; }
    std::string get_name() override { return name; }
    bool check() override
    {
        if ((corner_a_ + corner_b_ + corner_c_ + corner_d_) == 360)
        {
            return true;
        }
        return false;
    }
    void print_info() override
    {
        Figure::print_info();        
        std::cout << "Стороны: " << side_a_ << ", " << side_b_ << ", " << side_c_ << ", " << side_d_ << std::endl;
        std::cout << "Углы: " << corner_a_ << ", " << corner_b_ << ", " << corner_c_ << ", " << corner_d_ << std::endl << std::endl;
    }
protected:
    int side_a_ = 0, side_b_ = 0, side_c_ = 0, side_d_ = 0;
    int corner_a_ = 0, corner_b_ = 0, corner_c_ = 0, corner_d_ = 0;
    int num_side = 4;
private:
    std::string name = "Четырехугольник:";    
};

class Rectangle : public Quadrilateral // Прямоугольник
{
public:
    Rectangle(int side_a = 0, int side_b = 0, int side_c = 0, int side_d = 0) :Quadrilateral(side_a, side_b, side_c, side_d, corner_a, corner_b, corner_c, corner_d)
    {
        corner_a_ = corner_a;
        corner_b_ = corner_b;
        corner_c_ = corner_c;
        corner_d_ = corner_d;
    }
    bool check() override
    {
        if (((corner_a_, corner_b_, corner_c_, corner_d_) == 90) && ((side_a_ == side_c_) && (side_b_ == side_d_)) && Quadrilateral::check())
        {
            return true;
        }
        return false;
    }
    std::string get_name() override { return name; }
private:
    std::string name = "Прямоугольник:";
    int corner_a = 90, corner_b = 90, corner_c = 90, corner_d = 90;
};

class Square : public Rectangle // Квадрат
{
public:
    Square(int side_a = 0) :Rectangle(side_a)
    {
        side_a_ = side_b_ = side_c_ = side_d_ = side_a;
    }
    std::string get_name() override { return name; }
    bool check() override
    {
        if ((Rectangle::check()) && (side_a_ == side_b_) && (side_b_ == side_c_) && (side_c_ == side_d_))
        {
           return true;
        }
        return false;
    }    
private:
    std::string name = "Квадрат:";
};

class Parallelogram : public Quadrilateral
{
public:
    Parallelogram(int side_a = 0, int side_b = 0, int side_c = 0, int side_d = 0, int corner_a = 0, int corner_b = 0, int corner_c = 0, int corner_d = 0) :Quadrilateral(side_a, side_b, side_c, side_d, corner_a, corner_b, corner_c, corner_d)
    {}
    bool check() override
    {
        if ((Quadrilateral::check()) && ((side_a_ == side_c_) && (side_b_ == side_d_)) && ((corner_a_ == corner_c_) && (corner_b_ == corner_d_)))
        {
            return true;
        }
        return false;
    }    
    std::string get_name() override { return name; }
private:
    std::string name = "Параллелограмм:";
};

class Rhomb : public Quadrilateral // Ромб
{
public:
    Rhomb(int side_a = 0, int corner_a = 0, int corner_b = 0, int corner_c = 0, int corner_d = 0) :Quadrilateral(side_a, side_b, side_c, side_d, corner_a, corner_b, corner_c, corner_d)
    {
        side_b_ = side_c_ = side_d_ = side_a;
    }
    bool check() override
    {
        if(Quadrilateral::check())
        {
            if ((corner_a_ == corner_c_) && (corner_b_ == corner_d_))
            {
                if ((side_a_ == side_b_) && (side_b_ == side_c_) && (side_c_ == side_d_))
                {
                    return true;
                }
            }
        }
        return false;
    }
    std::string get_name() override { return name; }
private:
    std::string name = "Ромб:";
    int side_b = 0, side_c = 0, side_d = 0;
};
class Triangle : public Figure
{
public:
    Triangle(int side_a = 0, int side_b = 0, int side_c = 0, int corner_a = 0, int corner_b = 0, int corner_c = 0)
    {
        side_a_ = side_a;
        side_b_ = side_b;
        side_c_ = side_c;
        corner_a_ = corner_a;
        corner_b_ = corner_b;
        corner_c_ = corner_c;
    };
    int get_side_a() { return side_a_; }
    int get_side_b() { return side_b_; }
    int get_side_c() { return side_c_; }
    int get_corner_a() { return corner_a_; }
    int get_corner_b() { return corner_b_; }
    int get_corner_c() { return corner_c_; }
    std::string get_name() override { return name; }
    int get_num_side() { return num_side; }
    bool check() override
    {
        if ((corner_a_ + corner_b_ + corner_c_) == 180)
        {
            return true;
        }
        return false;
    }
    void print_info() override
    {
        Figure::print_info();
        std::cout << "Стороны: " << side_a_ << ", " << side_b_ << ", " << side_c_ << ", " << std::endl;
        std::cout << "Углы: " << corner_a_ << ", " << corner_b_ << ", " << corner_c_ << ", " << std::endl << std::endl;
    }
protected:
    int side_a_ = 0, side_b_ = 0, side_c_ = 0;    
    int corner_a_ = 0, corner_b_ = 0, corner_c_ = 0;   
    int num_side = 3;
private:
    std::string name = "Треугольник:";    
};

class IsosTriangle : public Triangle // Равнобедренный треугольник
{
public:
    IsosTriangle(int side_a = 0, int side_b = 0, int side_c = 0, int corner_a = 0, int corner_b = 0, int corner_c = 0) :Triangle(side_a, side_b, side_c, corner_a, corner_b, corner_c)
    {}    
    std::string get_name() override { return name; }
    bool check() override
    {
        if ((side_a_ == side_b_) && (corner_a_ == corner_c_) && (Triangle::check()))
        {
            return true;
        }
        return false;
    }
    /*void print_info() override
    {
        Triangle::print_info();
    }*/
private:
    std::string name = "Равнобедренный треугольник:";
};

class RectTriangle : public Triangle // Прямоугольный треугольник
{
public:
    RectTriangle(int side_a = 0, int side_b = 0, int side_c = 0, int corner_a = 0, int corner_b = 0) :Triangle(side_a, side_b, side_c, corner_a, corner_b, corner_c)
    {
        corner_c_ = corner_c;
    }
    std::string get_name() override { return name; }
    bool check() override
    {
        if (corner_c_ == 90 && Triangle::check())
        {
            return true;
        }
        return false;
    }
private:
    int corner_c = 90;
    std::string name = "Прямоугольный треугольник:";
};

class EquilTriangle : public Triangle
{
public:
    EquilTriangle(int side_a = 0) :Triangle(side_a, corner_a, corner_b, corner_c)
    {
        side_b_ = side_c_ = side_a;
        corner_a_ = corner_a;
        corner_b_ = corner_b;
        corner_c_ = corner_c;
    }
    void set_side()
    {
        if (side_a_ == side_c_ == side_b_)
        {
            std::cout << "Правильная фигура";
        }
        std::cout << "Неправильная фигура";
    }
    std::string get_name() override { return name; }
private:
    int corner_c = 60, corner_b = 60, corner_a = 60;
    std::string name = "Равносторонний треугольник:";
};
