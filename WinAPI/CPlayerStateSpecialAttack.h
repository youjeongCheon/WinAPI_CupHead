#pragma once
#include "CState.h"

class CPlayer;

class CPlayerStateSpecialAttack : public CState
{
private:
	CPlayer* pPlayer;
	Vector m_LookDir;
	float fCooltime;

	Vector m_vecMissilePos;
	bool bShoot;

public:
	CPlayerStateSpecialAttack(CPlayer* pPlayer) { this->pPlayer = pPlayer; }
	virtual ~CPlayerStateSpecialAttack();

	void Enter() override;
	void Update() override;
	void Exit() override;

};

