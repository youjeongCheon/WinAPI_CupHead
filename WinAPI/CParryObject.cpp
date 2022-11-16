#include "framework.h"
#include "CParryObject.h"

#include "CPlayer.h"

CParryObject::CParryObject()
{
	m_pParrySpikle = nullptr;
	bParry = true;
	bParryExit = false;

	m_vecDir = Vector(0, 0);
	m_fVelocity = 1000;
	m_layer = Layer::Obstacle;
}

CParryObject::~CParryObject()
{
}

void CParryObject::CreateSpikle()
{
	if (bParry == true)
		m_pAnimator->Play(L"ParrySpikle", false);
	else
		m_pAnimator->Play(L"NoneParrySpikle", false);
}

void CParryObject::SetDir(Vector dir)
{
	m_vecDir = dir.Normalized();
}

void CParryObject::SetVelocity(float velocity)
{
	m_fVelocity = velocity;
}

void CParryObject::Init()
{
	m_pParrySpikle = RESOURCE->LoadImg(L"ParrySpikle", L"Image\\cuphead_parry_spikle.png");
	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"ParrySpikle", m_pParrySpikle, Vector(0.f, 0.f), Vector(300, 300), Vector(300, 0.f), 0.05f, 9, false);
	m_pAnimator->CreateAnimation(L"NoneParrySpikle", m_pParrySpikle, Vector(0.f, 0.f), Vector(0, 0), Vector(0, 0.f), 0.05f, 1, false);
	AddComponent(m_pAnimator);
}

void CParryObject::OnCollisionStay(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"플레이어")
	{
		CPlayer* pPlayer = static_cast<CPlayer*>(pOtherCollider->GetOwner());

		if (BUTTONDOWN('Z'))
		{
			if (bParry == true)
			{
				bParryExit = true;
				CreateSpikle();
				int count = pPlayer->GetSpecialAttackCount();
				count++;
				pPlayer->SetSpecialAttackCount(count);
				pPlayer->ChangeState(PlayerState::Parry);
			}
		}
	}
}

void CParryObject::OnCollisionExit(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"플레이어")
	{
		if (bParryExit == true)
		{
			bParry = false;
			bParryExit = false;
			CreateSpikle();
		}
	}
}
