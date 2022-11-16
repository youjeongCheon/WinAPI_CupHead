#pragma once
#include "CGameObject.h"

class CImage;
class CAnimator;

class CState;

enum class PlayerState
{
	Idle, Run, Jump, Parry, Fall,Dash, Duck, Aim, Shoot, SpecialAttack, TakeHit
};

class CPlayer : public CGameObject
{
	friend CState;

public:
	CPlayer();
	virtual ~CPlayer();

private:
	map< PlayerState, CState*> m_mapState;

	PlayerState m_curState;
	PlayerState m_preState;
	
	wstring m_strState;

	CAnimator* m_pAnimator;

	CImage* m_pIdleImage;
	CImage* m_pRunImage;
	CImage* m_pJumpImage;
	CImage* m_pDashImage;
	CImage* m_pDuckImage;
	CImage* m_pDuckIdleImage;
	CImage* m_pAimImage;
	CImage* m_pShootImage;
	CImage* m_pRunShootImage;
	CImage* m_pParryImage;
	CImage* m_pSpecialAttackImage;
	CImage* m_pTakeHitImage;

	Vector m_vecMoveDir;
	Vector m_vecLookDir;

	Vector	m_vecColliderScale;
	bool	bIsGround;
	bool	bIsOnBlock;
	bool	bPassBlock;

	int		m_ColliderCount;
	int		m_SpecialAttackCount;

	int m_HP;

public:

	void ChangeState(PlayerState state);
	PlayerState GetCurState();
	PlayerState GetPreState();
	void SetStateName(wstring strState);

	Vector GetLookDir();
	void SetLookDir(Vector vecLookDir);
	void SetMoveDir(Vector vecMoveDir);
	
	void SetColliderCount(int count);
	int GetColliderCount();
	bool isGround();
	void SetGround(bool ground);
	void SetOnBlock(bool onBlock);
	bool GetOnBlock();
	void SetPassBlock(bool passBlock);
	bool GetPassBlock();
	void SetHP(int hp);
	int GetHp();

	bool ActGravity();

	void CreateMissile(Vector pos, Vector direction, bool ExMissile= false);

	void SetSpecialAttackCount(int count);
	int GetSpecialAttackCount();

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void AnimatorUpdate();

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

#define PLAYERSTARTPOS Vector(200, WINSIZEY*0.72f)