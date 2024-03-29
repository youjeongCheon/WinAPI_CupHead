#pragma once
#include "CGameObject.h"

class CImage;
class CAnimator;
class CSceneTutorial;

class CParrySphere : public CGameObject
{
public:
	CParrySphere();
	virtual ~CParrySphere();

private:
	CImage* m_pImage;
	CImage* m_pSphere;
	CImage* m_pPinkSphere;
	CImage* m_pParrySpikle;

	CAnimator* m_pAnimator;

	CSceneTutorial* pSceneTutorial;

	int m_num;
	int parryNum; // Tutorial parryObject ��ȣ 
	bool bParry;
	bool bParryExit;

private:
	void CreateSpikle();
public:
	void SetNum(int num);
	void SetParryNum();
	void SelectNum();
	void SetScene(CSceneTutorial* scene);

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;

};

