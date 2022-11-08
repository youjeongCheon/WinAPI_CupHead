#pragma once

class CPlayer;
class CImage;
class CImageObject;

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


private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};


