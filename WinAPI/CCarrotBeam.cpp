#include "framework.h"
#include "CCarrotBeam.h"

CCarrotBeam::CCarrotBeam()
{
	m_vecDir = Vector(0, 1);
	m_vecPos = Vector(WINSIZEX*0.5f, WINSIZEY*0.3f);
	m_fVelocity = 400;

}

CCarrotBeam::~CCarrotBeam()
{
}

void CCarrotBeam::Init()
{
	CImage* pImgBeam = RESOURCE->LoadImg(L"CarrotBeam", L"Image\\Carrot_MissileBeam_Loop.png");
	CAnimator* m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"CarrotBeam", pImgBeam, Vector(0, 0), Vector(200, 200), Vector(200, 0), 0.1f, 9);
	m_pAnimator->Play(L"CarrotBeam");
	AddComponent(m_pAnimator);
	AddCollider(ColliderType::Circle, Vector(50, 50), Vector(0, 0));
}

void CCarrotBeam::Update()
{
	m_vecPos += m_vecDir * m_fVelocity * DT;
}

void CCarrotBeam::Render()
{
}

void CCarrotBeam::Release()
{
}

void CCarrotBeam::OnCollisionEnter(CCollider* pOther)
{

	if (pOther->GetObjName() == L"Ground")
	{
		DELETEOBJECT(this);
	}
}
