#include "framework.h"
#include "COnionMissileEffect.h"

COnionMissileEffect::COnionMissileEffect()
{
}

COnionMissileEffect::~COnionMissileEffect()
{
}

void COnionMissileEffect::Init()
{
	CImage* m_pImgMissileDeath = RESOURCE->LoadImg(L"OnionTearDeath", L"Image\\Onion_DropTear_Death.png");

	CAnimator* animator = new CAnimator;
	animator->CreateAnimation(L"OnionTearDropDeath", m_pImgMissileDeath, Vector(0, 0), Vector(300, 150), Vector(300, 0), 0.1f, 7, false);
	animator->Play(L"OnionTearDropDeath");
	AddComponent(animator);
}

void COnionMissileEffect::Update()
{
	timer -= DT;
	if (timer < 0)
		DELETEOBJECT(this);
}

void COnionMissileEffect::Render()
{
}

void COnionMissileEffect::Release()
{
}
