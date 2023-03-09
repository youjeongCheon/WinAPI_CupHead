#pragma once
#include "CState.h"

class CPlayer;
class CSound;

class CPlayerStateTakeHit : public CState
{
private:
	CPlayer* pPlayer;
	Vector m_vecPos;
	float fCooltime;
	CSound* pSound = RESOURCE->LoadSound(L"player_hit", L"Sound\\player_hit.mp3");

public:
	CPlayerStateTakeHit(CPlayer* pPlayer) { this->pPlayer = pPlayer; }
	virtual ~CPlayerStateTakeHit();

	void Enter() override;
	void Update() override;
	void Exit() override;
};

