#pragma once
#include "CState.h"

class CPlayer;

class CPlayerStateDash : public CState
{
private:
	CPlayer* pPlayer;
	Vector m_vecPos;
	float fCooltime;

public:
	CPlayerStateDash(CPlayer* pPlayer) { this->pPlayer = pPlayer; }
	virtual ~CPlayerStateDash();

	void Enter() override;
	void Update() override;
	void Exit() override;


};