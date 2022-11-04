#include "framework.h"
#include "CPlayerStateRun.h"

#include "CPlayer.h"
#include "CState.h"

CPlayerStateRun::~CPlayerStateRun()
{
}

void CPlayerStateRun::Enter()
{
	if (BUTTONSTAY(VK_RIGHT))
	{
		pPlayer->GetPos().x += m_fSpeed * DT;
		m_bIsMove = true;
		m_vecMoveDir.x = +1;
	}
}

void CPlayerStateRun::Update()
{
}

void CPlayerStateRun::Exit()
{
}
