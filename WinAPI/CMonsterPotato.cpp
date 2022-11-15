#include "framework.h"
#include "CMonsterPotato.h"

CMonsterPotato::CMonsterPotato()
{
	
	m_pPotato= nullptr;
	m_pHitPotato = nullptr;
	fCoolTime = 0;
	m_pImage= nullptr;
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

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"PotatoIntro1", m_pPotato, Vector(7, 1975), Vector(526,512), Vector(531, 0.f), 0.1f, 6);
	m_pAnimator->CreateAnimation(L"PotatoIntro2", m_pPotato, Vector(7, 2492), Vector(526,512), Vector(531, 0.f), 0.1f, 2);
	m_pAnimator->CreateAnimation(L"PotatoIdle1", m_pPotato, Vector(1069, 2492), Vector(526,512), Vector(531, 0.f), 0.1f, 4);
	m_pAnimator->CreateAnimation(L"PotatoIdle2", m_pPotato, Vector(7, 3009), Vector(526,512), Vector(531, 0.f), 0.1f, 3);

	m_pAnimator->CreateAnimation(L"PotatoAttack1", m_pPotato, Vector(7, 4106), Vector(526, 512), Vector(531, 0.f), 0.1f, 6);
	m_pAnimator->CreateAnimation(L"PotatoAttack2", m_pPotato, Vector(7, 4623), Vector(526, 512), Vector(531, 0.f), 0.1f, 6);
	m_pAnimator->CreateAnimation(L"PotatoAttack3", m_pPotato, Vector(7, 5140), Vector(526, 512), Vector(531, 0.f), 0.1f, 5);
	AddComponent(m_pAnimator);
	AddCollider(ColliderType::Rect, Vector(200, 300), Vector(0, 0));
	GetCollider()->SetChangePos(Vector(WINSIZEX * 0.8, WINSIZEY * 0.5 + 100));

}

void CMonsterPotato::Update()
{
	fCoolTime += DT;
	wstring str = L"Potato";

	if (fCoolTime >= 3.2f)
		fCoolTime = 1.5f;

	if (fCoolTime < 0.6f)
		str += L"Intro1";
	else if (fCoolTime >= 0.6f && fCoolTime < 0.8f)
		str += L"Intro2";

	else if (fCoolTime >= 0.8f && fCoolTime < 1.2f)
		str += L"Idle1";
	else if (fCoolTime >= 1.2f && fCoolTime < 1.5f)
		str += L"Idle2";

	else if (fCoolTime >= 1.5f && fCoolTime < 2.1f)
		str += L"Attack1";
	else if (fCoolTime >= 2.1f && fCoolTime < 2.7f)
		str += L"Attack2";
	else if (fCoolTime >= 2.7f && fCoolTime < 3.2f)
		str += L"Attack3";
	
	Logger::Debug(str);
	m_pAnimator->Play(str, false);
}

void CMonsterPotato::Render()
{
}

void CMonsterPotato::Release()
{
}
