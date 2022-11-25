#pragma once
#include "CGameObject.h"

class CImage;
class CAnimator;

class CMissile : public CGameObject
{
public:
	CMissile();
	virtual ~CMissile();

private:
	Vector m_vecDir;
	float m_fVelocity;
	bool m_bExMissile;
	bool bCreate;
	CAnimator* m_pAnimator;

	
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
	void CreateSpawn(Vector pos);

public:
	void SetDir(Vector dir);
	void SetVelocity(float velocity);
	void SetExMissile(bool bExMissile);
	bool GetExMissile();
	void DeathMissile();
};