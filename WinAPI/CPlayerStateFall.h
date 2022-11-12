#pragma once
#include "CState.h"

class CPlayer;

class CPlayerStateFall : public CState
{
private:
	CPlayer* pPlayer;
	Vector m_vecPos;

public:
	CPlayerStateFall(CPlayer* pPlayer) { this->pPlayer = pPlayer; }
	virtual ~CPlayerStateFall();

	void Enter() override;
	void Update() override;
	void Exit() override;
};

