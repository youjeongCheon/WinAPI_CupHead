#pragma once
#include "CGameObject.h"

class CMonster : public CGameObject
{
public:
	CMonster();
	virtual ~CMonster();

protected:
	int m_HP;
	bool bTakeHit;
	 
	float fImageCoolTime;
public:
	void SetHP(int hp);
	int GetHP();
	bool GetTakeHit();

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

