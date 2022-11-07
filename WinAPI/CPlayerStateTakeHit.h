#pragma once
#include "CState.h"

class CPlayer;

class CPlayerStateTakeHit : public CState
{
private:
	CPlayer* pPlayer;
	Vector m_vecPos;

public:
	CPlayerStateTakeHit(CPlayer* pPlayer) { this->pPlayer = pPlayer; }
	virtual ~CPlayerStateTakeHit();

	void Enter() override;
	void Update() override;
	void Exit() override;
};

