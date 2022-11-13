#pragma once

class CPlayer;
class CImage;
class CImageObject;
class CParryObject;

class CSceneTutorial : public CScene
{
public:
	CSceneTutorial();
	virtual ~CSceneTutorial();

private:
	CPlayer* pPlayer;

	CImage* pBackLayer;
	CImage* pFrontLayer;

	CImageObject* pBackground;
	CImageObject* pFrontground;

	int parryNum;

public:
	int GetParryNum();
	void SetParryNum(int num);

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};


