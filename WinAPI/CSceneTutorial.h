#pragma once

class CPlayer;
class CImage;
class CSound;
class CImageObject;
class CParrySphere;

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

	CSound* pBGM;
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


