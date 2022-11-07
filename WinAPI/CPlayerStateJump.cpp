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
		if (BUTTONDOWN(VK_SHIFT))
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
				m_vecPos.y -= 500 * DT;
			
			pPlayer->SetPos(m_vecPos);
		}
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
	else
	{
		
		if (BUTTONDOWN(VK_DOWN))
			pPlayer->ChangeState(PlayerState::Duck);
		if (BUTTONDOWN('C'))
			pPlayer->ChangeState(PlayerState::Aim);
		if (BUTTONDOWN('X'))
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

void CPlayerStateJump::Exit()
{
}
