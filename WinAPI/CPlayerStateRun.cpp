#include "framework.h"
#include "CPlayerStateRun.h"

#include "CPlayer.h"
#include "CState.h"

CPlayerStateRun::~CPlayerStateRun()
{
}

void CPlayerStateRun::Enter()
{


	
}

void CPlayerStateRun::Update()
{
	wstring str = L"Run";
	if (BUTTONSTAY(VK_RIGHT))
	{
		m_vecPos = pPlayer->GetPos();
		m_vecPos.x += 500 * DT;
		pPlayer->SetPos(m_vecPos);
		pPlayer->SetLookDir(Vector(+1, 0));
	}
	else if (BUTTONSTAY(VK_LEFT))
	{
		m_vecPos = pPlayer->GetPos();
		m_vecPos.x -= 500 * DT;
		pPlayer->SetPos(m_vecPos);
		pPlayer->SetLookDir(Vector(-1, 0));
	}
	else
		pPlayer->ChangeState(PlayerState::Idle);
	 if (BUTTONDOWN('Z'))
		pPlayer->ChangeState(PlayerState::Jump);
	 if (BUTTONDOWN(VK_SHIFT))
		pPlayer->ChangeState(PlayerState::Dash);
	 if (BUTTONDOWN(VK_DOWN))
		pPlayer->ChangeState(PlayerState::Duck);
	 if (BUTTONDOWN('C'))
		pPlayer->ChangeState(PlayerState::Aim);
	 if (BUTTONDOWN('X'))
		pPlayer->ChangeState(PlayerState::Shoot);

	 if (pPlayer->GetLookDir().x == +1)
		 str += L"Right";
	 else if (pPlayer->GetLookDir().x == -1)
		 str += L"Left";
	 pPlayer->SetStateName(str);

}

void CPlayerStateRun::Exit()
{
}
