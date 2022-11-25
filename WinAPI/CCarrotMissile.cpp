#include "framework.h"
#include "CCarrotMissile.h"

#include "CGameManager.h"
#include "CMissile.h"

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
	wstring str = to_wstring((int)(m_fAngle->GetAngle(m_vecPos, PLAYERPOS)));
	Logger::Debug(str);
}

void CCarrotMissile::Render()
{
	RENDER->Image(pImgMissile,
		m_vecPos.x - 0.5f * pImgMissile->GetWidth(),
		m_vecPos.y - 0.5f * pImgMissile->GetHeight(),
		m_vecPos.x + 0.5f * pImgMissile->GetWidth(),
		m_vecPos.y + 0.5f * pImgMissile->GetHeight(),
		m_fAngle->GetAngle(m_vecPos, PLAYERPOS)
		);
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
		CMissile* pMissile = static_cast<CMissile*>(pOther->GetOwner());
		pMissile->DeathMissile();
	}
	if (pOther->GetObjName() == L"플레이어")
	{
		DELETEOBJECT(this);
	}


}
