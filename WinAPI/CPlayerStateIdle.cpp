#include "framework.h"
#include "CPlayerStateIdle.h"

#include "CPlayer.h"

CPlayerStateIdle::~CPlayerStateIdle()
{
}

void CPlayerStateIdle::Enter()
{
}

void CPlayerStateIdle::Update()
{
	wstring str = L"Idle";

	// 땅에 있지 않는다면
	if (pPlayer->ActGravity())
	{
		pPlayer->ChangeState(PlayerState::Fall);
	}
	else
	{
		if (BUTTONSTAY(VK_RIGHT) || BUTTONSTAY(VK_LEFT))
			pPlayer->ChangeState(PlayerState::Run);
		if (BUTTONSTAY('Z'))
			pPlayer->ChangeState(PlayerState::Jump);
		if (BUTTONSTAY(VK_SHIFT))
			pPlayer->ChangeState(PlayerState::Dash);
		if (BUTTONSTAY(VK_DOWN))
			pPlayer->ChangeState(PlayerState::Duck);
		if (BUTTONSTAY('C'))
			pPlayer->ChangeState(PlayerState::Aim);
		if (BUTTONSTAY('X'))
			pPlayer->ChangeState(PlayerState::Shoot);
		if (BUTTONDOWN('Y'))
			pPlayer->ChangeState(PlayerState::SpecialAttack);
	}

	if (pPlayer->GetLookDir().x == +1)
		str += L"Right";
	else if (pPlayer->GetLookDir().x == -1)
		str += L"Left";

	pPlayer->SetStateName(str);
}

void CPlayerStateIdle::Exit()
{
}
