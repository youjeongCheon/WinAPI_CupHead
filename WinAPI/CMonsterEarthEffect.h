#pragma once
#include "CGameObject.h"
class CMonsterEarthEffect : public CGameObject
{
public:
	CMonsterEarthEffect();
	virtual~CMonsterEarthEffect();

private:
	CAnimator* m_pAnimatorEarth;
	float fEarthCoolTime;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

