#include "framework.h"
#include "CObstacle.h"

#include "CPlayer.h"

CObstacle::CObstacle()
{
	m_layer = Layer::Obstacle;
	dir = CollisionDir::None;
	offset = 0.25f;
}

CObstacle::~CObstacle()
{
}

void CObstacle::Init()
{
	AddCollider(ColliderType::Rect, m_vecScale, Vector(0, 0));
}

void CObstacle::Update()
{
}

void CObstacle::Render()
{
	switch (dir)
	{
	case CollisionDir::Up:
	{
		RENDER->Text(
			L"Up",
			m_vecPos.x - m_vecScale.x * 0.5f,
			m_vecPos.y - m_vecScale.y * 0.5f,
			m_vecPos.x + m_vecScale.x * 0.5f,
			m_vecPos.y + m_vecScale.y * 0.5f
		);
	}
	break;

	case CollisionDir::Down:
	{
		RENDER->Text(
			L"Down",
			m_vecPos.x - m_vecScale.x * 0.5f,
			m_vecPos.y - m_vecScale.y * 0.5f,
			m_vecPos.x + m_vecScale.x * 0.5f,
			m_vecPos.y + m_vecScale.y * 0.5f
		);
	}
	break;

	case CollisionDir::Left:
	{
		RENDER->Text(
			L"Left",
			m_vecPos.x - m_vecScale.x * 0.5f,
			m_vecPos.y - m_vecScale.y * 0.5f,
			m_vecPos.x + m_vecScale.x * 0.5f,
			m_vecPos.y + m_vecScale.y * 0.5f
		);
	}
	break;

	case CollisionDir::Right:
	{
		RENDER->Text(
			L"Right",
			m_vecPos.x - m_vecScale.x * 0.5f,
			m_vecPos.y - m_vecScale.y * 0.5f,
			m_vecPos.x + m_vecScale.x * 0.5f,
			m_vecPos.y + m_vecScale.y * 0.5f
		);
	}
	break;

	case CollisionDir::None:
	{
		RENDER->Text(
			L"None",
			m_vecPos.x - m_vecScale.x * 0.5f,
			m_vecPos.y - m_vecScale.y * 0.5f,
			m_vecPos.x + m_vecScale.x * 0.5f,
			m_vecPos.y + m_vecScale.y * 0.5f
		);
	}
	break;
	}
}

void CObstacle::Release()
{
}

void CObstacle::OnCollisionEnter(CCollider* pOther)
{
}

void CObstacle::OnCollisionStay(CCollider* pOther)
{
	if (pOther->GetObjName() == L"�÷��̾�")
	{
		
		// �÷��̾ �浹 ���� ��� �о�� ����
		CPlayer* pPlayer = static_cast<CPlayer*>(pOther->GetOwner());

		dir = GetCollisionDir(pOther);

		switch (GetCollisionDir(pOther))
		{
		case CollisionDir::Up:
		{
			if (!(pPlayer->GetPassBlock() && (m_vecScale.y * 0.5f + m_vecPos.y)<GROUNDPOSY))
			{
				pPlayer->SetPos(
					pPlayer->GetPos().x,
					GetCollider()->GetPos().y
					- (GetCollider()->GetScale().y + pOther->GetScale().y) * 0.5f + offset
					- pOther->GetOffsetPos().y
				);
				pPlayer->SetPassBlock(false);
				pPlayer->SetOnBlock(true);
			}
			
		}
		break;

		case CollisionDir::Down:
		{
			/*pPlayer->SetPos(
				pPlayer->GetPos().x,
				GetCollider()->GetPos().y
				+ (GetCollider()->GetScale().y + pOther->GetScale().y) * 0.5f - offset
				- pOther->GetOffsetPos().y
			);*/
			pPlayer->ChangeState(PlayerState::Idle);
		}
		break;

		case CollisionDir::Left:
		{
			pPlayer->SetPos(
				GetCollider()->GetPos().x
				- (GetCollider()->GetScale().x + pOther->GetScale().x) * 0.5f + offset
				- pOther->GetOffsetPos().x,
				pPlayer->GetPos().y
			);
		}
		break;

		case CollisionDir::Right:
		{
			pPlayer->SetPos(
				GetCollider()->GetPos().x
				+ (GetCollider()->GetScale().x + pOther->GetScale().x) * 0.5f - offset
				- pOther->GetOffsetPos().x,
				pPlayer->GetPos().y
			);
		}
		break;
		}
	}
}

void CObstacle::OnCollisionExit(CCollider* pOther)
{
	CPlayer* pPlayer = static_cast<CPlayer*>(pOther->GetOwner());
	pPlayer->SetGround(false);
	pPlayer->SetOnBlock(false);
	pPlayer->SetPassBlock(false);
}



struct ColliderInfo
{
	Vector pos;
	Vector scale;

	float left;
	float right;
	float up;
	float down;

	ColliderInfo(Vector pos, Vector scale)
	{
		this->pos = pos;
		this->scale = scale;

		left = pos.x - scale.x * 0.5f;
		right = pos.x + scale.x * 0.5f;
		up = pos.y - scale.y * 0.5f;
		down = pos.y + scale.y * 0.5f;
	}
};

typename CObstacle::CollisionDir CObstacle::GetCollisionDir(CCollider* pOther)
{
	ColliderInfo obj = ColliderInfo(GetCollider()->GetPos(), GetCollider()->GetScale());
	ColliderInfo other = ColliderInfo(pOther->GetPos(), pOther->GetScale());

	// x, y �� �� ���� �����ִ� �� Ȯ��
	if (((obj.scale.x + other.scale.x) * 0.5f - abs(obj.pos.x - other.pos.x) < offset * 4
		&& ((obj.scale.y + other.scale.y) * 0.5f - abs(obj.pos.y - other.pos.y)) < offset * 4))
	{
		return CollisionDir::None;
	}
	else if (((obj.scale.x + other.scale.x) * 0.5f - abs(obj.pos.x - other.pos.x))
		< (obj.scale.y + other.scale.y) * 0.5f - abs(obj.pos.y - other.pos.y))
	{
		if (obj.pos.x > other.pos.x && obj.left < other.right - offset)
			return CollisionDir::Left;
		if (obj.pos.x < other.pos.x && obj.right > other.left + offset)
			return CollisionDir::Right;
	}
	else
	{
		if (obj.pos.y > other.pos.y && obj.up < other.down - offset)
			return CollisionDir::Up;
		if (obj.pos.y < other.pos.y && obj.down > other.up + offset)
			return CollisionDir::Down;
	}

	return CollisionDir::None;
}

float CObstacle::GetOnGroundPosY()
{
	return GROUNDPOSY - 0.5 * m_vecScale.y;
}
