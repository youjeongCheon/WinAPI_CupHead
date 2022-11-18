#pragma once
#include "CMonster.h"

class CAnimator;

class CMonsterOnion :  public CMonster
{
public:
	CMonsterOnion();
	~CMonsterOnion();

private:
	wstring m_strState;

	CAnimator* m_pAnimator;
	CAnimator* m_pAnimatorEarth;

	int missileCount;
	float fEarthCoolTime;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void AnimatorUpdate();

	void CreateMissile();
	void CreateParry();
};

