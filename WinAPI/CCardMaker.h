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

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void ChangeCard(int num);

};

