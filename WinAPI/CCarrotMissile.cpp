#include "framework.h"
#include "CCarrotMissile.h"

#include "CGameManager.h"

CCarrotMissile::CCarrotMissile()
{
	m_vecDir = Vector(0, 1);
	m_vecPos = Vector(0, 0);
	m_fVelocity = 100;
}

CCarrotMissile::~CCarrotMissile()
{
}

void CCarrotMissile::Init()
{
	pImgMissile = RESOURCE->LoadImg(L"CarrotMissile", L"Image\\CarrotMissile.png");
	AddCollider(ColliderType::Rect, Vector(50, 70), Vector(0, 0));
}

void CCarrotMissile::Update()
{
	m_vecDir = PLAYERPOS - m_vecPos;
	SetDir(m_vecDir);
	m_vecPos += m_vecDir * m_fVelocity * DT;
}

void CCarrotMissile::Render()
{
	RENDER->Image(pImgMissile,
		m_vecPos.x - 0.5f * pImgMissile->GetWidth(),
		m_vecPos.y - 0.5f * pImgMissile->GetHeight(),
		m_vecPos.x + 0.5f * pImgMissile->GetWidth(),
		m_vecPos.y + 0.5f * pImgMissile->GetHeight());
}

void CCarrotMissile::Release()
{
}

void CCarrotMissile::OnCollisionEnter(CCollider* pOther)
{
	if (pOther->GetObjName() == L"Ground")
	{
		DELETEOBJECT(this);
	}
	if (pOther->GetObjName() == L"미사일")
	{
		DELETEOBJECT(this);
		DELETEOBJECT(pOther->GetOwner());
	}
	if (pOther->GetObjName() == L"플레이어")
	{
		DELETEOBJECT(this);
	}


}
