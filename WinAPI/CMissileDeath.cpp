#include "framework.h"
#include "CMissileDeath.h"

CMissileDeath::CMissileDeath()
{
	m_pImgMissileDeath = nullptr;
	m_pAnimator = nullptr;
	m_layer = Layer::Missile;
}

CMissileDeath::~CMissileDeath()
{
}

void CMissileDeath::Init()
{
	m_pImgMissileDeath = RESOURCE->LoadImg(L"MissileDeath", L"Image\\missile_death.png");
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Dearh", m_pImgMissileDeath, Vector(0.f, 0.f), Vector(300, 300), Vector(300, 0.f), 0.05f, 6, false);
	AddComponent(m_pAnimator);
	m_pAnimator->Play(L"Dearh");
}

void CMissileDeath::Update()
{
	fCoolTime += DT;
	if (fCoolTime > 0.3f)
		DELETEOBJECT(this);
}

void CMissileDeath::Render()
{
}

void CMissileDeath::Release()
{
}
