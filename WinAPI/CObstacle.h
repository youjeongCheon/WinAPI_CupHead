#pragma once
#include "CGameObject.h"

class CObstacle : public CGameObject
{
public:
	enum class CollisionDir { Up, Down, Left, Right, None };

public:
	CObstacle();
	virtual ~CObstacle();

	float GetOnGroundPosY();

private:
	CollisionDir dir;
	float		 offset;
	bool bpass;

private:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;

	void OnCollisionEnter(CCollider* pOther)	override;
	void OnCollisionStay(CCollider* pOther)		override;
	void OnCollisionExit(CCollider* pOther)		override;

private:
	CollisionDir GetCollisionDir(CCollider* pOther);
};


