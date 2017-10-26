#include <iostream>
enum class shapeType {triangle, square, rectangle, pentagon, hexagon, octagon};

class Shape {
protected:
    double area;
    double volume;
    double sideLength;
    shapeType type;
public:
    Shape() {
        area = 0;
        volume = 0;
        sideLength = 0;
        type = shapeType::square;
    }
    virtual void setLen(double len)  = 0;
    virtual double getLen() const = 0;
    virtual double getArea() const = 0;
    virtual double calcArea() = 0;
    virtual double getVolume() const = 0;
    virtual double calcVolume() = 0;
    virtual ~Shape() = default;
};

class Square : public Shape {
    shapeType type {shapeType::square};
public:
    explicit Square(double l) {
        area = 0;
        volume = 0;
        sideLength = 0;
        setLen(l);
        calcArea();
        calcVolume();
    }
    void setLen(double l) override {
        sideLength = l;
    }
    double getLen() const override {
        return sideLength;
    }
    double calcArea() override {
        area = sideLength * sideLength;
        return area;
    }
    double calcVolume() override {
        volume = sideLength * sideLength * sideLength;
        return volume;
    }
    double getVolume() const override {
        return volume;
    }
    double getArea() const override {
        return area;
    }
    ~Square() override = default;
};
int main() {
    std::cout << "Program start:" << std::endl;
    Square sq = Square(2.0);
    std::cout << "Square area is: " << sq.getArea() << std::endl;
    std::cout << "Square volume is: " <<sq.getVolume() << std::endl;
    return 0;
}