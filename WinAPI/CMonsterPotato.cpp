#include "framework.h"
#include "CMonsterPotato.h"

#include "CPotatoMissile.h"
#include "CPotatoParry.h"

CMonsterPotato::CMonsterPotato()
{
	m_pPotato= nullptr;
	m_pHitPotato = nullptr;
	fCoolTime = 0;
	missileCount = 0;
	m_pImage= nullptr;
	m_pAnimator = nullptr;
	m_pAnimatorEarth = nullptr;
}

CMonsterPotato::~CMonsterPotato()
{
}

void CMonsterPotato::Init()
{
	m_HP = 50;

	m_pPotato = RESOURCE->LoadImg(L"Potato", L"Image\\Botanic_Panic_Potato.png");
	m_pHitPotato = RESOURCE->LoadImg(L"HitPotato", L"Image\\Botanic_Panic_Potato_TakeHit.png");
	m_pImage = m_pPotato;


	CImage* pPotatoIntro = RESOURCE->LoadImg(L"PotatoIntro", L"Image\\Potato_Intro.png");
	CImage* pPotatoIdle = RESOURCE->LoadImg(L"PotatoIdle", L"Image\\Potato_Idle.png");
	CImage* pPotatoAttack = RESOURCE->LoadImg(L"PotatoAttack", L"Image\\Potato_Attack.png");
	CImage* pPotatoTransIdle = RESOURCE->LoadImg(L"PotatoTransIdle", L"Image\\Potato_TransIdle.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"PotatoNull", pPotatoIntro, Vector(0, 0), Vector(10, 10), Vector(10, 0.f), 0.1f, 1, false);
	m_pAnimator->CreateAnimation(L"PotatoIntro", pPotatoIntro, Vector(0, 0), Vector(600, 600), Vector(600, 0.f), 0.1f, 16, false);
	m_pAnimator->CreateAnimation(L"PotatoIdle", pPotatoIdle, Vector(0, 0), Vector(600, 600), Vector(600, 0.f), 0.1f, 16);
	m_pAnimator->CreateAnimation(L"PotatoAttack", pPotatoAttack, Vector(0, 0), Vector(600, 600), Vector(600, 0.f), 0.05f, 17);
	m_pAnimator->CreateAnimation(L"PotatoTransIdle", pPotatoTransIdle, Vector(0, 0), Vector(600, 600), Vector(600, 0.f), 0.1f, 3, false);

	AddComponent(m_pAnimator);


	m_pAnimatorEarth = new CAnimator;
	m_pAnimatorEarth->CreateAnimation(L"EarthIntro0", m_pPotato, Vector(2, 61), Vector(557, 461), Vector(558, 0), 0.1f, 5, false);
	m_pAnimatorEarth->CreateAnimation(L"EarthIntro1", m_pPotato, Vector(2, 523), Vector(557, 461), Vector(558, 0), 0.1f, 5, false);
	m_pAnimatorEarth->CreateAnimation(L"EarthIntro2", m_pPotato, Vector(2, 985), Vector(557, 461), Vector(558, 0), 0.1f, 5, false);
	m_pAnimatorEarth->CreateAnimation(L"EarthIntro3", m_pPotato, Vector(2, 1447), Vector(557, 461), Vector(558, 0), 0.1f, 3, false);
	AddComponent(m_pAnimatorEarth);
	AddCollider(ColliderType::Rect, Vector(200, 300), Vector(0, 0));
}

void CMonsterPotato::Update()
{
	fCoolTime += DT;

	wstring strEarth = L"EarthIntro";
	if (fCoolTime < 0.5f)
		strEarth += L"0";
	else if (fCoolTime >= 0.5f && fCoolTime < 1.0f)
		strEarth += L"1";
	else if (fCoolTime >= 1.0f && fCoolTime < 1.5f)
		strEarth += L"2";
	else if(fCoolTime >= 1.5f)
		strEarth += L"3";
	m_pAnimatorEarth->Play(strEarth);

	wstring str = L"Potato";

	if (fCoolTime >= 8.55f)
		fCoolTime = 2.5f;

	if(fCoolTime<0.9f)
		str += L"Null";
	else if (fCoolTime >= 0.9f && fCoolTime < 2.5f)
		str += L"Intro";
	else if (fCoolTime >= 2.5f && fCoolTime < 5.7f)
		str += L"Idle";
	else if (fCoolTime >= 5.7f && fCoolTime < 8.25f)
	{
		str += L"Attack";
		if (fCoolTime >= 6.45f && fCoolTime < 6.55f && missileCount == 0)
		{
			CreateMissile();
			missileCount++;
		}
		else if (fCoolTime >= 7.3f && fCoolTime < 7.4f && missileCount == 1)
		{
			CreateMissile();
			missileCount++;
		}
		else if (fCoolTime >= 8.15f && fCoolTime < 8.25f && missileCount == 2)
		{
			CreateParry();
			missileCount = 0;
		}
	}
	else if (fCoolTime >= 8.25f && fCoolTime < 8.55f)
		str += L"TransIdle";
	
	m_pAnimator->Play(str, false);
}

void CMonsterPotato::Render()
{
}

void CMonsterPotato::Release()
{
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
