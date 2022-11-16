#include "framework.h"
#include "CPlayerStateTakeHit.h"

#include "CPlayer.h"
#include "CState.h"

CPlayerStateTakeHit::~CPlayerStateTakeHit()
{
}

void CPlayerStateTakeHit::Enter()
{
	fCooltime = 0;
}

void CPlayerStateTakeHit::Update()
{
	fCooltime += DT;
	wstring str = L"TakeHit";
	if (fCooltime > 0.6f)
	{
		if (pPlayer->ActGravity())
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

void CPlayerStateTakeHit::Exit()
{
}
