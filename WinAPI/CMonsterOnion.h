#pragma once
#include "CMonster.h"

class CAnimator;
class CMonsterEarthEffect;
class CSound;

class CMonsterOnion :  public CMonster
{
public:
	CMonsterOnion();
	~CMonsterOnion();

private:
	wstring m_strState;
	CMonsterEarthEffect* pEarthEffect;
	CAnimator* m_pAnimator;

	int missileCount;
	bool isAppear = false;
	bool isDeath = false;

	CSound* pAppearSFX = RESOURCE->LoadSound(L"boss_appear", L"Sound\\boss_appear.wav");
	CSound* pDeathSFX = RESOURCE->FindSound(L"pDeathSFX");

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void AnimatorUpdate();

	void CreateMissile();
	void CreateParry();
};

