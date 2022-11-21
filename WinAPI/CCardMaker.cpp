#include "framework.h"
#include "CCardMaker.h"

#include "CCard.h"

CCardMaker::CCardMaker()
{
	m_SpecialAttackCount = 0;
	fCoolTime = 0;
	pCard1 = nullptr;
	pCard2 = nullptr;
	pCard3 = nullptr;
	pCard4 = nullptr;
	pCard5 = nullptr;
}

CCardMaker::~CCardMaker()
{
}

void CCardMaker::Init()
{
}

void CCardMaker::Update()
{
	
}

void CCardMaker::Render()
{
}

void CCardMaker::Release()
{
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
