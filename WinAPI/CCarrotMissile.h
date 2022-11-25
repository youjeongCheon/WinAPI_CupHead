#pragma once
#include "CMonsterMissile.h"
class CCarrotMissile : public CMonsterMissile
{
public:
	CCarrotMissile();
	virtual ~CCarrotMissile();

private:
	CImage* pImgMissile;
	Vector* m_fAngle;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOther)	override;
};

