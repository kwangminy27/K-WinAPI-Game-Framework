#pragma once

#include "singleton.h"

class AudioManager final : public Singleton<AudioManager>
{
	friend class Singleton<AudioManager>;
public:
	bool Initialize();
	void Update();
	void Suspend();
	void Resume();

	std::shared_ptr<DirectX::SoundEffect> const& FindSoundEffect(std::string const& _tag);
	void AddSoundEffectInstance(std::unique_ptr<DirectX::SoundEffectInstance> _sound_effect_instance);

private:
	AudioManager() = default;
	AudioManager(AudioManager const&) = delete;
	AudioManager& operator=(AudioManager const&) = delete;

	virtual void _Release() override;

	bool _LoadSoundDataSheet(std::wstring const& _file_name, std::string const& _path_tag = "DataPath");
	bool _LoadSoundEffect(std::string const& _tag, std::wstring const& _file_name, std::string const& _path_tag = "SoundPath");

	std::shared_ptr<DirectX::SoundEffect> sound_effect_nullptr_{};

	std::unique_ptr<DirectX::AudioEngine> audio_engine_{};
	std::unordered_map<std::string, std::shared_ptr<DirectX::SoundEffect>> sound_effect_map_{};
	std::list<std::unique_ptr<DirectX::SoundEffectInstance>> sound_effect_instance_list_{};
};