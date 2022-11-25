#pragma once
#include "CImageObject.h"

class CImage;

class CTitleObject : public CImageObject
{
public:
	CTitleObject();
	virtual ~CTitleObject();

private:
	CImage* m_pImage;
	CAnimator* m_pAnimator;

	float fCoolTime;

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

