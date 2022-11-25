#pragma once
#include "CState.h"

class CPlayer;

class CPlayerStateDuck : public CState
{
private:
	CPlayer* pPlayer;
	float fCooltime;

public:
	CPlayerStateDuck(CPlayer* pPlayer) { this->pPlayer = pPlayer; }
	virtual ~CPlayerStateDuck();

	void Enter() override;
	void Update() override;
	void Exit() override;


};