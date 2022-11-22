#include "framework.h"
#include "CMonsterPotato.h"

#include "CPotatoMissile.h"
#include "CPotatoParry.h"
#include "CMonsterOnion.h"
#include "CMonsterCarrot.h"
#include "CMonsterEarthEffect.h"

CMonsterPotato::CMonsterPotato()
{
	m_curState = MonsterState::Null;
	m_strState = L"";
	m_pPotato= nullptr;
	fCoolTime = 0;
	missileCount = 0;
	m_pAnimator = nullptr;

	fEarthCoolTime = 0;
	m_pAnimatorEarth = nullptr;
}

CMonsterPotato::~CMonsterPotato()
{
}

void CMonsterPotato::Init()
{
	m_HP = 50;

	m_pPotato = RESOURCE->LoadImg(L"Potato", L"Image\\Botanic_Panic_Potato.png");

	CImage* pPotatoIntro = RESOURCE->LoadImg(L"PotatoIntro", L"Image\\Potato_Intro.png");
	CImage* pPotatoIdle = RESOURCE->LoadImg(L"PotatoIdle", L"Image\\Potato_Idle.png");
	CImage* pPotatoAttack = RESOURCE->LoadImg(L"PotatoAttack", L"Image\\Potato_Attack.png");
	CImage* pPotatoTransIdle = RESOURCE->LoadImg(L"PotatoTransIdle", L"Image\\Potato_TransIdle.png");
	CImage* pPotatoDeath = RESOURCE->LoadImg(L"PotatoDeath", L"Image\\Potato_Death.png");
	CImage* pPotatoDeathLeave = RESOURCE->LoadImg(L"PotatoDeathLeave", L"Image\\Potato_DeathLeave.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"PotatoNull", pPotatoIntro, Vector(0, 0), Vector(10, 10), Vector(10, 0.f), 0.1f, 1, false);
	m_pAnimator->CreateAnimation(L"PotatoIntro", pPotatoIntro, Vector(0, 0), Vector(600, 600), Vector(600, 0.f), 0.1f, 16, false);
	m_pAnimator->CreateAnimation(L"PotatoIdle", pPotatoIdle, Vector(0, 0), Vector(600, 600), Vector(600, 0.f), 0.1f, 16);
	m_pAnimator->CreateAnimation(L"PotatoAttack", pPotatoAttack, Vector(0, 0), Vector(600, 600), Vector(600, 0.f), 0.05f, 17);
	m_pAnimator->CreateAnimation(L"PotatoTransIdle", pPotatoTransIdle, Vector(0, 0), Vector(600, 600), Vector(600, 0.f), 0.1f, 3, false);
	m_pAnimator->CreateAnimation(L"PotatoDeath", pPotatoDeath, Vector(0, 0), Vector(600, 600), Vector(600, 0.f), 0.05f, 16);
	m_pAnimator->CreateAnimation(L"PotatoDeathLeave", pPotatoDeathLeave, Vector(0, 0), Vector(600, 600), Vector(600, 0.f), 0.05f, 16,false);
	AddComponent(m_pAnimator);

	CImage* pEarth = RESOURCE->LoadImg(L"Earth", L"Image\\Botanic_Panic_Potato.png");
	m_pAnimatorEarth = new CAnimator;
	m_pAnimatorEarth->CreateAnimation(L"EarthIntro0", pEarth, Vector(2, 61), Vector(557, 461), Vector(558, 0), 0.1f, 5, false);
	m_pAnimatorEarth->CreateAnimation(L"EarthIntro1", pEarth, Vector(2, 523), Vector(557, 461), Vector(558, 0), 0.1f, 5, false);
	m_pAnimatorEarth->CreateAnimation(L"EarthIntro2", pEarth, Vector(2, 985), Vector(557, 461), Vector(558, 0), 0.1f, 5, false);
	m_pAnimatorEarth->CreateAnimation(L"EarthIntro3", pEarth, Vector(2, 1447), Vector(557, 461), Vector(558, 0), 0.1f, 3, false);
	AddComponent(m_pAnimatorEarth);

	AddCollider(ColliderType::Rect, Vector(200, 300), Vector(0, 0));
}

void CMonsterPotato::Update()
{
	fCoolTime += DT;
	fEarthCoolTime += DT;

	wstring strEarth = L"EarthIntro";
	if (fEarthCoolTime < 0.5f)
		strEarth += L"0";
	else if (fEarthCoolTime >= 0.5f && fEarthCoolTime < 1.0f)
		strEarth += L"1";
	else if (fEarthCoolTime >= 1.0f && fEarthCoolTime < 1.5f)
		strEarth += L"2";
	else if (fEarthCoolTime >= 1.5f)
		strEarth += L"3";
	m_pAnimatorEarth->Play(strEarth);

	m_strState = L"Potato";
	switch (m_curState)
	{
	case MonsterState::Null:
		m_strState += L"Null";
		if (fCoolTime >= 0.9f)
			ChangeState(MonsterState::Intro);
		break;
	case MonsterState::Intro:
		m_strState += L"Intro";
		if (fCoolTime > 1.6f)
			ChangeState(MonsterState::Idle);
		break;
	case MonsterState::Idle:
		m_strState += L"Idle";
		if(fCoolTime > 1.6f)
			ChangeState(MonsterState::Attack);
		break;
	case MonsterState::Attack:
		m_strState += L"Attack";
		if (fCoolTime >= 0.75f && fCoolTime < 0.85f && missileCount == 0)
		{
			CreateMissile();
			missileCount++;
		}
		else if (fCoolTime >= 1.65f && fCoolTime < 1.7f && missileCount == 1)
		{
			CreateMissile();
			missileCount++;
		}
		else if (fCoolTime >= 2.5f && fCoolTime < 2.55f && missileCount == 2)
		{
			CreateMissile();
			missileCount++;
		}
		else if (fCoolTime >= 3.35f && fCoolTime < 3.4f && missileCount == 3)
		{
			CreateParry();
			missileCount++;
		}
		if (fCoolTime > 3.4f && missileCount == 4)
		{
			ChangeState(MonsterState::Trans);
			missileCount = 0;
		}
		break;
	case MonsterState::Trans:
		m_strState += L"TransIdle";
		if (fCoolTime > 0.3f)
			ChangeState(MonsterState::Idle);
		break;
	case MonsterState::Death:
		m_strState += L"Death";
		if (fCoolTime > 1.6f)
			ChangeState(MonsterState::DeathLeave);
		break;
	case MonsterState::DeathLeave:
		m_strState += L"DeathLeave";
		if (fCoolTime > 0.8f)
		{
			DELETEOBJECT(this);
			/*CMonsterOnion* pMonsterOnion = new CMonsterOnion();
			pMonsterOnion->SetPos(WINSIZEX * 0.5, WINSIZEY * 0.4);
			ADDOBJECT(pMonsterOnion);*/
		}
		break;
	}
	AnimatorUpdate();
}

void CMonsterPotato::Render()
{
}

void CMonsterPotato::Release()
{
}

void CMonsterPotato::AnimatorUpdate()
{
	
	m_pAnimator->Play(m_strState, false);
}

void CMonsterPotato::CreateMissile()
{
	CPotatoMissile* pMissile= new CPotatoMissile();
	ADDOBJECT(pMissile);
}

void CMonsterPotato::CreateParry()
{
	CPotatoParry* pParry = new CPotatoParry();
	ADDOBJECT(pParry);
}
