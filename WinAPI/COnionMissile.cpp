#include "framework.h"
#include "COnionMissile.h"

#include "COnionMissileEffect.h"

COnionMissile::COnionMissile()
{
	m_vecDir = Vector(0, 1);
	m_vecPos = Vector(0,0);
	m_fVelocity = 800;
}

COnionMissile::~COnionMissile()
{
}

void COnionMissile::Init()
{
	CImage* missile = RESOURCE->LoadImg(L"OnionTear", L"Image\\Onion_DropTear.png");

	CAnimator* m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"OnionTearDrop", missile, Vector(0, 0), Vector(300, 150), Vector(300, 0), 0.1f, 3);
	m_pAnimator->Play(L"OnionTearDrop");
	AddComponent(m_pAnimator);

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
