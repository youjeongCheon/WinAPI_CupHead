#include "framework.h"
#include "CPlayer.h"

#include "CPlayerStateIdle.h"
#include "CPlayerStateRun.h"
#include "CPlayerStateJump.h"
#include "CPlayerStateDash.h"
#include "CPlayerStateDuck.h"
#include "CPlayerStateAim.h"
#include "CPlayerStateShoot.h"
#include "CPlayerStateSpecialAttack.h"
#include "CPlayerStateTakeHit.h"

#include "CMissile.h"
#include "CState.h"

CPlayer::CPlayer()
{
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Player;
	m_strName = L"플레이어";
	m_curState = PlayerState::Run;

	m_pIdleImage = nullptr;
	m_pRunImage = nullptr;
	m_pJumpImage = nullptr;
	m_pDashImage = nullptr;
	m_pDuckImage = nullptr;
	m_pDuckIdleImage = nullptr;
	m_pAimImage = nullptr;
	m_pShootImage = nullptr;
	m_pRunShootImage = nullptr;
	m_pParryImage = nullptr;
	m_pSpecialAttackImage = nullptr;
	m_pTakeHitImage = nullptr;

	m_vecMoveDir = Vector(0, 0);
	m_vecLookDir = Vector(1, 0);

	bIsGround = true;
}

CPlayer::~CPlayer()
{
}

void CPlayer::SetPos(Vector pos)
{
	if (pos.x < 70)
		m_vecPos.x = 70;
	else 
		m_vecPos.x = pos.x;
	m_vecPos.y = pos.y;
}

void CPlayer::SetPos(float x, float y)
{
	if (x < 70)
		m_vecPos.x = 70;
	else
		m_vecPos.x = x;
	m_vecPos.y = y;
}

void CPlayer::ChangeState(PlayerState state)
{
	m_mapState[m_curState]->Exit();
	m_curState = state;
	m_mapState[m_curState]->Enter();
}

void CPlayer::SetStateName(wstring strState)
{
	m_strState = strState;
}

Vector CPlayer::GetLookDir()
{
	return m_vecLookDir;
}

void CPlayer::SetLookDir(Vector vecLookDir)
{
	m_vecLookDir = vecLookDir;
}

bool CPlayer::isGround()
{
	if (m_vecPos.y > PLAYERSTARTPOS.y)
	{
		bIsGround = false;
	}
	else
	{
		bIsGround = true;
	}

	return bIsGround;
}

void CPlayer::Init()
{
#pragma region ImageLoad
	m_pIdleImage = RESOURCE->LoadImg(L"PlayerIdle", L"Image\\cuphead_idle.png");
	m_pRunImage = RESOURCE->LoadImg(L"PlayerRun", L"Image\\cuphead_run.png");
	m_pJumpImage = RESOURCE->LoadImg(L"PlayerJump", L"Image\\cuphead_jump.png");
	m_pDashImage = RESOURCE->LoadImg(L"PlayerDash", L"Image\\cuphead_dash.png");
	m_pDuckImage = RESOURCE->LoadImg(L"PlayerDuck", L"Image\\cuphead_duck.png");
	m_pDuckIdleImage = RESOURCE->LoadImg(L"PlayerDuckIdle", L"Image\\cuphead_duckIdle.png");
	m_pAimImage = RESOURCE->LoadImg(L"PlayerAim", L"Image\\cuphead_aim.png");
	m_pShootImage = RESOURCE->LoadImg(L"PlayerShoot", L"Image\\cuphead_shoot.png");
	m_pRunShootImage = RESOURCE->LoadImg(L"PlayerRunShoot", L"Image\\cuphead_runShoot.png");
	m_pParryImage = RESOURCE->LoadImg(L"PlayerParry", L"Image\\cuphead_parry.png");
	m_pSpecialAttackImage = RESOURCE->LoadImg(L"PlayerSpecialAttack", L"Image\\cuphead_ex_move.png");
	m_pTakeHitImage = RESOURCE->LoadImg(L"PlayerTakeHit", L"Image\\cuphead_hit.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"IdleRight", m_pIdleImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 8);
	m_pAnimator->CreateAnimation(L"IdleLeft", m_pIdleImage, Vector(0.f, 200.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 8);
	m_pAnimator->CreateAnimation(L"RunRight", m_pRunImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.05f, 16);
	m_pAnimator->CreateAnimation(L"RunLeft", m_pRunImage, Vector(0.f, 200.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.05f, 16);
	m_pAnimator->CreateAnimation(L"JumpRight", m_pJumpImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.05f, 8);
	m_pAnimator->CreateAnimation(L"JumpLeft", m_pJumpImage, Vector(0.f, 200.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.05f, 8);
	m_pAnimator->CreateAnimation(L"DashRight", m_pDashImage, Vector(0.f, 0.f), Vector(500.f, 200.f), Vector(500.f, 0.f), 0.05f, 8, false);
	m_pAnimator->CreateAnimation(L"DashLeft", m_pDashImage, Vector(0.f, 200.f), Vector(500.f, 200.f), Vector(500.f, 0.f), 0.05f, 8, false);
	m_pAnimator->CreateAnimation(L"DuckRight", m_pDuckImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 7, false);
	m_pAnimator->CreateAnimation(L"DuckLeft", m_pDuckImage, Vector(0.f, 200.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 7, false);
	m_pAnimator->CreateAnimation(L"DuckRightIdle", m_pDuckIdleImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 5);
	m_pAnimator->CreateAnimation(L"DuckLeftIdle", m_pDuckIdleImage, Vector(0.f, 200.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 5);
	m_pAnimator->CreateAnimation(L"AimRightUp", m_pAimImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 8);
	m_pAnimator->CreateAnimation(L"AimRightDigonalUp", m_pAimImage, Vector(0.f, 200.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 8);
	m_pAnimator->CreateAnimation(L"AimRight", m_pAimImage, Vector(0.f, 400.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 8);
	m_pAnimator->CreateAnimation(L"AimRightDigonalDown", m_pAimImage, Vector(0.f, 600.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 8);
	m_pAnimator->CreateAnimation(L"AimRightDown", m_pAimImage, Vector(0.f, 800.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 8);
	m_pAnimator->CreateAnimation(L"AimLeftUp", m_pAimImage, Vector(0.f, 1000.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 8);
	m_pAnimator->CreateAnimation(L"AimLeftDigonalUp", m_pAimImage, Vector(0.f, 1200.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 8);
	m_pAnimator->CreateAnimation(L"AimLeft", m_pAimImage, Vector(0.f, 1400.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 8);
	m_pAnimator->CreateAnimation(L"AimLeftDigonalDown", m_pAimImage, Vector(0.f, 1600.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 8);
	m_pAnimator->CreateAnimation(L"AimLeftDown", m_pAimImage, Vector(0.f, 1800.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 8);
	m_pAnimator->CreateAnimation(L"ShootRightUp", m_pShootImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 3, false);
	m_pAnimator->CreateAnimation(L"ShootRightDigonalUp", m_pShootImage, Vector(0.f, 200.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 3, false);
	m_pAnimator->CreateAnimation(L"ShootRight", m_pShootImage, Vector(0.f, 400.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 3, false);
	m_pAnimator->CreateAnimation(L"ShootRightDigonalDown", m_pShootImage, Vector(0.f, 600.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 3, false);
	m_pAnimator->CreateAnimation(L"ShootRightDown", m_pShootImage, Vector(0.f, 800.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 3, false);
	m_pAnimator->CreateAnimation(L"ShootLeftUp", m_pShootImage, Vector(0.f, 1000.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 3, false);
	m_pAnimator->CreateAnimation(L"ShootLeftDigonalUp", m_pShootImage, Vector(0.f, 1200.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 3, false);
	m_pAnimator->CreateAnimation(L"ShootLeft", m_pShootImage, Vector(0.f, 1400.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 3, false);
	m_pAnimator->CreateAnimation(L"ShootLeftDigonalDown", m_pShootImage, Vector(0.f, 1600.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 3, false);
	m_pAnimator->CreateAnimation(L"ShootLeftDown", m_pShootImage, Vector(0.f, 1800.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 3, false);
	m_pAnimator->CreateAnimation(L"RunShootImageRight", m_pRunShootImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 16);
	m_pAnimator->CreateAnimation(L"RunShootImageLeft", m_pRunShootImage, Vector(0.f, 200.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 16);
	m_pAnimator->CreateAnimation(L"ParryRight", m_pParryImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 16, false);
	m_pAnimator->CreateAnimation(L"ParryLeft", m_pParryImage, Vector(0.f, 200.f), Vector(200.f, 200.f), Vector(200.f, 0.f), 0.1f, 16, false);
	m_pAnimator->CreateAnimation(L"SpecialAttackRight", m_pSpecialAttackImage, Vector(0.f, 0.f), Vector(400.f, 400.f), Vector(200.f, 0.f), 0.1f, 15, false);
	m_pAnimator->CreateAnimation(L"SpecialAttackLeft", m_pSpecialAttackImage, Vector(0.f, 400.f), Vector(400.f, 400.f), Vector(200.f, 0.f), 0.1f, 15, false);
	m_pAnimator->CreateAnimation(L"TakeHitRight", m_pTakeHitImage, Vector(0.f, 0.f), Vector(200.f, 300.f), Vector(200.f, 0.f), 0.1f, 6, false);
	m_pAnimator->CreateAnimation(L"TakeHitLeft", m_pTakeHitImage, Vector(0.f, 300.f), Vector(200.f, 300.f), Vector(200.f, 0.f), 0.1f, 6, false);

	AddComponent(m_pAnimator);
#pragma endregion

	AddCollider(ColliderType::Rect, Vector(120, 160), Vector(0, 0));

	m_mapState.insert(make_pair(PlayerState::Idle, new CPlayerStateIdle(this)));
	m_mapState.insert(make_pair(PlayerState::Run, new CPlayerStateRun(this)));
	m_mapState.insert(make_pair(PlayerState::Jump, new CPlayerStateJump(this)));
	m_mapState.insert(make_pair(PlayerState::Dash, new CPlayerStateDash(this)));
	m_mapState.insert(make_pair(PlayerState::Duck, new CPlayerStateDuck(this)));
	m_mapState.insert(make_pair(PlayerState::Aim, new CPlayerStateAim(this)));
	m_mapState.insert(make_pair(PlayerState::Shoot, new CPlayerStateShoot(this)));
	m_mapState.insert(make_pair(PlayerState::SpecialAttack, new CPlayerStateSpecialAttack(this)));
	m_mapState.insert(make_pair(PlayerState::TakeHit, new CPlayerStateTakeHit(this)));
}

void CPlayer::Update()
{
	

	m_mapState[m_curState]->Update();
	AnimatorUpdate();
}

void CPlayer::Render()
{
	
}

void CPlayer::Release()
{
}

void CPlayer::AnimatorUpdate()
{
	m_pAnimator->Play(m_strState, false);
}

void CPlayer::CreateMissile()
{
	Logger::Debug(L"미사일 생성");

	CMissile* pMissile = new CMissile();
	pMissile->SetPos(m_vecPos);
	pMissile->SetDir(Vector(1, 0));
	ADDOBJECT(pMissile);

}

void CPlayer::OnCollisionEnter(CCollider* pOtherCollider)
{
}

void CPlayer::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CPlayer::OnCollisionExit(CCollider* pOtherCollider)
{
}
