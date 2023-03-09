#pragma once
#include "CState.h"

class CPlayer;
class CSound;

class CPlayerStateDash : public CState
{
private:
	CPlayer* pPlayer;
	Vector m_vecPos;
	float fCooltime;
	CSound* pSound = RESOURCE->LoadSound(L"player_dash", L"Sound\\player_dash.mp3");
public:
	CPlayerStateDash(CPlayer* pPlayer) { this->pPlayer = pPlayer; }
	virtual ~CPlayerStateDash();

	void Enter() override;
	void Update() override;
	void Exit() override;


};