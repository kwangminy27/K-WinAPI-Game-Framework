#include "stdafx.h"
#include "texture_manager.h"

#include "texture.h"

using namespace std;

bool TextureManager::Initialize()
{
	_LoadTexture("Test", L"Test.bmp");

	return true;
}

shared_ptr<Texture> const& TextureManager::FindTexture(string const& _tag) const
{
	auto iter = texture_map_.find(_tag);

	if (iter == texture_map_.end())
		return texture_nullptr_;

	return iter->second;
}

void TextureManager::_Release()
{
}

bool TextureManager::_LoadTexture(string const& _tag, wstring const& _file_name, string const& _path_tag)
{
	if (FindTexture(_tag))
		return false;

	auto texture = shared_ptr<Texture>{ new Texture, [](Texture* _p) {
		_p->_Release();
		delete _p;
	} };

	texture->set_tag(_tag);

	if (!texture->_LoadTexture(_tag, _file_name, _path_tag))
		return false;

	texture_map_.insert(make_pair(_tag, move(texture)));

	return true;
}