#pragma once
#include "CGameObject.h"
class COverWorldObject :  public CGameObject
{
public:
	COverWorldObject();
	virtual~COverWorldObject();

private:
	CImage* pImg;

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;


	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

