#pragma once
#include "CScene.h"

class COverWorldPlayer;
class CImage;
class CImageObject;

class CSceneOverWorld : public CScene
{
public:
	CSceneOverWorld();
	virtual~CSceneOverWorld();

private:
	COverWorldPlayer* pPlayer;

	CImage* pBackLayer;
	CImageObject* pBackground;

	CImage* pTopper;
	CImageObject* pTopperObject;

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

