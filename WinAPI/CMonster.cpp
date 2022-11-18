#include "framework.h"
#include "CMonster.h"

#include "CMissile.h"

CMonster::CMonster()
{
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Monster;
	m_HP = 5;
	bTakeHit = false;
	fImageCoolTime = 0;
	m_curState = MonsterState::Null;
	m_PreState = MonsterState::Null;
}

CMonster::~CMonster()
{
}

bool CMonster::CollisionRange(Vector pos)
{
	return true;
}

void CMonster::ChangeState(MonsterState state)
{
	m_PreState = m_curState;
	m_curState = state;
	fCoolTime = 0;
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
	if (pOtherCollider->GetObjName() == L"�÷��̾�")
	{
		Logger::Debug(L"���Ͱ� �÷��̾�� �浹����");
	}
	else if (pOtherCollider->GetObjName() == L"�̻���")
	{
		if (CollisionRange(pOtherCollider->GetPos()))
		{
			CMissile* pMissile = static_cast<CMissile*>(pOtherCollider->GetOwner());
			Logger::Debug(L"���Ͱ� �̻��ϰ� �浹����");
			if (pMissile->GetExMissile())
				m_HP -= 5;
			else
				m_HP -= 1;
			bTakeHit = true;
			DELETEOBJECT(pOtherCollider->GetOwner());
		}
		else
			Logger::Debug(L"�浹���� ��");
	}
	
}

void CMonster::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CMonster::OnCollisionExit(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"�÷��̾�")
	{
		Logger::Debug(L"���Ͱ� �÷��̾�� �浹����");
	}
	else if (pOtherCollider->GetObjName() == L"�̻���")
	{
		if (CollisionRange(pOtherCollider->GetPos()))
		{
			Logger::Debug(L"���Ͱ� �̻��ϰ� �浹����");
		}
	}
	if (m_HP == 0)
	{
		Logger::Debug(L"Monster Die");
		m_curState = MonsterState::Death;
	}
}
