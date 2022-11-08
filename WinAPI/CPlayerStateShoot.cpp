#include "framework.h"
#include "CPlayerStateShoot.h"

#include "CPlayer.h"
#include "CState.h"
#include "CMissile.h"

CPlayerStateShoot::~CPlayerStateShoot()
{
}

void CPlayerStateShoot::Enter()
{
	fCooltime = 0;
	bShoot = false;
}

void CPlayerStateShoot::Update()
{
	m_LookDir = pPlayer->GetLookDir();
	m_vecMissilePos = pPlayer->GetPos();
	float result = m_LookDir.x*1 + m_LookDir.y * (-3);

	wstring str = L"Shoot";	
	
	switch ((int)result)
	{
	case 10:
		str += L"RightDiagonalUp";
		m_vecMissilePos.x += 60;
		m_vecMissilePos.y -= 40;
		m_LookDir = Vector(1, -1);
		break;
	case 8:
		str += L"LeftDiagonalUp";
		m_vecMissilePos.x -= 60;
		m_vecMissilePos.y -= 40;
		m_LookDir = Vector(-1, -1);
		break;
	case 7:
		str += L"RightUp";
		m_LookDir.x = 0;
		m_vecMissilePos.x += 10;
		m_vecMissilePos.y -= 80;
		break;
	case 5:
		str += L"LeftUp";
		m_LookDir.x = 0;
		m_vecMissilePos.x -= 10;
		m_vecMissilePos.y -= 80;
		break;
	case 1:
		str += L"Right";
		m_LookDir.y = 0;
		m_vecMissilePos.x += 60;
		break;
	case -1:
		str += L"Left";
		m_LookDir.y = 0;
		m_vecMissilePos.x -= 60;
		break;
	case -5:
		str += L"RightDown";
		m_vecMissilePos.x += 10;
		m_vecMissilePos.y += 80;
		m_LookDir.x = 0;
		break;
	case -7:
		str += L"LeftDown";
		m_vecMissilePos.x -= 10;
		m_vecMissilePos.y += 80;
		m_LookDir.x = 0;
		break;
	case -8:
		str += L"RightDiagonalDown";
		m_vecMissilePos.x += 60;
		m_vecMissilePos.y += 40;
		m_LookDir = Vector(1, +1);
		break;
	case -10:
		str += L"LeftDiagonalDown";
		m_vecMissilePos.x -= 60;
		m_vecMissilePos.y += 40;
		m_LookDir = Vector(-1, +1);
		break;
	}
	pPlayer->SetStateName(str);

	pPlayer->CreateMissile(m_vecMissilePos, m_LookDir);
	
	fCooltime += DT;
	if (fCooltime>0.3f)
	{
		if(BUTTONSTAY('C'))
			pPlayer->ChangeState(PlayerState::Aim);
		else
			pPlayer->ChangeState(PlayerState::Idle);
	}
}

void CPlayerStateShoot::Exit()
{
}
