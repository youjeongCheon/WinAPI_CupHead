#pragma once
#include "CGameObject.h"

class CImage;
class CAnimator;

class CState;

enum class PlayerState
{
	Idle, Run, Jump, Dash, Duck, Aim, Shoot, SpecialAttack, TakeHit
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
	int		num; // 1 : 왼쪽에서 충돌, 2 : 위쪽에 충돌, 3 : 오른쪽에서 충돌, 4 : 아래쪽에서 충돌
	bool	bPassBlock;

public:

	void ChangeState(PlayerState state);
	PlayerState GetCurState();
	void SetStateName(wstring strState);

	Vector GetLookDir();
	void SetLookDir(Vector vecLookDir);
	void SetMoveDir(Vector vecMoveDir);
	bool GetPassBlock();
	void SetPassBlock(bool passBlock);
	
	bool isGround();
	void SetGround(bool ground);

	void CreateMissile(Vector pos, Vector direction, bool ExMissile= false);

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