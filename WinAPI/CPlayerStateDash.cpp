#include "framework.h"
#include "CPlayerStateDash.h"

#include "CPlayer.h"
#include "CState.h"

CPlayerStateDash::~CPlayerStateDash()
{
}

void CPlayerStateDash::Enter()
{
	fCooltime = 0;
}

void CPlayerStateDash::Update()
{
	fCooltime += DT;
	wstring str = L"Dash";

	if (fCooltime <= 0.4f)
	{
		m_vecPos = pPlayer->GetPos();
		m_vecPos.x += 1000 *pPlayer->GetLookDir().x *DT;
		pPlayer->SetPos(m_vecPos);
	}
	else
	{
		if (BUTTONSTAY(VK_RIGHT) || BUTTONSTAY(VK_LEFT))
			pPlayer->ChangeState(PlayerState::Run);
		if (BUTTONSTAY('Z'))
			pPlayer->ChangeState(PlayerState::Jump);
		if (BUTTONSTAY(VK_DOWN))
			pPlayer->ChangeState(PlayerState::Duck);
		if (BUTTONSTAY('C'))
			pPlayer->ChangeState(PlayerState::Aim);
		if (BUTTONSTAY('X'))
			pPlayer->ChangeState(PlayerState::Shoot);
		else
			pPlayer->ChangeState(PlayerState::Idle);
	}
	

	if (pPlayer->GetLookDir().x == +1)
		str += L"Right";
	else if (pPlayer->GetLookDir().x == -1)
		str += L"Left";

	pPlayer->SetStateName(str);
}

void CPlayerStateDash::Exit()
{
}
