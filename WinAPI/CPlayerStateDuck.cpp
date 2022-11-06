#include "framework.h"
#include "CPlayerStateDuck.h"

#include "CPlayer.h"
#include "CState.h"

CPlayerStateDuck::~CPlayerStateDuck()
{
}

void CPlayerStateDuck::Enter()
{
	fCooltime = 0;
}

void CPlayerStateDuck::Update()
{
	fCooltime += DT;
	wstring str = L"Duck";
	if (pPlayer->GetLookDir().x == +1)
		str += L"Right";
	else if (pPlayer->GetLookDir().x == -1)
		str += L"Left";

	if (BUTTONSTAY(VK_DOWN))
	{
		if (fCooltime > 0.7f)
		{
			str += L"Idle";
		}
	}
	else 
		pPlayer->ChangeState(PlayerState::Idle);

	 if (BUTTONDOWN(VK_RIGHT) || BUTTONDOWN(VK_LEFT))
		pPlayer->ChangeState(PlayerState::Run);
	 if (BUTTONDOWN('Z'))
		pPlayer->ChangeState(PlayerState::Jump);
	 if (BUTTONDOWN(VK_SHIFT))
		pPlayer->ChangeState(PlayerState::Dash);
	 if (BUTTONDOWN('C'))
		pPlayer->ChangeState(PlayerState::Aim);
	 if (BUTTONDOWN('X'))
		pPlayer->ChangeState(PlayerState::Shoot);

	 pPlayer->SetStateName(str);
}

void CPlayerStateDuck::Exit()
{
	
}
