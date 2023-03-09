#pragma once
#include "CState.h"

class CPlayer;
class CSound;

class CPlayerStateJump : public CState
{
private:
	CPlayer* pPlayer;
	Vector m_vecPos;
	float fCooltime;
	CSound* pSound = RESOURCE->LoadSound(L"player_jump",L"Sound\\player_jump.mp3");

public:
	CPlayerStateJump(CPlayer* pPlayer) { this->pPlayer = pPlayer; }
	virtual ~CPlayerStateJump();

	void Enter() override;
	void Update() override;
	void Exit() override;


};