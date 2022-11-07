#pragma once
#include "CState.h"

class CPlayer;

class CPlayerStateAim : public CState
{
private:
	CPlayer* pPlayer;
	Vector m_vecPos;

public:
	CPlayerStateAim(CPlayer* pPlayer) { this->pPlayer = pPlayer; }
	virtual ~CPlayerStateAim();

	void Enter() override;
	void Update() override;
	void Exit() override;
};

