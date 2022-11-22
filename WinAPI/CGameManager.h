#pragma once

class CPlayer;
class COverWorldPlayer;

class CGameManager : public SingleTon<CGameManager>
{
	friend SingleTon<CGameManager>;
	friend CCore;

private:
	CGameManager();
	virtual ~CGameManager();

private:
	CPlayer* pPlayer;
	COverWorldPlayer* pOverWorldPlayer;
	Vector m_vecOverWorldPlayerPos;

public: 
	void SetPlayer(CPlayer* player);
	void SetOverWorldPlayer(COverWorldPlayer* player);
	void SetOverWorldPlayerPos();
	void GetOverWorldPlayerPos();
	Vector GetPlayerPos();

private:
	void Init();
	void Update();
	void Render();
	void Release();
};

#define SETPLAYER(pPlayer)						CGameManager::GetInstance()->SetPlayer(pPlayer)
#define PLAYERPOS								CGameManager::GetInstance()->GetPlayerPos()
#define SETOVERWORLDPLAYER(pOverWorldPlayer)	CGameManager::GetInstance()->SetOverWorldPlayer(pOverWorldPlayer)
#define SETOVERWORLDPLAYERPOS					CGameManager::GetInstance()->SetOverWorldPlayerPos()
#define GETOVERWORLDPLAYERPOS					CGameManager::GetInstance()->GetOverWorldPlayerPos()
