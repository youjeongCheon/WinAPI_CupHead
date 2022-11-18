#include "framework.h"
#include "CMonsterOnion.h"

#include "COnionMissile.h"
#include "COnionParry.h"
#include "CMonsterEarthEffect.h"
#include "CMonsterCarrot.h"

CMonsterOnion::CMonsterOnion()
{
	m_curState = MonsterState::Null;
	m_strState = L"";
	fCoolTime = 0;
	missileCount = 1;
	m_pAnimator = nullptr;
	pEarthEffect = nullptr;
}

CMonsterOnion::~CMonsterOnion()
{
}

void CMonsterOnion::Init()
{
	m_HP = 100;
	CImage* pOnionIntro = RESOURCE->LoadImg(L"OnionIntro", L"Image\\Onion_Intro.png");
	CImage* pOnionIdle = RESOURCE->LoadImg(L"OnionIdle", L"Image\\Onion_Idle.png");
	CImage* pOnionTransCry = RESOURCE->LoadImg(L"OnionTransCry", L"Image\\Onion_TransCry.png");
	CImage* pOnionCry = RESOURCE->LoadImg(L"OnionCry", L"Image\\Onion_Cry.png");
	CImage* pOnionDeath = RESOURCE->LoadImg(L"OnionDeath", L"Image\\Onion_Death.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"OnionNull", pOnionIntro, Vector(0, 0), Vector(10, 10), Vector(10, 0.f), 0.1f, 1, false);
	m_pAnimator->CreateAnimation(L"OnionIntro1", pOnionIntro, Vector(0, 0), Vector(700, 700), Vector(700, 0.f), 0.1f, 12, false);
	m_pAnimator->CreateAnimation(L"OnionIntro2", pOnionIntro, Vector(0, 700), Vector(700, 700), Vector(700, 0.f), 0.1f, 12, false);
	m_pAnimator->CreateAnimation(L"OnionIdle1", pOnionIdle, Vector(0, 0), Vector(700, 700), Vector(700, 0.f), 0.1f, 14);
	m_pAnimator->CreateAnimation(L"OnionIdle2", pOnionIdle, Vector(0, 700), Vector(700, 700), Vector(700, 0.f), 0.1f, 14);
	m_pAnimator->CreateAnimation(L"OnionTransCry", pOnionTransCry, Vector(0, 0), Vector(700, 700), Vector(700, 0.f), 0.1f, 22, false);
	m_pAnimator->CreateAnimation(L"OnionCry", pOnionCry, Vector(0, 0), Vector(700, 700), Vector(700, 0.f), 0.05f, 16);
	m_pAnimator->CreateAnimation(L"OnionDeath1", pOnionDeath, Vector(0, 0), Vector(700, 700), Vector(700, 0.f), 0.1f, 19,false);
	m_pAnimator->CreateAnimation(L"OnionDeath2", pOnionDeath, Vector(0, 700), Vector(700, 700), Vector(700, 0.f), 0.1f, 19, false);
	AddComponent(m_pAnimator);

	pEarthEffect = new CMonsterEarthEffect();
	pEarthEffect->SetPos(m_vecPos.x,m_vecPos.y+150);
	ADDOBJECT(pEarthEffect);

	AddCollider(ColliderType::Rect, Vector(200, 300), Vector(0, 0));
	GetCollider()->SetChangePos(Vector(m_vecPos.x, m_vecPos.y + 150));
}

void CMonsterOnion::Update()
{
	srand(time(NULL));

	fCoolTime += DT;
	m_strState = L"Onion";
	switch (m_curState)
	{
	case MonsterState::Null:
		m_strState += L"Null";
		if (fCoolTime >= 0.9f)
			ChangeState(MonsterState::Intro);
		break;
	case MonsterState::Intro:
		m_strState += L"Intro";
		if(fCoolTime<=1.2f)
			m_strState += L"1";
		else if(fCoolTime > 1.2f)
			m_strState += L"2";
		if (fCoolTime > 2.4f)
			ChangeState(MonsterState::Idle);
		break;
	case MonsterState::Idle:
		m_strState += L"Idle";
		if (fCoolTime <= 1.4f)
			m_strState += L"1";
		else if (fCoolTime > 1.4f )
			m_strState += L"2";
		if (fCoolTime > 2.8f)
			ChangeState(MonsterState::Trans);
		break;
	case MonsterState::Trans:
		m_strState += L"TransCry";
		if (fCoolTime > 2.2f)
			ChangeState(MonsterState::Attack);
		break;
	case MonsterState::Attack:
		m_strState += L"Cry";
		if (fCoolTime > 0.5f && missileCount % 4 != 0)
		{
			CreateMissile();
			fCoolTime = 0;
			missileCount++;
		}
		else if (fCoolTime > 0.5f && missileCount % 4 == 0)
		{
			CreateParry();
			fCoolTime = 0;
			missileCount++;
		}
		break;
	case MonsterState::Death:
		m_strState += L"Death";
		if (fCoolTime < 1.9f)
			m_strState += L"1";
		else if (fCoolTime >= 1.9f)
			m_strState += L"2";
		if (fCoolTime >= 3.8f)
		{
			DELETEOBJECT(this);
			DELETEOBJECT(pEarthEffect);
			CMonsterCarrot* pMonsterCarrot = new CMonsterCarrot();
			pMonsterCarrot->SetPos(WINSIZEX * 0.5, WINSIZEY * 0.4);
			ADDOBJECT(pMonsterCarrot);
		}
		break;
	}
	AnimatorUpdate();
}

void CMonsterOnion::Render()
{
}

void CMonsterOnion::Release()
{
}

void CMonsterOnion::AnimatorUpdate()
{
	m_pAnimator->Play(m_strState, false);
}

void CMonsterOnion::CreateMissile()
{
	COnionMissile* pMissile = new COnionMissile();
	pMissile->SetPos(100 * (rand() % 11 + 1), 0);
	ADDOBJECT(pMissile);
}

void CMonsterOnion::CreateParry()
{
	COnionParry* pParry = new COnionParry();
	ADDOBJECT(pParry);
}
