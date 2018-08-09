#include "stdafx.h"
#include "math.h"

using namespace TYPE;

float Math::PI()
{
	static float const kPI = 3.141592654f;
	return kPI;
}

float Math::GetDistance(Point const& src, Point const& dest)
{
	float width = dest.x - src.x;
	float height = dest.y - src.y;
	return sqrt((width * width) + (height * height));
}

float Math::GetAngle(Point const& src, Point const& dest)
{
	float width = dest.x - src.x;
	float diagonal = Math::GetDistance(src, dest);
	float cos_theta = width / diagonal;
	float theta = Math::ConvertToDegrees(acos(cos_theta));

	return dest.y - src.y < 0.f ? -theta : theta;
}

float Math::ConvertToDegrees(float radians)
{
	return radians * (180.f / Math::PI());
}

float Math::ConvertToRadians(float degrees)
{
	return degrees * (Math::PI() / 180.f);
}