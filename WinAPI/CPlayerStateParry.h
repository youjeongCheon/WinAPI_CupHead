#pragma once
#include "CState.h"

class CPlayer;
class CSound;

class CPlayerStateParry :  public CState
{
private:
	CPlayer* pPlayer;
	Vector m_vecPos;
	float fCooltime;
	CSound* pSound = RESOURCE->LoadSound(L"player_parry", L"Sound\\player_parry.mp3");

public:
	CPlayerStateParry(CPlayer* pPlayer) { this->pPlayer = pPlayer; }
	virtual ~CPlayerStateParry();

	void Enter() override;
	void Update() override;
	void Exit() override;
};

