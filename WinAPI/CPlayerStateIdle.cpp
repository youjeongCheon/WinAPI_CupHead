#include "framework.h"
#include "CPlayerStateIdle.h"

#include "CPlayer.h"
#include "CState.h"


CPlayerStateIdle::~CPlayerStateIdle()
{
}

void CPlayerStateIdle::Enter()
{
}

void CPlayerStateIdle::Update()
{
	if (BUTTONDOWN(VK_RIGHT)|| BUTTONDOWN(VK_LEFT))
		pPlayer->ChangeState(PlayerState::Run);
	else if (BUTTONDOWN('Z'))
		pPlayer->ChangeState(PlayerState::Jump);
	else if(BUTTONDOWN(VK_SHIFT))
		pPlayer->ChangeState(PlayerState::Dash);
	else if (BUTTONDOWN(VK_DOWN))
		pPlayer->ChangeState(PlayerState::Duck);
	else if (BUTTONDOWN('C'))
		pPlayer->ChangeState(PlayerState::Aim);
	else if (BUTTONDOWN('X'))
		pPlayer->ChangeState(PlayerState::Shoot);

	if(pPlayer->GetLookDir().x==+1)
		pPlayer->SetStateName(L"IdleRight");
	else if(pPlayer->GetLookDir().x == -1)
		pPlayer->SetStateName(L"IdleLeft");
}

void CPlayerStateIdle::Exit()
{
}
