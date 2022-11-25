#include "framework.h"
#include "CTitleObject.h"

CTitleObject::CTitleObject()
{
	m_pImage = nullptr;
	fCoolTime = 0;
}

CTitleObject::~CTitleObject()
{
}

void CTitleObject::Init()
{
	m_pImage = RESOURCE->LoadImg(L"cuphead_title_screen", L"Image\\cuphead_title_screen.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"cupheads_title_movement1", m_pImage, Vector(0, 0.f), Vector(1093, 700), Vector(1093, 0.f), 0.08f, 5);
	m_pAnimator->CreateAnimation(L"cupheads_title_movement2", m_pImage, Vector(0, 700), Vector(1093, 700), Vector(1093, 0.f), 0.08f, 5);
	m_pAnimator->CreateAnimation(L"cupheads_title_movement3", m_pImage, Vector(0, 1400), Vector(1093, 700), Vector(1093, 0.f), 0.08f, 5);
	m_pAnimator->CreateAnimation(L"cupheads_title_movement4", m_pImage, Vector(0, 2100), Vector(1093, 700), Vector(1093, 0.f), 0.08f, 5);
	m_pAnimator->CreateAnimation(L"cupheads_title_movement5", m_pImage, Vector(0, 2800), Vector(1093, 700), Vector(1093, 0.f), 0.08f, 5);
	m_pAnimator->CreateAnimation(L"cupheads_title_movement6", m_pImage, Vector(0, 3500), Vector(1093, 700), Vector(1093, 0.f), 0.08f, 5);
	m_pAnimator->CreateAnimation(L"cupheads_title_movement7", m_pImage, Vector(0, 4200), Vector(1093, 700), Vector(1093, 0.f), 0.08f, 4);

	AddComponent(m_pAnimator);
}

void CTitleObject::Update()
{
	fCoolTime += DT;
	wstring str = L"cupheads_title_movement";
	if (fCoolTime >= 2.72f)
		fCoolTime = 0;
	if (fCoolTime < 0.4f)
		str += L"1";
	else if(fCoolTime >= 0.4f && fCoolTime < 0.8f)
		str += L"2";
	else if (fCoolTime >= 0.8f && fCoolTime < 1.2f)
		str += L"3";
	else if (fCoolTime >= 1.2f && fCoolTime < 1.6f)
		str += L"4";
	else if (fCoolTime >= 1.6f && fCoolTime < 2.0f)
		str += L"5";
	else if (fCoolTime >= 2.0f && fCoolTime < 2.4f)
		str += L"6";
	else if (fCoolTime >= 2.4f && fCoolTime < 2.72f)
		str += L"7";
	
	m_pAnimator->Play(str, false);
}

void CTitleObject::Render()
{
}

void CTitleObject::Release()
{
}
