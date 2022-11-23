#include "framework.h"
#include "CPlayerStateSpecialAttack.h"

#include "CPlayer.h"
#include "CState.h"

CPlayerStateSpecialAttack::~CPlayerStateSpecialAttack()
{
}

void CPlayerStateSpecialAttack::Enter()
{
	fCooltime = 0;
	bShoot = false;
}

void CPlayerStateSpecialAttack::Update()
{
	wstring str = L"SpecialAttack";
	m_LookDir = pPlayer->GetLookDir();

	int count = GETSPECIALATTACK;
	if (count <= 0)
		pPlayer->ChangeState(PlayerState::Idle);
	else
	{
		fCooltime += DT;
		
		m_vecMissilePos = pPlayer->GetPos();
		if (bShoot == false)
		{
			if (fCooltime >= 0.4f)
			{
				pPlayer->CreateMissile(m_vecMissilePos, m_LookDir, true);
				count--;
				pPlayer->SetSpecialAttackCount(count);
				bShoot = true;
			}
		}
		if (fCooltime > 0.75f)
		{
			pPlayer->ChangeState(PlayerState::Idle);
		}
	}
	
	if (m_LookDir.x == +1)
		str += L"Right";
	else if (m_LookDir.x == -1)
		str += L"Left";
	pPlayer->SetStateName(str);

	
}

void CPlayerStateSpecialAttack::Exit()
{
}
