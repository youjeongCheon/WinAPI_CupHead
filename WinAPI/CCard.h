#pragma once
#include "CGameObject.h"
class CCard : public CGameObject
{
public:
	CCard();
	virtual ~CCard();

	void SetDeleteCard(bool bDelete);

private:
	CImage* m_pImgCard;
	CAnimator* m_pAnimator;

	bool bDeleteCard;
	float fCoolTime;

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;


};

