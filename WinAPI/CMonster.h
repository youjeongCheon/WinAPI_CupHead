#pragma once
#include "CGameObject.h"

class CMonster : public CGameObject
{
public:
	CMonster();
	virtual ~CMonster();

protected:
	int m_HP;
	
public:
	void SetHP(int hp);
	int GetHP();

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

