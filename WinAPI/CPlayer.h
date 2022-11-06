#pragma once
#include "CGameObject.h"

class CImage;
class CAnimator;

class CState;

enum class PlayerState
{
	Idle, Run, Jump, Dash, Duck, Aim, Shoot, RunShoot,  Parry, SpecialAttack, TakeHit
};

class CPlayer : public CGameObject
{
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

	bool bIsGround;

public:
	void SetPos(Vector pos);
	void SetPos(float x, float y);

	void ChangeState(PlayerState state);
	void SetStateName(wstring strState);

	Vector GetLookDir();
	void SetLookDir(Vector vecLookDir);
	
	bool isGround();

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void AnimatorUpdate();
	void CreateMissile();

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

#define PLAYERSTARTPOS Vector(200, WINSIZEY*0.75f)