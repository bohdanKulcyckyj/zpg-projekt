#pragma once

#include <iostream>
#include <cmath>

class Point {
public:
    double x;
    double y;

    Point(double _x, double _y){
        x = _x;
        y = _y;
    }

    static Point* add(Point* p1, Point* p2, Point* result) {
        result->x = p1->x + p2->x;
        result->y = p1->y + p2->y;
        return result;
    }

    static Point* add(Point* p1, Point* p2) {
        return new Point(p1->x + p2->x, p1->y + p2->y);
    }

    static Point* subtract(Point* p1, Point* p2, Point* result) {
        result->x = p1->x - p2->x;
        result->y = p1->y - p2->y;
        return result;
    }

    static Point* subtract(const Point* p1, const Point* p2) {
        return new Point(p1->x - p2->x, p1->y - p2->y);
    }

    static Point* multiplyBy(Point* p, float c) {
        p->x *= (double)c;
        p->y *= (double)c;
        return p;
    }

    static Point* divideBy(Point* p, float c) {
        p->x /= (double)c;
        p->y /= (double)c;
        return p;
    }
};