#pragma once
#include "CState.h"

class CPlayer;

class CPlayerStateShoot : public CState
{
private:
	CPlayer* pPlayer;
	Vector m_vecPos;

public:
	CPlayerStateShoot(CPlayer* pPlayer) { this->pPlayer = pPlayer; }
	virtual ~CPlayerStateShoot();

	void Enter() override;
	void Update() override;
	void Exit() override;
};

