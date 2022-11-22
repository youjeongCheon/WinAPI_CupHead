#pragma once
#include "CGameObject.h"

class CCard;

class CCardMaker : public CGameObject
{
public:
	CCardMaker();
	virtual~CCardMaker();

private:
	int	m_SpecialAttackCount;
	float fCoolTime;

	vector<CCard*> vCard;

	CCard* pCard1;
	CCard* pCard2;
	CCard* pCard3;
	CCard* pCard4;
	CCard* pCard5;

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void ChangeCard(int num);
public:
	void SetSpecialAttackCount(int count);
	void CreateCard();

};

