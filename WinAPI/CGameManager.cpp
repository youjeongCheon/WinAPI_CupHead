#include "framework.h"
#include "CGameManager.h"

#include "CPlayer.h"

CGameManager::CGameManager()
{
	pPlayer = nullptr;
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
