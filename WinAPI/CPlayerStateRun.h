#pragma once
#include "CState.h"

class CPlayer;

class CPlayerStateRun : public CState
{
private:
	CPlayer* pPlayer;
	Vector m_vecPos;

public:
	CPlayerStateRun(CPlayer* pPlayer) { this->pPlayer = pPlayer; }
	virtual ~CPlayerStateRun();

	void Enter() override;
	void Update() override;
	void Exit() override;
};