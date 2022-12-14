#pragma once
#include "CState.h"

class CPlayer;

class CPlayerStateIdle : public CState
{
private:
	CPlayer* pPlayer;
	Vector m_vecPos;

public:
	CPlayerStateIdle(CPlayer* pPlayer) { this->pPlayer = pPlayer; }
	virtual ~CPlayerStateIdle();

	void Enter() override;
	void Update() override;
	void Exit() override;


};

