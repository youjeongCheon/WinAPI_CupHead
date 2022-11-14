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
	fCooltime += DT;
	m_LookDir = pPlayer->GetLookDir();
	m_vecMissilePos = pPlayer->GetPos();
	if (bShoot == false)
	{
		if (fCooltime >= 0.4f)
		{
			pPlayer->CreateMissile(m_vecMissilePos, m_LookDir, true);
			bShoot = true;
		}
	}
	wstring str = L"SpecialAttack";
	if (fCooltime > 0.75f)
	{
		pPlayer->ChangeState(PlayerState::Idle);
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
