#include "framework.h"
#include "CGround.h"

#include "CPlayer.h"

CGround::CGround()
{
	m_layer = Layer::Ground;
	offset = 5.f;
	m_strName = L"Ground";
}

CGround::~CGround()
{
}

void CGround::Init()
{
	AddCollider(ColliderType::Rect, Vector(7000, 1), Vector(0, 0));
}

void CGround::Update()
{
}

void CGround::Render()
{
}

void CGround::Release()
{
}

void CGround::OnCollisionEnter(CCollider* pOther)
{
}

void CGround::OnCollisionStay(CCollider* pOther)
{
	if (pOther->GetObjName() == L"플레이어")
	{
		// 플레이어가 충돌 중일 경우 밀어내기 연산
		// 위로 밀어내기
		CPlayer* pPlayer = static_cast<CPlayer*>(pOther->GetOwner());

		if (pPlayer->GetCurState() != PlayerState::Jump)
		{
			pPlayer->SetPos(
				pPlayer->GetPos().x,
				GetCollider()->GetPos().y
				- (GetCollider()->GetScale().y + pOther->GetScale().y) * 0.5f + offset
				- pOther->GetOffsetPos().y);
			pPlayer->SetGround(true);
		}
		else
			pPlayer->SetGround(false);
		
		
	}
}

void CGround::OnCollisionExit(CCollider* pOther)
{
	CPlayer* pPlayer = static_cast<CPlayer*>(pOther->GetOwner());

	pPlayer->SetGround(false);
}

