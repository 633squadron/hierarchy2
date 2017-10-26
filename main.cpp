#include <iostream>
enum class shapeType {triangle, square, rectangle, pentagon, hexagon, octagon};

class Shape {
public:
    virtual void setLen(float len)  = 0;
    virtual float getLen() const = 0;
    virtual double getArea() const = 0;
    virtual void calcArea() = 0;
    virtual double getVolume() const = 0;
    virtual void calcVolume() = 0;
    virtual ~Shape() = default;
};

class Square : public Shape {
    double area;
    double volume;
    float sideLength;
    shapeType type {shapeType::square};
public:
    explicit Square(float l) {
        area = 0;
        volume = 0;
        sideLength = 0;
        setLen(l);
        calcArea();
        calcVolume();
    }
    void setLen(float l) override {
        sideLength = l;
    }
    float getLen() const override {
        return sideLength;
    }
    void calcArea() override {
        area = sideLength * sideLength;
    }
    void calcVolume() override {
        volume = sideLength * sideLength * sideLength;
    }
    double getVolume() const override {
        return volume;
    }
    double getArea() const override {
        return area;
    }
    ~Square() = default;
};
int main() {
    std::cout << "Program start:" << std::endl;
    Square sq = Square(2.0);
    std::cout << "Square area is: " << sq.getArea() << std::endl;
    std::cout << "Square volume is: " <<sq.getVolume() << std::endl;
    return 0;
}