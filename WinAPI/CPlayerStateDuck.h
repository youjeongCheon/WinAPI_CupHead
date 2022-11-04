#pragma once
#include "CState.h"

class CPlayer;

class CPlayerStateDuck : public CState
{
private:
	CPlayer* pPlayer;

public:
	CPlayerStateDuck(CPlayer* pPlayer) { this->pPlayer = pPlayer; }
	virtual ~CPlayerStateDuck();

	void Enter() override;
	void Update() override;
	void Exit() override;


};