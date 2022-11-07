#include "framework.h"
#include "CPlayerStateAim.h"

#include "CPlayer.h"
#include "CState.h"

CPlayerStateAim::~CPlayerStateAim()
{
}

void CPlayerStateAim::Enter()
{
}

void CPlayerStateAim::Update()
{
	wstring str = L"Aim";
	m_LookDir = pPlayer->GetLookDir();
	if (m_LookDir.x == +1)
		str += L"Right";
	else if (m_LookDir.x == -1)
		str += L"Left";

	int up = +3, down = -3, right = +1, left = -1;
	int result = 0;
	if (BUTTONSTAY('C'))
	{
		if (BUTTONSTAY(VK_UP))
			result += up;
		else if (BUTTONSTAY(VK_DOWN))
			result += down;
		if (BUTTONSTAY(VK_RIGHT))
			result += right;
		else if (BUTTONSTAY(VK_LEFT))
			result += left;

		if (BUTTONDOWN('X'))
			pPlayer->ChangeState(PlayerState::Shoot);
	}
	
	switch (result)
	{
	case 4:
		str = L"AimRightDiagonalUp";
		m_LookDir = Vector(+1, -3);
		break;
	case 3:
		str += L"Up";
		m_LookDir.y = -2;
		break;
	case 2:
		str = L"AimLeftDiagonalUp";
		m_LookDir = Vector(-1, -3);
		break;
	case 1:
		str = L"AimRight";
		m_LookDir.y = 0;
		m_LookDir.x = +1;
		break;
	case 0:
		if (!BUTTONSTAY('C'))
		{
			m_LookDir.y = 0;
			pPlayer->ChangeState(PlayerState::Idle);
		}
		break;
	case -1:
		str = L"AimLeft";
		m_LookDir.y = 0;
		m_LookDir.x = -1;
		break;
	case -2:
		str = L"AimRightDiagonalDown";
		m_LookDir = Vector(+1, +3);
		break;
	case -3:
		str += L"Down";
		m_LookDir.y = +2;
		break;
	case -4:
		str = L"AimLeftDiagonalDown";
		m_LookDir = Vector(-1, +3);
		break;
	}
	pPlayer->SetStateName(str);
	pPlayer->SetLookDir(m_LookDir);
}

void CPlayerStateAim::Exit()
{
}
