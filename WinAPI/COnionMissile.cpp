#include "framework.h"
#include "COnionMissile.h"

#include "COnionMissileEffect.h"

COnionMissile::COnionMissile()
{
	m_pImgMissile = nullptr;
	m_pImgMissileDeath = nullptr;
	m_pAnimator = nullptr;
	m_vecDir = Vector(0, 1);
	m_vecPos = Vector(0,0);
	m_fVelocity = 800;

	bCreate = false;
	bDeath = false;
	fDeathCoolTime = 0;
}

COnionMissile::~COnionMissile()
{
}

void COnionMissile::Init()
{
	m_pImgMissile = RESOURCE->LoadImg(L"OnionTear", L"Image\\Onion_DropTear.png");
	//m_pImgMissileDeath = RESOURCE->LoadImg(L"OnionTearDeath", L"Image\\Onion_DropTear_Death.png");
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"OnionTearDrop", m_pImgMissile, Vector(0, 0), Vector(300, 150), Vector(300, 0), 0.1f, 3);
	//m_pAnimator->CreateAnimation(L"OnionTearDropDeath", m_pImgMissileDeath, Vector(0, 0), Vector(300, 150), Vector(300, 0), 0.1f, 7,false);
	AddComponent(m_pAnimator);
	m_pAnimator->Play(L"OnionTearDrop");

	AddCollider(ColliderType::Rect, Vector(50, 80), Vector(0, 0));
}

void COnionMissile::Update()
{
	
	m_vecPos += m_vecDir * m_fVelocity * DT;
}

void COnionMissile::Render()
{
}

void COnionMissile::Release()
{
}

void COnionMissile::Death()
{
	m_pAnimator->Play(L"OnionTearDropDeath");
	
}

void COnionMissile::OnCollisionEnter(CCollider* pOther)
{
	if (pOther->GetObjName() == L"Ground")
	{
		DELETEOBJECT(this);
		COnionMissileEffect* effect = new COnionMissileEffect();
		effect->SetPos(m_vecPos);
		ADDOBJECT(effect);
	}
}
