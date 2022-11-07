#pragma once
#include "CGameObject.h"

class CImage;
class CAnimator;

enum  class MissileState { Spawn, Loop, Death, EX_Loop, EX_Death };

class CMissile : public CGameObject
{
public:
	CMissile(bool ExMissile) { m_bExMissile = ExMissile; };
	CMissile();
	virtual ~CMissile();

private:
	Vector m_vecDir;
	float m_fVelocity;
	Vector m_vecPos;
	bool m_bExMissile;

	CAnimator* m_pAnimator;

	CImage* m_pSpawnImage;
	CImage* m_pLoopImage;
	CImage* m_pDeathImage;
	CImage* m_pExLoopImage;
	CImage* m_pExDeathImage;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;

public:
	void SetDir(Vector dir);
	void SetVelocity(float velocity);
};