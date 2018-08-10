#pragma once

#include "tag.h"

class Scene;
class Layer;
class Texture;
class Animation;

class Object : public Tag, public std::enable_shared_from_this<Object>
{
	friend class Layer;
	friend class ObjectManager;
public:
	OBJECT type() const;

	std::shared_ptr<Scene> scene() const;
	void set_scene(std::shared_ptr<Scene> const& _scene);

	std::shared_ptr<Layer> layer() const;
	void set_layer(std::shared_ptr<Layer> const& _layer);

	std::shared_ptr<Texture> texture() const;
	void set_texture(std::string const& _tag);
	void set_texture(std::shared_ptr<Texture> const& _texture);

	COLORREF const& color_key() const;
	void set_color_key(COLORREF const& _color_key);

protected:
	Object() = default;
	Object(Object const& _other);
	Object(Object&& _other) noexcept;
	Object& operator=(Object const&) = default;
	Object& operator=(Object&&) noexcept = default;
	virtual ~Object() = default;

	virtual void _Release() override;

	virtual bool _Initialize();
	virtual void _Input(float _time);
	virtual void _Update(float _time);
	virtual void _LateUpdate(float _time);
	virtual void _Collision(float _time);
	virtual void _Render(HDC _device_context, float _time);

	bool _AddAnimationClip(std::string const& _tag);

	virtual std::unique_ptr<Object, std::function<void(Object*)>> _Clone() const = 0;

	OBJECT type_{ OBJECT::NONE };

	std::weak_ptr<Scene> scene_{};
	std::weak_ptr<Layer> layer_{};

	std::shared_ptr<Texture> texture_{};
	COLORREF color_key_{};
	bool is_color_key_{};

	std::unique_ptr<Animation, std::function<void(Animation*)>> animation_{};
};