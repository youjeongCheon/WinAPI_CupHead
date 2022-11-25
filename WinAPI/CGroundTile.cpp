#include "framework.h"
#include "CGroundTile.h"

#include "CResourceManager.h"
#include "CRenderManager.h"
#include "CCollider.h"
#include "COverWorldPlayer.h"

CGroundTile::CGroundTile()
{
	dir = CollisionDir::None;
	offset = 0.25f;
}

CGroundTile::~CGroundTile()
{
}

void CGroundTile::Init()
{
	CTile::Init();

	AddCollider(ColliderType::Rect,
		Vector(CTile::TILESIZE, CTile::TILESIZE),
		Vector(CTile::TILESIZE / 2, CTile::TILESIZE / 2));
}

void CGroundTile::Update()
{
	CTile::Update();
}

void CGroundTile::Render()
{
	CTile::Render();

	ComponentRender();
}

void CGroundTile::Release()
{
	CTile::Release();
}

void CGroundTile::OnCollisionEnter(CCollider* pOther)
{
	
}

void CGroundTile::OnCollisionStay(CCollider* pOther)
{
	if (pOther->GetObjName() == L"OverWorldPlayer")
	{
		// �÷��̾ �浹 ���� ��� �о�� ����
		COverWorldPlayer* pPlayer = static_cast<COverWorldPlayer*>(pOther->GetOwner());

		dir = GetCollisionDir(pOther);

		switch (GetCollisionDir(pOther))
		{
		case CollisionDir::Up:
		{
			pPlayer->SetPos(
				pPlayer->GetPos().x,
				GetCollider()->GetPos().y
				- (GetCollider()->GetScale().y + pOther->GetScale().y) * 0.5f + offset
				- pOther->GetOffsetPos().y
			);
		}
		break;

		case CollisionDir::Down:
		{
			pPlayer->SetPos(
				pPlayer->GetPos().x,
				GetCollider()->GetPos().y
				+ (GetCollider()->GetScale().y + pOther->GetScale().y) * 0.5f - offset
				- pOther->GetOffsetPos().y
			);
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

void CGroundTile::OnCollisionExit(CCollider* pOther)
{
	// ��Ÿ�ϰ� �浹���� ��� ó��
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

typename CGroundTile::CollisionDir CGroundTile::GetCollisionDir(CCollider* pOther)
{
	ColliderInfo obj = ColliderInfo(GetCollider()->GetPos(), GetCollider()->GetScale());
	ColliderInfo other = ColliderInfo(pOther->GetPos(), pOther->GetScale());

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