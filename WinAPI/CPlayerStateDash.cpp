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
		pPlayer->ChangeState(PlayerState::Idle);
	if (BUTTONDOWN(VK_RIGHT) || BUTTONDOWN(VK_LEFT))
		pPlayer->ChangeState(PlayerState::Run);
	if (BUTTONDOWN('Z'))
		pPlayer->ChangeState(PlayerState::Jump);
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

void CPlayerStateDash::Exit()
{
}
