#pragma once
#include "CMonster.h"

class CAnimator;
class CMonsterEarthEffect;

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

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void AnimatorUpdate();

	void CreateMissile();
	void CreateParry();
};

