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

	struct AnimationClipInfo
	{
		int frame_width{};
		int frame_height{};
		int start_x{};
		int start_y{};
		int end_x{};
		int count_x{};
		int count_y{};
		int total_count{};
	};
};