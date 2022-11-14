#pragma once
#include "CTile.h"
class CGroundTile : public CTile
{
public:
	enum class CollisionDir { Up, Down, Left, Right, None };

public:
	CGroundTile();
	virtual ~CGroundTile();

private:
	CollisionDir dir;
	float		 offset;

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

private:
	void OnCollisionEnter(CCollider* pOther) override;
	void OnCollisionStay(CCollider* pOther) override;
	void OnCollisionExit(CCollider* pOther) override;

	CollisionDir GetCollisionDir(CCollider* pOther);
};

