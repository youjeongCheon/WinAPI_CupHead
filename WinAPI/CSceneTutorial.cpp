#include "framework.h"
#include "CSceneTutorial.h"

#include "CPlayer.h"
#include "CMonster.h"
#include "CCameraController.h"

CSceneTutorial::CSceneTutorial()
{
	pPlayer = nullptr;
}

CSceneTutorial::~CSceneTutorial()
{
}

void CSceneTutorial::Init()
{
	pPlayer = new CPlayer();
	pPlayer->SetPos(PLAYERSTARTPOS);
	AddGameObject(pPlayer);
}

void CSceneTutorial::Enter()
{
}

void CSceneTutorial::Update()
{
}

void CSceneTutorial::Render()
{
}

void CSceneTutorial::Exit()
{
}

void CSceneTutorial::Release()
{
}
