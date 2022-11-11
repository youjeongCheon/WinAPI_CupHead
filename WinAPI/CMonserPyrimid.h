#pragma once
#include "CMonster.h"
class CMonserPyrimid : public CMonster
{
public:
	CMonserPyrimid();
	virtual ~CMonserPyrimid();
private:
	CImage* m_pPyramid;
	CImage* m_pHitPyramid;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

};

