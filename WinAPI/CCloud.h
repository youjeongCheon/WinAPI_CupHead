#pragma once
#include "CGameObject.h"
class CCloud :  public CGameObject
{
public:
	CCloud();
	virtual ~CCloud();

private:
	CImage* pImgCloud;
	Vector m_vecDir;
	float m_fVelocity;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

