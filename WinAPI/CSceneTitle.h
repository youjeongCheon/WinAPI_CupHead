#pragma once
#include "CScene.h"

class CImage;
class CImageObject;
class CAnimator;

class CSceneTitle : public CScene
{
public:
	CSceneTitle();
	virtual ~CSceneTitle();

private:
	CImage* pBackLayer;
	CImageObject* pBackground;

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};