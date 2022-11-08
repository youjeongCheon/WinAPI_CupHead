#pragma once
#include "CGameObject.h"

class CImage;

class CImageObject : public CGameObject
{
public:
	CImageObject();
	virtual ~CImageObject();

private:
	CImage* m_pImage;
	bool m_bChange;

public:
	CImage* GetIamge();
	void SetImage(CImage* pImage);
	void ChangeScale(bool change, Vector scale);

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

