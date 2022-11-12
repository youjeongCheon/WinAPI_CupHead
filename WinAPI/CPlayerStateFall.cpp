#include "framework.h"
#include "CPlayerStateFall.h"

#include "CPlayer.h"

CPlayerStateFall::~CPlayerStateFall()
{
}

void CPlayerStateFall::Enter()
{
}

void CPlayerStateFall::Update()
{
	wstring str = L"Jump";

	if (!pPlayer->isGround())
	{
		m_vecPos = pPlayer->GetPos();
		m_vecPos.y += 500 * DT;
		pPlayer->SetPos(m_vecPos);

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
		if (BUTTONSTAY(VK_SHIFT) && !(pPlayer->GetPreState() == PlayerState::Dash))
			pPlayer->ChangeState(PlayerState::Dash);
	}
	else
		pPlayer->ChangeState(PlayerState::Idle);

	if (pPlayer->GetLookDir().x == +1)
		str += L"Right";
	else if (pPlayer->GetLookDir().x == -1)
		str += L"Left";

	pPlayer->SetStateName(str);
}

void CPlayerStateFall::Exit()
{
}
