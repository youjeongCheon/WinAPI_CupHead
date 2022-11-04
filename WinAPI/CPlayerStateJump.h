#pragma once
#include "CState.h"

class CPlayer;

class CPlayerStateJump : public CState
{
private:
	CPlayer* pPlayer;

public:
	CPlayerStateJump(CPlayer* pPlayer) { this->pPlayer = pPlayer; }
	virtual ~CPlayerStateJump();

	void Enter() override;
	void Update() override;
	void Exit() override;


};