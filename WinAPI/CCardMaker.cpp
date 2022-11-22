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
	ChangeCard(0);
}

void CCardMaker::Update()
{
	switch (m_SpecialAttackCount)
	{
	case 0:
		fCoolTime += DT;
		if (fCoolTime > 6.0f)
			ChangeCard(1);
		break;
	case 1:
		fCoolTime += DT;
		if (fCoolTime > 6.0f)
			ChangeCard(2);
		break;
	case 2:
		fCoolTime += DT;
		if (fCoolTime > 6.0f)
			ChangeCard(3);
		break;
	case 3:
		fCoolTime += DT;
		if (fCoolTime > 6.0f)
			ChangeCard(4);
		break;
	case 4:
		fCoolTime += DT;
		if (fCoolTime > 6.0f)
			ChangeCard(1);
		break;
	case 5:
		fCoolTime += DT;
		
		break;
	}
}

void CCardMaker::Render()
{
}

void CCardMaker::Release()
{
}

void CCardMaker::ChangeCard(int num)
{
	m_SpecialAttackCount = num;
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

void CCardMaker::SetSpecialAttackCount(int count)
{
	m_SpecialAttackCount = count;
}

void CCardMaker::CreateCard()
{
	CCard* pCard = new CCard();
	ADDOBJECT(pCard);
}
