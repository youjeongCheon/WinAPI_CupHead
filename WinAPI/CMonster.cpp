#include "framework.h"
#include "CMonster.h"

#include "CRenderManager.h"
#include "CCollider.h"

CMonster::CMonster()
{
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Monster;
	m_HP = 5;
	bTakeHit = false;
	fImageCoolTime = 0;
}

CMonster::~CMonster()
{
}

bool CMonster::CollisionRange(Vector pos)
{
	return true;
}

void CMonster::SetHP(int hp)
{
	m_HP = hp;
}

int CMonster::GetHP()
{
	return m_HP;
}

bool CMonster::GetTakeHit()
{
	return bTakeHit;
}

void CMonster::Init()
{
	AddCollider(ColliderType::Rect, m_vecScale, Vector(0, 0));
}

void CMonster::Update()
{
	
}

void CMonster::Render()
{
	
}

void CMonster::Release()
{
}

void CMonster::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"플레이어")
	{
		Logger::Debug(L"몬스터가 플레이어와 충돌진입");
	}
	else if (pOtherCollider->GetObjName() == L"미사일")
	{
		if (CollisionRange(pOtherCollider->GetPos()))
		{
			Logger::Debug(L"몬스터가 미사일과 충돌진입");
			m_HP -= 1;
			bTakeHit = true;
			DELETEOBJECT(pOtherCollider->GetOwner());
		}
		else
			Logger::Debug(L"충돌범위 밖");
	}
	
}

void CMonster::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CMonster::OnCollisionExit(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"플레이어")
	{
		Logger::Debug(L"몬스터가 플레이어와 충돌해제");
	}
	else if (pOtherCollider->GetObjName() == L"미사일")
	{
		if (CollisionRange(pOtherCollider->GetPos()))
		{
			Logger::Debug(L"몬스터가 미사일과 충돌해제");
		}
	}
	if (m_HP == 0)
	{
		Logger::Debug(L"Monster Die");
		DELETEOBJECT(this);
	}
}
