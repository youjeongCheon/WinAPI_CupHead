#pragma once
#include "CParryObject.h"
class CPotatoParry : public CParryObject
{
public:
	CPotatoParry();
	virtual~CPotatoParry();

private:
	CImage* m_pImgParry;
	CAnimator* m_pAnimator;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

