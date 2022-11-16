#pragma once
#include "CGameObject.h"
class CMonsterMissile :  public CGameObject
{
public:
	CMonsterMissile();
	virtual~CMonsterMissile();

protected:
	Vector m_vecDir;
	float m_fVelocity;
	
public:
	void SetDir(Vector dir);
	void SetVelocity(float velocity);

private:
	void OnCollisionEnter(CCollider* pOtherCollider) override;
};

