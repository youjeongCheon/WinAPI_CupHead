#pragma once
#include "CGameObject.h"

class CPlayer;
class COverWorldPlayer;

class CCameraController : public CGameObject
{
public:
	CCameraController();
	virtual ~CCameraController();

	void Setplayer(CPlayer* pPlayer);
	void SetOverWorldPlayer(COverWorldPlayer* pPlayer);
private:
	float m_fMouseTime = 1;
	float m_fScrollSpeed = 200;

	CPlayer* pPlayer;
	COverWorldPlayer* pOverWorldPlayer;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

