#pragma once
#include "CGameObject.h"
class COnionMissileEffect :
    public CGameObject
{
public:
	COnionMissileEffect();
	virtual ~COnionMissileEffect();

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	float timer = 0.7f;
};

