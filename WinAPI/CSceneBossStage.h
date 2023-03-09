#pragma once
#include "CScene.h"

class CPlayer;
class CHPObject;
class CCardMaker;
class CImageObject;
class CSound;

class CSceneBossStage : public CScene
{
public:
	CSceneBossStage();
	virtual ~CSceneBossStage();

private:
	CPlayer* pPlayer;
	CHPObject* pHP;
	CCardMaker* pCardMaker;
	CSound* pBGM;
private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

