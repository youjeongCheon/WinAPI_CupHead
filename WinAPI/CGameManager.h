#pragma once

class CPlayer;

class CGameManager : public SingleTon<CGameManager>
{
	friend SingleTon<CGameManager>;
	friend CCore;

private:
	CGameManager();
	virtual ~CGameManager();
	
	
	void Init();
	void Update();
	void Release();

};

