#pragma once
#include "CMonster.h"

class CAnimator;

class CMonsterPotato : public CMonster
{
public:
	CMonsterPotato();
	~CMonsterPotato();

private:
	wstring m_strState;

	CImage* m_pPotato;
	CImage* m_pHitPotato;
	
	CImage* m_pImage;

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

