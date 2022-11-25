#include "framework.h"
#include "COnionParry.h"

COnionParry::COnionParry()
{
	m_pImgParry = nullptr;
	m_pImgParryDeath = nullptr;
	m_pAnimator = nullptr;
	m_vecDir = Vector(0, 1);
	m_vecPos = Vector(0, 0);
	m_fVelocity = 800;

	bDeath = false;
	bCreate = false;
	fDeathCoolTime = 0;
}

COnionParry::~COnionParry()
{
}

void COnionParry::Init()
{
	CParryObject::Init();

	m_pImgParry = RESOURCE->LoadImg(L"OnionParryTear", L"Image\\Onion_DropTear_Pink.png");
	m_pImgParryDeath = RESOURCE->LoadImg(L"OnionParryTearDeath", L"Image\\Onion_DropTear_Death_Pink.png");
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"OnionParryTear", m_pImgParry, Vector(0, 0), Vector(300, 150), Vector(300, 0), 0.1f, 3);
	m_pAnimator->CreateAnimation(L"OnionParryTearDeath", m_pImgParryDeath, Vector(0, 0), Vector(300, 150), Vector(300, 0), 0.1f, 6, false);
	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(50, 80), Vector(0, 0));
}

void COnionParry::Update()
{
	srand(time(NULL));
	if (bDeath == true)
	{
		fDeathCoolTime += DT;
		RemoveCollider();
		Death();
	}
	else
	{
		if (bCreate == false)
		{
			m_vecPos.x = 120 * (rand() % 10 + 1);
			bCreate = true;
		}
		else
		{
			m_pAnimator->Play(L"OnionParryTear");
			m_vecPos += m_vecDir * m_fVelocity * DT;
			if (GetParry() == false)
				Death();
		}
	}
}

void COnionParry::Render()
{
}

void COnionParry::Release()
{
}

void COnionParry::Death()
{
	m_pAnimator->Play(L"OnionParryTearDeath");
	if (fDeathCoolTime > 0.7f)
		DELETEOBJECT(this);
}

void COnionParry::OnCollisionEnter(CCollider* pOther)
{
	if (pOther->GetObjName() == L"Ground")
	{
		bDeath = true;
	}
}
