#pragma once
#include "CMissile.h"

class CSound;

class CMissileDeath : public CMissile
{
public:
	CMissileDeath();
	virtual ~CMissileDeath();
private:
	CAnimator* m_pAnimator;
	CImage* m_pImgMissileDeath;
	CSound* pSound = RESOURCE->LoadSound(L"player_shoot_hit", L"Sound\\player_shoot_hit.wav");
	float fCoolTime = 0;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

