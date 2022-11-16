#pragma once
#include "CMonster.h"

class CAnimator;
enum Class {Intro, Idle, Attack,TransIdle, Death};

class CMonsterPotato : public CMonster
{
public:
	CMonsterPotato();
	~CMonsterPotato();

private:
	CImage* m_pPotato;
	CImage* m_pHitPotato;
	
	CImage* m_pImage;

	CAnimator* m_pAnimator;
	CAnimator* m_pAnimatorEarth;

	float fCoolTime;
	int missileCount;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void CreateMissile();
	void CreateParry();

};

