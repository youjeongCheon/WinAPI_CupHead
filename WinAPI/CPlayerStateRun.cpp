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
	if (pPlayer->ActGravity())
	{
		pPlayer->ChangeState(PlayerState::Fall);
	}
	else
	{
		if (BUTTONSTAY('C'))
		{
			// RunShooT
			str += L"Shoot";
			if (BUTTONDOWN('X'))
			{
				pPlayer->CreateMissile(pPlayer->GetPos(), pPlayer->GetLookDir());
			}

		}
		if (BUTTONSTAY(VK_RIGHT))
		{
			pPlayer->SetMoveDir(Vector(+1, 0));
			m_vecPos = pPlayer->GetPos();
			m_vecPos.x += 400 * DT;
			pPlayer->SetPos(m_vecPos);
			pPlayer->SetLookDir(Vector(+1, 0));
		}
		else if (BUTTONSTAY(VK_LEFT))
		{
			pPlayer->SetMoveDir(Vector(-1, 0));
			m_vecPos = pPlayer->GetPos();
			m_vecPos.x -= 400 * DT;
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
		if (BUTTONDOWN('V'))
			pPlayer->ChangeState(PlayerState::SpecialAttack);
	}

	 if (pPlayer->GetLookDir().x == +1)
		 str += L"Right";
	 else if (pPlayer->GetLookDir().x == -1)
		 str += L"Left";
	 pPlayer->SetStateName(str);

}

void CPlayerStateRun::Exit()
{
}
