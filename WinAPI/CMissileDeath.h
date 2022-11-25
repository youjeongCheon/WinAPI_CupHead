#pragma once
#include "CMissile.h"
class CMissileDeath : public CMissile
{
public:
	CMissileDeath();
	virtual ~CMissileDeath();
private:
	CAnimator* m_pAnimator;
	CImage* m_pImgMissileDeath;

	float fCoolTime = 0;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

