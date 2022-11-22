#include "framework.h"
#include "CGameManager.h"

#include "CPlayer.h"
#include "COverWorldPlayer.h"

CGameManager::CGameManager()
{
	pPlayer = nullptr;
	pOverWorldPlayer = nullptr;
	m_vecOverWorldPlayerPos = OVERWORLDPLAYERSTARTPOS;
}

CGameManager::~CGameManager()
{
}

Vector CGameManager::GetPlayerPos()
{
	return pPlayer->GetPos();
}

void CGameManager::SetPlayer(CPlayer* player)
{
	pPlayer = player;
}

void CGameManager::SetOverWorldPlayer(COverWorldPlayer* player)
{
	pOverWorldPlayer = player;
}

void CGameManager::SetOverWorldPlayerPos()
{
	pOverWorldPlayer->SetPos(m_vecOverWorldPlayerPos);
}

void CGameManager::GetOverWorldPlayerPos()
{
	m_vecOverWorldPlayerPos = pOverWorldPlayer->GetPos();
}

void CGameManager::Init()
{
}

void CGameManager::Update()
{
}

void CGameManager::Render()
{
}

void CGameManager::Release()
{
}
