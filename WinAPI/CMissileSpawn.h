#pragma once
#include "CGameObject.h"

class CImage;
class CAnimator;

class CMissileSpawn : public CGameObject
{
public:
	CMissileSpawn();
	virtual ~CMissileSpawn();
private:
	CAnimator* m_pAnimator;
	CImage* m_pSpawnImage;

	float fCoolTime = 0;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

