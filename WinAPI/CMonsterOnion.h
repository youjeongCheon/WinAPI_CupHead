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
	float curPos = 0;
	float prePos = 0;

	CSound* pAppearSFX = RESOURCE->LoadSound(L"boss_appear", L"Sound\\boss_appear.wav");
	CSound* pDeathSFX = RESOURCE->LoadSound(L"boss_death", L"Sound\\boss_death.wav");

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void AnimatorUpdate();

	void CreateMissile();
	void CreateParry();
	float SetRandPos();
};

