#pragma once
#include "CGameObject.h"

class CParryObject :  public CGameObject
{
public:
	CParryObject();
	virtual~CParryObject();

protected:
	Vector m_vecDir;
	float m_fVelocity;

	void Init() override;
private:
	CImage* m_pParrySpikle;
	CAnimator* m_pAnimator;

	bool bParry;
	bool bParryExit;

	void CreateSpikle();
public:
	void SetDir(Vector dir);
	void SetVelocity(float velocity);
	bool GetParry();

private:

	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;

};

