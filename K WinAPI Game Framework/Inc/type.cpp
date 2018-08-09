#include "stdafx.h"

using namespace std;
using namespace TYPE;

Point Point::operator+(float _value) const
{
	return Point{ x + _value, y + _value };
}

Point Point::operator+(Point const& _value) const
{
	return Point{ x + _value.x, y + _value.y };
}

void Point::operator+=(float _value)
{
	x += _value;
	y += _value;
}

void Point::operator+=(Point const& _value)
{
	x += _value.x;
	y += _value.y;
}

Point Point::operator-(float _value) const
{
	return Point{ x - _value, y - _value };
}

Point Point::operator-(Point const& _value) const
{
	return Point{ x - _value.x, y - _value.y };
}

void Point::operator-=(float _value)
{
	x -= _value;
	y -= _value;
}

void Point::operator-=(Point const& _value)
{
	x -= _value.x;
	y -= _value.y;
}

Point Point::operator*(float _value) const
{
	return Point{ x * _value, y * _value };
}

Point Point::operator*(Point const& _value) const
{
	return Point{ x * _value.x, y * _value.y };
}

void Point::operator*=(float _value)
{
	x *= _value;
	y *= _value;
}

void Point::operator*=(Point const& _value)
{
	x *= _value.x;
	y *= _value.y;
}

Point Point::operator/(float _value) const
{
	return Point{ x / _value, y / _value };
}

Point Point::operator/(Point const& _value) const
{
	return Point{ x / _value.x, y / _value.y };
}

void Point::operator/=(float _value)
{
	x /= _value;
	y /= _value;
}

void Point::operator/=(Point const& _value)
{
	x /= _value.x;
	y /= _value.y;
}