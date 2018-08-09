#include "stdafx.h"
#include "tag.h"

using namespace std;

string const& Tag::tag() const
{
	return tag_;
}

void Tag::set_tag(string const& _tag)
{
	tag_ = _tag;
}

bool Tag::enablement() const
{
	return enablement_;
}

void Tag::set_enablement(bool _state)
{
	enablement_ = _state;
}

bool Tag::activation() const
{
	return activation_;
}

void Tag::set_activation(bool _state)
{
	activation_ = _state;
}

Tag::Tag(Tag const& _other)
{
	*this = _other;
}

Tag::Tag(Tag&& _other) noexcept
{
	*this = move(_other);
}