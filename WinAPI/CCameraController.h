#pragma once
#include "CGameObject.h"

class CPlayer;

class CCameraController : public CGameObject
{
public:
	CCameraController(CPlayer* pPlayer) { this->pPlayer = pPlayer; }
	virtual ~CCameraController();

private:
	float m_fMouseTime = 1;
	float m_fScrollSpeed = 200;

	CPlayer* pPlayer;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

