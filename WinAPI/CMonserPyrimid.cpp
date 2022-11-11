#include "framework.h"
#include "CMonserPyrimid.h"

CMonserPyrimid::CMonserPyrimid()
{
	m_pPyramid = nullptr;
}

CMonserPyrimid::~CMonserPyrimid()
{
}

void CMonserPyrimid::Init()
{
	m_HP = 5;
	m_pPyramid = RESOURCE->LoadImg(L"BlockPyramid", L"Image\\tutorial_pyramid_topper.png");
	SetPos(2999, 280);
	AddCollider(ColliderType::Rect, Vector(218, 141), Vector(0, 0));
}

void CMonserPyrimid::Update()
{
}

void CMonserPyrimid::Render()
{
	RENDER->Image(m_pPyramid,
		m_vecPos.x - m_pPyramid->GetWidth() * 0.5f,
		m_vecPos.y - m_pPyramid->GetHeight() * 0.5f,
		m_vecPos.x + m_pPyramid->GetWidth() * 0.5f,
		m_vecPos.y + m_pPyramid->GetHeight() * 0.5f);
}

void CMonserPyrimid::Release()
{
}

