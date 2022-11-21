#pragma once
#include "CGameObject.h"
class CHPObject :  public CGameObject
{
public:
	CHPObject();
	virtual ~CHPObject();

private:
	int m_hp;
	CImage* m_pImgHP;
	CAnimator* m_pAnimator;

	wstring str;

public:
	int GetHP();
	void SetHP(int hp);

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

};

