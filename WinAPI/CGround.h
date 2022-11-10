#pragma once
#include "CGameObject.h"
class CGround : public CGameObject
{
public:
	CGround();
	virtual ~CGround();

private:
	float		 offset;

private:
	void Init()		override;
	void Update()	override;
	void Render()	override;
	void Release()	override;

	void OnCollisionEnter(CCollider* pOther)	override;
	void OnCollisionStay(CCollider* pOther)		override;
	void OnCollisionExit(CCollider* pOther)		override;
};