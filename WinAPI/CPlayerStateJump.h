#pragma once
#include "CState.h"

class CPlayer;

class CPlayerStateJump : public CState
{
private:
	CPlayer* pPlayer;
	Vector m_vecPos;
	float fCooltime;

public:
	CPlayerStateJump(CPlayer* pPlayer) { this->pPlayer = pPlayer; }
	virtual ~CPlayerStateJump();

	void Enter() override;
	void Update() override;
	void Exit() override;


};