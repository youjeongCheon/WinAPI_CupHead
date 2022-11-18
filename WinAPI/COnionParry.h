#pragma once
#include "CParryObject.h"
class COnionParry : public CParryObject
{
public:
	COnionParry();
	virtual ~COnionParry();

private:
	CImage* m_pImgParry;
	CImage* m_pImgParryDeath;
	CAnimator* m_pAnimator;

	bool bDeath;
	bool bCreate;
	float fDeathCoolTime;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void Death();

	void OnCollisionEnter(CCollider* pOther)	override;
};

