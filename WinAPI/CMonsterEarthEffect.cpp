#include "framework.h"
#include "CMonsterEarthEffect.h"

CMonsterEarthEffect::CMonsterEarthEffect()
{
	fEarthCoolTime = 0;
	m_pAnimatorEarth = nullptr;
	m_layer = Layer::FrontObject;
}

CMonsterEarthEffect::~CMonsterEarthEffect()
{
}

void CMonsterEarthEffect::Init()
{
	CImage* pEarth = RESOURCE->LoadImg(L"Earth", L"Image\\Botanic_Panic_Potato.png");
	m_pAnimatorEarth = new CAnimator;
	m_pAnimatorEarth->CreateAnimation(L"EarthIntro0", pEarth, Vector(2, 61), Vector(557, 460), Vector(558, 0), 0.1f, 5, false);
	m_pAnimatorEarth->CreateAnimation(L"EarthIntro1", pEarth, Vector(2, 523), Vector(557, 460), Vector(558, 0), 0.1f, 5, false);
	m_pAnimatorEarth->CreateAnimation(L"EarthIntro2", pEarth, Vector(2, 985), Vector(557, 460), Vector(558, 0), 0.1f, 5, false);
	m_pAnimatorEarth->CreateAnimation(L"EarthIntro3", pEarth, Vector(2, 1447), Vector(557, 460), Vector(558, 0), 0.1f, 3, false);
	AddComponent(m_pAnimatorEarth);
}

void CMonsterEarthEffect::Update()
{
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
}

void CMonsterEarthEffect::Render()
{
}

void CMonsterEarthEffect::Release()
{
}
