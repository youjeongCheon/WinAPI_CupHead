#pragma once
#include "CImageObject.h"
class CLayer : public CImageObject
{
public:
	CLayer();
	virtual~CLayer();

	void SetScreenFixed(bool fixed);

private:
	Vector		m_vecAbsolutePos;	// ���ӿ����� ���� ��ġ
	Vector		m_vecRenderPos;		// ���ӿ����� �׷��� ��ġ
	bool		m_bScreenFixed;		// ȭ�� ���� ����

private:
	void GameObjectInit() override;
	void GameObjectUpdate() override;
	void GameObjectRender() override;
	void GameObjectRelease() override;
};

