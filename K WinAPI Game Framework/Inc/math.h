#pragma once

class Math
{
public:
	static float PI();
	static float GetDistance(TYPE::Point const& src, TYPE::Point const& dest);
	static float GetAngle(TYPE::Point const& src, TYPE::Point const& dest);
	static float ConvertToDegrees(float radians);
	static float ConvertToRadians(float degrees);
};