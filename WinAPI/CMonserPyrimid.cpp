#include "framework.h"
#include "CMonserPyrimid.h"

CMonserPyrimid::CMonserPyrimid()
{
	m_pPyramid = nullptr;
	m_pHitPyramid = nullptr;
}

CMonserPyrimid::~CMonserPyrimid()
{
}

void CMonserPyrimid::Init()
{
	m_HP = 5;
	m_pPyramid = RESOURCE->LoadImg(L"BlockPyramid", L"Image\\tutorial_pyramid_topper.png");
	m_pHitPyramid = RESOURCE->LoadImg(L"BlockPyramidHit", L"Image\\tutorial_pyramid_topper_takeHit.png");
	SetPos(2999, 280);
	AddCollider(ColliderType::Circle, Vector(100, 100), Vector(0, 0));
}

void CMonserPyrimid::Update()
{
	if (bTakeHit)
	{
		fImageCoolTime = 0;
		fImageCoolTime += DT;
	}
		
	if (fImageCoolTime > 0.2f)
		bTakeHit = false;
}

void CMonserPyrimid::Render()
{
	if (fImageCoolTime>0&& fImageCoolTime < 0.2f)
	{
		RENDER->Image(m_pHitPyramid,
			m_vecPos.x - m_pPyramid->GetWidth() * 0.5f,
			m_vecPos.y - m_pPyramid->GetHeight() * 0.5f,
			m_vecPos.x + m_pPyramid->GetWidth() * 0.5f,
			m_vecPos.y + m_pPyramid->GetHeight() * 0.5f);
	}
	else
	{
		RENDER->Image(m_pPyramid,
			m_vecPos.x - m_pPyramid->GetWidth() * 0.5f,
			m_vecPos.y - m_pPyramid->GetHeight() * 0.5f,
			m_vecPos.x + m_pPyramid->GetWidth() * 0.5f,
			m_vecPos.y + m_pPyramid->GetHeight() * 0.5f);
	}
}

void CMonserPyrimid::Release()
{
}

