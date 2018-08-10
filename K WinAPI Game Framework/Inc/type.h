#pragma once

namespace TYPE
{
	struct Point
	{
		float x{};
		float y{};

		Point operator+(float _value) const;
		Point operator+(Point const& _value) const;
		void operator+=(float _value);
		void operator+=(Point const& _value);

		Point operator-(float _value) const;
		Point operator-(Point const& _value) const;
		void operator-=(float _value);
		void operator-=(Point const& _value);

		Point operator*(float _value) const;
		Point operator*(Point const& _value) const;
		void operator*=(float _value);
		void operator*=(Point const& _value);

		Point operator/(float _value) const;
		Point operator/(Point const& _value) const;
		void operator/=(float _value);
		void operator/=(Point const& _value);
	};

	struct Rectangle
	{
		float left{};
		float top{};
		float right{};
		float bottom{};
	};

	struct Circle
	{
		Point center{};
		float radius{};
	};
};