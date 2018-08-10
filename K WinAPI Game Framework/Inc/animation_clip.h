#pragma once

#include "tag.h"

class Texture;

class AnimationClip : public Tag
{
	friend class AnimationManager;
private:
	AnimationClip() = default;
	AnimationClip(AnimationClip const& _other);
	AnimationClip(AnimationClip&& _other) noexcept;
	AnimationClip& operator=(AnimationClip const&) = default;
	AnimationClip& operator=(AnimationClip&&) noexcept = default;

	virtual void _Release() override;

	ANIMATION_CLIP type_{};
	ANIMATION_OPTION option_{};
	TYPE::AnimationClipInfo animation_clip_info_{};
	float completion_time_{};

	std::weak_ptr<Texture> texture_{};
};