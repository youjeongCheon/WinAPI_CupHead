#pragma once
#include "CGameObject.h"

class CImage;

class CImageObject : public CGameObject
{
public:
	CImageObject();
	virtual ~CImageObject();

private:
	CImage*		m_pImage;
	Vector		m_vecRenderPos;		// ���ӿ����� �׷��� ��ġ
	bool		m_bChange;
	bool		m_bScreenFixed;		// ȭ�� ���� ����

public:
	CImage*		GetIamge();
	void		SetImage(CImage* pImage);
	void		ChangeScale(bool change, Vector scale);
	void		SetScreenFixed(bool fixed);

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

