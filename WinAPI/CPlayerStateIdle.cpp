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
	wstring str = L"";

	// 땅에 있지 않는다면
	if (!pPlayer->isGround())
	{
		m_vecPos = pPlayer->GetPos();
		m_vecPos.y += 500 * DT;
		pPlayer->SetPos(m_vecPos);
		str += L"Jump";

		if (BUTTONSTAY(VK_RIGHT))
		{
			m_vecPos = pPlayer->GetPos();
			m_vecPos.x += 200 * DT;
			pPlayer->SetPos(m_vecPos);
			pPlayer->SetLookDir(Vector(+1, 0));
		}
		else if (BUTTONSTAY(VK_LEFT))
		{
			m_vecPos = pPlayer->GetPos();
			m_vecPos.x -= 200 * DT;
			pPlayer->SetPos(m_vecPos);
			pPlayer->SetLookDir(Vector(-1, 0));
		}
		if (BUTTONSTAY(VK_SHIFT)&&!(pPlayer->GetPreState()==PlayerState::Dash))
			pPlayer->ChangeState(PlayerState::Dash);
	}
	else
	{
		str += L"Idle";
		if ( (VK_RIGHT) || BUTTONSTAY(VK_LEFT))
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
