#include "framework.h"
#include "CParryObject.h"

#include "CPlayer.h"

#include "CSceneTutorial.h"

CParryObject::CParryObject()
{
	m_pImage = nullptr;
	m_pSphere = nullptr;
	m_pPinkSphere = nullptr;
	m_pParrySpikle = nullptr;
	m_pAnimator = nullptr;

	m_layer = Layer::Obstacle;

	m_num = 0;
	parryNum = 0;
	pSceneTutorial = nullptr;
	bParry = true;
	bParryExit = false;
}

CParryObject::~CParryObject()
{
}

void CParryObject::CreateSpikle()
{
	if(bParry==true)
		m_pAnimator->Play(L"ParrySpikle", false);
	else 
		m_pAnimator->Play(L"NoneParrySpikle", false);
	
}

void CParryObject::SetNum(int num)
{
	m_num = num;
}

void CParryObject::SetParryNum()
{
	parryNum = pSceneTutorial->GetParryNum();
}

void CParryObject::SelectNum()
{
	if (parryNum == 3)
		parryNum = 0;
	if (m_num == parryNum)
		bParry = true;
	else
		bParry = false;
}

void CParryObject::SetScene(CSceneTutorial* scene)
{
	this->pSceneTutorial=scene;
}

void CParryObject::Init()
{
	m_pSphere = RESOURCE->LoadImg(L"Sphere", L"Image\\tutorial_sphere_1.png"); 
	m_pPinkSphere = RESOURCE->LoadImg(L"PinkSphere", L"Image\\tutorial_pink_sphere_1.png");
	m_pParrySpikle = RESOURCE->LoadImg(L"ParrySpikle", L"Image\\cuphead_parry_spikle.png");

	m_pImage = m_pSphere;

	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"ParrySpikle", m_pParrySpikle, Vector(0.f, 0.f), Vector(300, 300), Vector(300, 0.f), 0.05f, 9, false);
	m_pAnimator->CreateAnimation(L"NoneParrySpikle", m_pParrySpikle, Vector(0.f, 0.f), Vector(0, 0), Vector(0, 0.f), 0.05f, 1, false);
	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Circle, Vector(18, 18), Vector(0, 0));
}

void CParryObject::Update()
{
	SetParryNum();
	SelectNum();

	if (bParry == true)
		m_pImage = m_pPinkSphere;
	else
		m_pImage = m_pSphere;
}

void CParryObject::Render()
{
	RENDER->Image(m_pImage,
		m_vecPos.x - m_pImage->GetWidth() * 0.5f,
		m_vecPos.y - m_pImage->GetHeight() * 0.5f,
		m_vecPos.x + m_pImage->GetWidth() * 0.5f,
		m_vecPos.y + m_pImage->GetHeight() * 0.5f);
}

void CParryObject::Release()
{
}

void CParryObject::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"플레이어")
	{
	}
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
			parryNum++;
			pSceneTutorial->SetParryNum(parryNum);
		}	
	}
}
