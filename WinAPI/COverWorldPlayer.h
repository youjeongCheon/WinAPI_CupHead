#pragma once
#include "CGameObject.h"

class CImage;
class CAnimator;

class COverWorldPlayer : public CGameObject
{
public:
	COverWorldPlayer();
	virtual~COverWorldPlayer();

private:
	CImage* m_pImage;
	CImage* m_pImageLeft;

	CAnimator* m_pAnimator;

	Vector m_vecMoveDir;
	Vector m_vecLookDir;
	bool m_bIsMove;

	float m_fSpeed = 200.0f;


private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void AnimatorUpdate();

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;

};
#define OVERWORLDPLAYERSTARTPOS Vector(720-500,976-720)
