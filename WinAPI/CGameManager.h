#pragma once

class CPlayer;

class CGameManager : public SingleTon<CGameManager>
{
	friend SingleTon<CGameManager>;
	friend CCore;

private:
	CGameManager();
	virtual ~CGameManager();

private:
	CPlayer* pPlayer;

public: 
	void SetPlayer(CPlayer* player);
	Vector GetPlayerPos();

private:
	void Init();
	void Update();
	void Render();
	void Release();
};

#define SETPLAYER(pPlayer) CGameManager::GetInstance()->SetPlayer(pPlayer)
#define PLAYERPOS CGameManager::GetInstance()->GetPlayerPos()
