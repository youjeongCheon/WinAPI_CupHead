#pragma once
#include "CGameObject.h"
class CCard : public CGameObject
{
public:
	CCard();
	virtual ~CCard();

	void Settingcard(bool bDelete, bool bCreate);
private:
	CImage* m_pImgCard;
	CAnimator* m_pAnimator;

	bool bDeleteCard;
	bool bCreateCard;
	float fCoolTime;

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;


};

