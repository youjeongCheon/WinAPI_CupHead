#include "framework.h"
#include "CCameraController.h"

#include "CInputManager.h"
#include "CCameraManager.h"

#include "CPlayer.h"

CCameraController::CCameraController()
{
}

CCameraController::~CCameraController()
{
}

void CCameraController::Setplayer(CPlayer* pPlayer)
{
	this->pPlayer = pPlayer;
}

void CCameraController::SetOverWorldPlayer(COverWorldPlayer* pPlayer)
{
	this->pOverWorldPlayer = pPlayer;
}

void CCameraController::Init()
{
}

void CCameraController::Update()
{
	
	Vector dir;
	if (BUTTONSTAY('A'))
	{
		dir.x = -1;
	}
	else if (BUTTONSTAY('D'))
		dir.x = 1;
	else dir.x = 0;

	CAMERA->Scroll(dir, m_fScrollSpeed);
}

void CCameraController::Render()
{
}

void CCameraController::Release()
{
}
