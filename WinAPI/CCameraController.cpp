#include "framework.h"
#include "CCameraController.h"

#include "CInputManager.h"
#include "CCameraManager.h"

#include "CPlayer.h"

CCameraController::~CCameraController()
{
}

void CCameraController::Init()
{
}

void CCameraController::Update()
{
	if (pPlayer->GetPos().x > +WINSIZEX*0.5f && pPlayer->GetPos().x < 5200-WINSIZEX * 0.5f)
	{
		CAMERA->SetTargetPos(Vector(pPlayer->GetPos().x, WINSIZEY * 0.5f), 0);
	}

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
