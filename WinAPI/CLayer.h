#pragma once
#include "CImageObject.h"
class CLayer : public CImageObject
{
public:
	CLayer();
	virtual~CLayer();

	void SetScreenFixed(bool fixed);

private:
	Vector		m_vecAbsolutePos;	// 게임에서의 절대 위치
	Vector		m_vecRenderPos;		// 게임에서의 그려질 위치
	bool		m_bScreenFixed;		// 화면 고정 여부

private:
	void GameObjectInit() override;
	void GameObjectUpdate() override;
	void GameObjectRender() override;
	void GameObjectRelease() override;
};

