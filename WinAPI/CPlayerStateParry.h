#pragma once
#include "CState.h"

class CPlayer;

class CPlayerStateParry :  public CState
{
private:
	CPlayer* pPlayer;
	Vector m_vecPos;
	float fCooltime;

public:
	CPlayerStateParry(CPlayer* pPlayer) { this->pPlayer = pPlayer; }
	virtual ~CPlayerStateParry();

	void Enter() override;
	void Update() override;
	void Exit() override;
};

