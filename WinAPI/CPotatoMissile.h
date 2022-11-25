#pragma once
#include "CMonsterMissile.h"

class CPotatoMissile : public CMonsterMissile
{
public: 
	CPotatoMissile();
	virtual ~CPotatoMissile();

private:
	CImage* m_pImgMissile;
	CAnimator* m_pAnimator;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

};

