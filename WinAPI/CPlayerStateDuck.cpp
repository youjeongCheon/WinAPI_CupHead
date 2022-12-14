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
	
	wstring str = L"Duck";
	if (pPlayer->GetLookDir().x == +1)
		str += L"Right";
	else if (pPlayer->GetLookDir().x == -1)
		str += L"Left";

	if (BUTTONSTAY(VK_DOWN))
	{
		fCooltime += DT;
		if (fCooltime > 0.7f)
		{
			str += L"Idle";
		}
		if (BUTTONSTAY(VK_DOWN) && BUTTONDOWN('Z')&&pPlayer->GetOnBlock())
		{
			pPlayer->SetPassBlock(true);
		}
	}
	else 
		pPlayer->ChangeState(PlayerState::Idle);

	 if (BUTTONSTAY(VK_RIGHT) || BUTTONSTAY(VK_LEFT))
		pPlayer->ChangeState(PlayerState::Run);
	 if (BUTTONDOWN('Z'))
		 if(!pPlayer->GetPassBlock())
			 pPlayer->ChangeState(PlayerState::Jump);
	 if (BUTTONDOWN(VK_SHIFT))
		pPlayer->ChangeState(PlayerState::Dash);
	 if (BUTTONDOWN('C'))
		pPlayer->ChangeState(PlayerState::Aim);
	 if (BUTTONDOWN('X'))
		pPlayer->ChangeState(PlayerState::Shoot);
	 if (BUTTONDOWN('V'))
		 pPlayer->ChangeState(PlayerState::SpecialAttack);
	 pPlayer->SetStateName(str);
}

void CPlayerStateDuck::Exit()
{
	
}
