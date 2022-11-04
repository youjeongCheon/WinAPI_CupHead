#pragma once
#include "CState.h"

class CPlayer;

class CPlayerStateDash : public CState
{
private:
	CPlayer* pPlayer;

public:
	CPlayerStateDash(CPlayer* pPlayer) { this->pPlayer = pPlayer; }
	virtual ~CPlayerStateDash();

	void Enter() override;
	void Update() override;
	void Exit() override;


};