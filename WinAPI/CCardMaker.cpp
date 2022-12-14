#include "framework.h"
#include "CCardMaker.h"

#include "CCard.h"

CCardMaker::CCardMaker()
{
	m_SpecialAttackCount = 0;
	fCoolTime = 0;
}

CCardMaker::~CCardMaker()
{
}

void CCardMaker::Init()
{
	for (int i = 0; i < 5; i++)
	{
		vCard.push_back(new CCard());
		ADDOBJECT(vCard[i]);
		vCard[i]->SetPos(WINSIZEX * 0.05f + 55 + 30 * i, WINSIZEY * 0.95f);
	}
}

void CCardMaker::Update()
{
	ChangeCard(GETSPECIALATTACK);
}

void CCardMaker::Render()
{
}

void CCardMaker::Release()
{
}

void CCardMaker::ChangeCard(int num)
{
	SETSPECIALATTACK(num);
	// "Front"
	for (int i = 0; i < num; i++)
		vCard[i]->Settingcard(false, false);
	// "Back"
	if(num!=5)
		vCard[num]->Settingcard(false, true);
	// "Null"
	for (int i = num+1; i < 5; i++)
		vCard[i]->Settingcard(true, false);
	fCoolTime = 0;
}