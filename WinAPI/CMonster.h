#pragma once
#include "CGameObject.h"

enum class MonsterState { Null, Intro, Idle, Attack, TransIdle, Death, DeathLeave };

class CMonster : public CGameObject
{
public:
	CMonster();
	virtual ~CMonster();

protected:
	MonsterState m_curState;
	int m_HP;
	bool bTakeHit;
	 
	float fImageCoolTime;
	float fCoolTime;

	virtual bool CollisionRange( Vector pos);
	void ChangeState(MonsterState state);

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

