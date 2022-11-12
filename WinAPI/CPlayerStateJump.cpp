#include "framework.h"
#include "CPlayerStateJump.h"

#include "CPlayer.h"
#include "CState.h"

CPlayerStateJump::~CPlayerStateJump()
{
}

void CPlayerStateJump::Enter()
{
	fCooltime = 0;
}

void CPlayerStateJump::Update()
{
	fCooltime += DT;
	wstring str = L"Jump";
	if (fCooltime <= 0.5f)
	{
		if (BUTTONDOWN(VK_SHIFT)&& !(pPlayer->GetPreState() == PlayerState::Dash))
		{
			pPlayer->ChangeState(PlayerState::Dash);
		}
		else
		{
			m_vecPos = pPlayer->GetPos();
			// 중력 포물선 운동
			if (fCooltime > 0.3f)
				m_vecPos.y -= 200 * DT;
			else
				m_vecPos.y -= 600 * DT;
			
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
		}
	}
	else
	{
		if(!pPlayer->isGround())
			pPlayer->ChangeState(PlayerState::Fall);
		else
			pPlayer->ChangeState(PlayerState::Idle);
	}
	if (pPlayer->GetLookDir().x == +1)
		str += L"Right";
	else if (pPlayer->GetLookDir().x == -1)
		str += L"Left";
	pPlayer->SetStateName(str);
}

void CPlayerStateJump::Exit()
{
}
