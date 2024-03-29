#include "framework.h"
#include "CMonserPyrimid.h"

CMonserPyrimid::CMonserPyrimid()
{
	m_pPyramid = nullptr;
	m_pHitPyramid = nullptr;
	m_pImage = nullptr;
	fImageCoolTime = 0;
}

CMonserPyrimid::~CMonserPyrimid()
{
}

bool CMonserPyrimid::CollisionRange(Vector pos)
{
	// Collider Scale = (220, 110);
	float minX = m_vecPos.x - 0.5f * 220;
	if (pos.x < minX)
		return false;
	else
		return true;
}

void CMonserPyrimid::Init()
{
	m_HP = 5;
	m_pPyramid = RESOURCE->LoadImg(L"BlockPyramid", L"Image\\tutorial_pyramid_topper.png");
	m_pHitPyramid = RESOURCE->LoadImg(L"BlockPyramidHit", L"Image\\tutorial_pyramid_topper_takeHit.png");
	m_pImage = m_pPyramid;
	SetPos(2995, 300);
	AddCollider(ColliderType::Rect, Vector(220, 142), Vector(0, 0));
}

void CMonserPyrimid::Update()
{
	if (bTakeHit)
	{
		fImageCoolTime += DT;
		m_pImage = m_pHitPyramid;
	}
	if (fImageCoolTime > 0.5f)
	{
		bTakeHit = false;
		fImageCoolTime = 0;
		m_pImage = m_pPyramid;
	}
	if (m_HP <= 0)
		DELETEOBJECT(this);
}

void CMonserPyrimid::Render()
{
	RENDER->Image(m_pImage,
		m_vecPos.x - m_pImage->GetWidth() * 0.5f,
		m_vecPos.y - m_pImage->GetHeight() * 0.5f,
		m_vecPos.x + m_pImage->GetWidth() * 0.5f,
		m_vecPos.y + m_pImage->GetHeight() * 0.5f);
}

void CMonserPyrimid::Release()
{
}

