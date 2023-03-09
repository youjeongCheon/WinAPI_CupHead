#pragma once
#include "CMonster.h"

class CAnimator;
class CSound;

class CMonsterPotato : public CMonster
{
public:
	CMonsterPotato();
	~CMonsterPotato();

private:
	wstring m_strState;

	CImage* m_pPotato;

	CAnimator* m_pAnimator;
	CAnimator* m_pAnimatorEarth;

	CSound* pShootSFX = RESOURCE->LoadSound(L"boss_shoot", L"Sound\\boss_shoot.wav");
	CSound* pDeathSFX = RESOURCE->LoadSound(L"boss_death", L"Sound\\boss_death.wav");

	int missileCount;
	float fEarthCoolTime;
	bool isDeath = false;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void AnimatorUpdate();

	void CreateMissile();
	void CreateParry();

};

