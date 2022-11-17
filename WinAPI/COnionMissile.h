#pragma once
#include "CMonsterMissile.h"
class COnionMissile : public CMonsterMissile
{
public:
	COnionMissile();
	virtual ~COnionMissile();

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOther)	override;
};

