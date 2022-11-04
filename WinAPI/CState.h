#pragma once

class CState
{
private:
	wstring m_curStateName;

public:
	CState();
	virtual ~CState();

public:
	void SetState(wstring stateName);

	virtual void Enter() = 0;
	virtual void Update() = 0;
	virtual void Exit() = 0;
};

