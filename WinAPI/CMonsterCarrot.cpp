#include "framework.h"
#include "CMonsterCarrot.h"

CMonsterCarrot::CMonsterCarrot()
{
	m_curState = MonsterState::Null;
	m_strState = L"";
	m_pCarrot = nullptr;
	fCoolTime = 0;
	missileCount = 0;
	m_pAnimator = nullptr;
	m_pAnimatorEarth = nullptr;
	m_layer = Layer::MonsterCarrot;
}

CMonsterCarrot::~CMonsterCarrot()
{
}

void CMonsterCarrot::Init()
{
	m_HP = 50;

	m_pCarrot = RESOURCE->LoadImg(L"Carrot", L"Image\\Chauncey_Chantenay.png");

	CImage* pCarrotBeamAttack = RESOURCE->LoadImg(L"CarrotBeamAttack", L"Image\\Carrot_AttackBEam.png");
	CImage* pCarrotTrans = RESOURCE->LoadImg(L"CarrotTrans", L"Image\\Carrot_Trans.png");
	CImage* pCarrotDeath = RESOURCE->LoadImg(L"CarrotDeath", L"Image\\Carrot_Death.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"CarrotNull", pCarrotBeamAttack, Vector(0, 0), Vector(5, 5), Vector(10, 0.f), 0.1f, 1, false);
	m_pAnimator->CreateAnimation(L"CarrotIntro1", m_pCarrot, Vector(0, 386), Vector(592, 549), Vector(597, 0.f), 0.1f, 8, false);
	m_pAnimator->CreateAnimation(L"CarrotIntro2", m_pCarrot, Vector(0, 940), Vector(592, 549), Vector(597, 0.f), 0.1f, 8, false);
	m_pAnimator->CreateAnimation(L"CarrotIntro3", m_pCarrot, Vector(0, 1494), Vector(592, 549), Vector(597, 0.f), 0.1f, 8, false);
	m_pAnimator->CreateAnimation(L"CarrotIntro4", m_pCarrot, Vector(0, 2048), Vector(592, 549), Vector(597, 0.f), 0.1f, 1, false);
	m_pAnimator->CreateAnimation(L"CarrotIdle1", m_pCarrot, Vector(0, 2665), Vector(466, 509), Vector(471, 0.f), 0.1f, 10,false);
	m_pAnimator->CreateAnimation(L"CarrotIdle2", m_pCarrot, Vector(0, 3179), Vector(466, 509), Vector(471, 0.f), 0.1f, 10, false);
	m_pAnimator->CreateAnimation(L"CarrotIdle3", m_pCarrot, Vector(0, 3693), Vector(466, 509), Vector(471, 0.f), 0.1f, 2, false);
	m_pAnimator->CreateAnimation(L"CarrotAttack", pCarrotBeamAttack, Vector(0, 0), Vector(500, 500), Vector(500, 0.f), 0.1f, 4);
	m_pAnimator->CreateAnimation(L"CarrotTransAttack", pCarrotTrans, Vector(0, 0), Vector(500, 550), Vector(500, 0.f), 0.1f, 9, false);
	m_pAnimator->CreateAnimation(L"CarrotTransIdle", pCarrotTrans, Vector(0, 550), Vector(500, 550), Vector(500, 0.f), 0.1f, 9, false);
	m_pAnimator->CreateAnimation(L"CarrotDeath1", pCarrotDeath, Vector(0, 0), Vector(500, 550), Vector(500, 0.f), 0.05f, 12,false);
	m_pAnimator->CreateAnimation(L"CarrotDeath2", pCarrotDeath, Vector(0, 550), Vector(500, 550), Vector(500, 0.f), 0.05f, 12, false);
	AddComponent(m_pAnimator);

	m_pAnimatorEarth = new CAnimator;
	m_pAnimatorEarth->CreateAnimation(L"EarthIntro", m_pCarrot, Vector(0, 66), Vector(336, 252), Vector(341, 0), 0.1f, 11, false);
	AddComponent(m_pAnimatorEarth);

	AddCollider(ColliderType::Rect, Vector(100, 300), Vector(0, 0));
}

void CMonsterCarrot::Update()
{
	fCoolTime += DT;
	//m_pAnimatorEarth->Play(L"EarthIntro");

	m_strState = L"Carrot";
	switch (m_curState)
	{
	case MonsterState::Null:
		m_strState += L"Null";
		if (fCoolTime >= 1.0f)
			ChangeState(MonsterState::Intro);
		break;
	case MonsterState::Intro:
		m_strState += L"Intro";
		if(fCoolTime<=0.8f)
			m_strState += L"1";
		else if(fCoolTime>0.8f&&fCoolTime<=1.6f)
			m_strState += L"2";
		else if (fCoolTime > 1.6f && fCoolTime <= 2.4f)
			m_strState += L"3";
		else
			m_strState += L"4";
		if (fCoolTime > 2.5f)
			ChangeState(MonsterState::Idle);
		break;
	case MonsterState::Idle:
		// �̻��� �߻�
		m_strState += L"Idle";
		if (fCoolTime <= 1.0f)
			m_strState += L"1";
		else if (fCoolTime > 1.0f && fCoolTime <= 2.0f)
			m_strState += L"2";
		else if (fCoolTime > 2.0f )
			m_strState += L"3";
		if (fCoolTime > 2.2f)
			ChangeState(MonsterState::Trans);
		break;
	case MonsterState::Trans:
		m_strState += L"Trans";
		if (m_PreState == MonsterState::Idle)
		{
			m_strState += L"Attack";
			if(fCoolTime>0.9f)
				ChangeState(MonsterState::Attack);
		}
		else if (m_PreState == MonsterState::Attack)
		{
			m_strState += L"Idle";
			if (fCoolTime > 0.9f)
				ChangeState(MonsterState::Idle);
		}
		break;
	case MonsterState::Attack:
		m_strState += L"Attack";
		// �� �߻� 4��
		if(fCoolTime>4.2f)
			ChangeState(MonsterState::Trans);
		break;
	case MonsterState::Death:
		m_strState += L"Death";
		if (fCoolTime <= 0.6f)
			m_strState += L"1";
		else if (fCoolTime > 0.6f )
			m_strState += L"2";
		if (fCoolTime > 1.2f)
			fCoolTime = 0;
		break;
	}
	AnimatorUpdate();
}

void CMonsterCarrot::Render()
{
}

void CMonsterCarrot::Release()
{
}

void CMonsterCarrot::AnimatorUpdate()
{
	m_pAnimator->Play(m_strState, false);
}

void CMonsterCarrot::CreateMissile()
{
}

void CMonsterCarrot::CreateBeam()
{
}