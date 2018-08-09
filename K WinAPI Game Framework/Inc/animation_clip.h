#pragma once

class Texture;

class AnimationClip
{
	friend class AnimationManager;
private:
	AnimationClip() = default;
	AnimationClip(AnimationClip const& _other);
	AnimationClip(AnimationClip&& _other) noexcept;
	AnimationClip& operator=(AnimationClip const&) = default;
	AnimationClip& operator=(AnimationClip&&) noexcept = default;

	void _Release();

	std::weak_ptr<Texture> texture_{};

	std::string tag_{};
	ANIMATION_CLIP_TYPE type_{};
	ANIMATION_OPTION option_{};
	TYPE::AnimationClipInfo animation_clip_info_{};
	float completion_time_{};
};