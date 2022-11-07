#pragma once

class CPlayer;

class CSceneTutorial : public CScene
{
public:
	CSceneTutorial();
	virtual ~CSceneTutorial();

private:
	CPlayer* pPlayer;

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};


