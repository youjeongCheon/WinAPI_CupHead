#pragma once

#include "CMonsterMissile.h"

class CCarrotBeam : public CMonsterMissile
{
public:
	CCarrotBeam();
	virtual ~CCarrotBeam();

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOther)	override;
};
