#pragma once
#include "CMonsterMissile.h"
class COnionMissile : public CMonsterMissile
{
public:
	COnionMissile();
	virtual ~COnionMissile();

private:
	CImage* m_pImgMissile;
	CImage* m_pImgMissileDeath;
	CAnimator* m_pAnimator;

	bool bCreate;
	bool bDeath;
	float fDeathCoolTime;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void Death();

	void OnCollisionEnter(CCollider* pOther)	override;
};

