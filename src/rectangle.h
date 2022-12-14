#pragma once

#include <iostream>

#include "./iterator/null_iterator.h"
#include "./shape.h"
#include "./visitor/shape_visitor.h"

class Rectangle : public Shape {
public:
    Rectangle(double length, double width): _length(length), _width(width){
        if(length <= 0) { throw "Not a positive double length"; } 
        else if(width <= 0) { throw "Not a positive double width"; }
    }

    double area() const override { return _length * _width; }

    double perimeter() const override { return (_length + _width) * 2; }
    
    std::string info() const override {
        std::stringstream stream1, stream2;
        stream1 << std::fixed << std::setprecision(2) << _length;
        stream2 << std::fixed << std::setprecision(2) << _width;
        std::string info = "Rectangle (" + stream1.str() + " " + stream2.str() + ")";
        return info;
    }

    void accept(ShapeVisitor* visitor) override {
        visitor->visitRectangle(this); 
    }

    Iterator* createIterator() override { return new NullIterator(); }

private:
    double _length, _width;
};