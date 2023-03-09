#pragma once
#include "CMonster.h"

class CSound;

class CMonsterCarrot : public CMonster
{
public:
	CMonsterCarrot();
	~CMonsterCarrot();

private:
	wstring m_strState;

	CImage* m_pCarrot;

	CAnimator* m_pAnimator;
	CAnimator* m_pAnimatorEarth;

	CSound* pAppearSFX = RESOURCE->LoadSound(L"boos_carrot_appear", L"Sound\\boss_carrot_appear.wav");
	CSound* pDeathSFX = RESOURCE->FindSound(L"pDeathSFX");
	CSound* pShootSFX = RESOURCE->LoadSound(L"boss_shoot", L"Sound\\boss_shoot.wav");
	CSound* pBeamSFX = RESOURCE->LoadSound(L"boos_beam", L"Sound\\boss_beam.wav");

	bool isAppear = false;
	bool isDeath = false;

	int missileCount;
	int beamCount;
	bool bBeamCreate;
	float fMissileCoolTime;
	float fDeathCoolTime;

	Vector m_vecBeamDir;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void AnimatorUpdate();

	void CreateMissile();
	void CreateBeam();
};

