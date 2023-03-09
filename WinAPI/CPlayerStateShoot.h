#pragma once
#include "CState.h"

class CPlayer;
class CSound;

class CPlayerStateShoot : public CState
{
private:
	CPlayer* pPlayer;
	Vector m_LookDir;
	float fCooltime = 0;

	Vector m_vecMissilePos;
	bool bShoot;

	CSound* pSound = RESOURCE->LoadSound(L"player_shoot", L"Sound\\player_shoot.wav");

public:
	CPlayerStateShoot(CPlayer* pPlayer) { this->pPlayer = pPlayer; }
	virtual ~CPlayerStateShoot();

	void Enter() override;
	void Update() override;
	void Exit() override;
};

