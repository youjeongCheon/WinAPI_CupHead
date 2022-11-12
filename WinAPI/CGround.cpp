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
	AddCollider(ColliderType::Rect, Vector(10000, 1), Vector(0, 0));
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
	CPlayer* pPlayer = static_cast<CPlayer*>(pOther->GetOwner());
	pPlayer->SetGround(true);
}

void CGround::OnCollisionStay(CCollider* pOther)
{
	if (pOther->GetObjName() == L"�÷��̾�")
	{
		// �÷��̾ �浹 ���� ��� �о�� ����
		// ���� �о��
		CPlayer* pPlayer = static_cast<CPlayer*>(pOther->GetOwner());
		pPlayer->SetPos(
			pPlayer->GetPos().x,
			GetCollider()->GetPos().y
			- (GetCollider()->GetScale().y + pOther->GetScale().y) * 0.5f + offset
			- pOther->GetOffsetPos().y);
		
	}
}

void CGround::OnCollisionExit(CCollider* pOther)
{
	CPlayer* pPlayer = static_cast<CPlayer*>(pOther->GetOwner());
	pPlayer->SetGround(false);
	Logger::Debug(L"������ ���");
}

