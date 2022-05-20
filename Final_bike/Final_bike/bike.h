#pragma once
#include <iostream>
#include "Vector.h"
#define _USE_MATH_DEFINES
#include "math.h"

class Bike;
class Wheel;
struct spring //пружины(рессоры), связывающие колёса с корпусом
{
	double k;//коэффициент упругости
	double d;
	double l;//длина пружины
	Bike* bike;
	Vector2 p1;
	Wheel* p2;
	Vector2 dir2;
	Vector2 force1() const;//функции сил
	Vector2 force2() const;
	Vector2 dir() const;//направление

	Vector2 mid() const;//середина пружины

	double len() const;
	double angle() const;//угол наклона
};



struct Body
{
	Vector2 pos;//положение объекта
	Vector2 momentum;//момент импульса тела
	double angle;//угол наклона
	double L;//импульс тела
};
struct Wheel
{
	spring s;
	Body b;
	double mass;//масса колеса
	double radius;//радиус колеса
};


class Bike
{
public:
	Body b;//корпус
	Wheel rear;//заднее колесо
	Wheel front;//переднее колесо
	double mass;
	Bike operator+(Bike r);
	Bike operator*(double k);
	Bike();
	void update(int controls);

	Vector2 toGlobal(Vector2 v) const;
	Vector2 rotate(Vector2 v, double angle) const;
	Vector2 toLocal(Vector2 v) const;
	static void func(Bike* out, const Bike& in);

	static Bike rk(Bike* b);
	bool right;
	bool left;
	bool brake;
};


