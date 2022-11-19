#pragma once
#include "CMonster.h"
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

	int missileCount;
	int beamCount;
	bool bBeamCreate;
	float fMissileCoolTime;

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

