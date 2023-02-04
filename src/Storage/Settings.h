#pragma once

#include <SimpleIni.h>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

namespace RE
{
	enum class DIFFICULTY : std::int32_t
	{
		kNovice = 0,
		kApprentice = 1,
		kAdept = 2,
		kExpert = 3,
		kMaster = 4,
		kLegendary = 5
	};
}

class Settings
{
public:
	[[nodiscard]] static Settings* GetSingleton()
	{
		static Settings singleton;
		return &singleton;
	}

    float fDiffMultHPByPCVE;
	float fDiffMultHPByPCE;
	float fDiffMultHPByPCN;
	float fDiffMultHPByPCH;
	float fDiffMultHPByPCVH;
	float fDiffMultHPByPCL;
	float fDiffMultHPToPCVE;
	float fDiffMultHPToPCE;
	float fDiffMultHPToPCN;
	float fDiffMultHPToPCH;
	float fDiffMultHPToPCVH;
	float fDiffMultHPToPCL;
	

	struct
	{
		int StaggerMode{ 1 };
	} Modes;

	struct
	{
		float BaseMult{ 50 };
		float ArmorMult{ 0.25 };
		float RegenRate{ 0.050f };
	} Health;

	struct
	{
		float BashMult{ 1.5 };
		float BowMult{ 1.0 };
		float CreatureMult{ 2.0 };
		float MeleeMult{ 1.0 };
		float UnarmedMult{ 2.0 };

		float ToPCMult{ 1.0 };
		float ToNPCMult{ 1.0 };

		float WeightContribution{ 2.0 };
		float GauntletWeightContribution{ 1.0 };
		float UnarmedSkillContribution{ 0.2 };

	} Damage;

	struct
	{
		bool SpecialBar{ true };
	} TrueHUD;

	json JSONSettings;

	float GetDamageMultiplier(RE::Actor* a_aggressor, RE::Actor* a_target);
	void  LoadGameSettings();
	void  LoadINI(const wchar_t* a_path);
	void  LoadJSON(const wchar_t* a_path);
	void  LoadSettings();

private:
	Settings() = default;
	Settings(const Settings&) = delete;
	Settings(Settings&&) = delete;

	~Settings() = default;

	Settings& operator=(const Settings&) = delete;
	Settings& operator=(Settings&&) = delete;
};
