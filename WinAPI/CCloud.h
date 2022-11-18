#pragma once
#include "CGameObject.h"
class CCloud :  public CGameObject
{
public:
	CCloud();
	virtual~CCloud();
private:
	CImage* m_pImgCloud;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

