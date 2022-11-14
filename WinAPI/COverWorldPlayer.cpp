#include "framework.h"
#include "COverWorldPlayer.h"


COverWorldPlayer::COverWorldPlayer()
{
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Player;
	m_strName = L"OverWorldPlayer";

	m_pImage = nullptr;
	m_pImageLeft = nullptr;

	m_vecMoveDir = Vector(0, 0);
	m_vecLookDir = Vector(0, -1);
	m_bIsMove = false;
}

COverWorldPlayer::~COverWorldPlayer()
{
}

void COverWorldPlayer::Init()
{
	m_pImage = RESOURCE->LoadImg(L"OverworldPlayer", L"Image\\Cuphead_Overworld.png");
	m_pImageLeft = RESOURCE->LoadImg(L"OverworldPlayerLeft", L"Image\\Cuphead_Overworld_left.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"IdleUp", m_pImage, Vector(0, 0.f), Vector(103.f, 113.f), Vector(103.f, 0.f), 0.1f, 4);
	m_pAnimator->CreateAnimation(L"MoveUp", m_pImage, Vector(412, 0.f), Vector(103.f, 113.f), Vector(103.f, 0.f), 0.05f, 12);
	m_pAnimator->CreateAnimation(L"IdleRightUp", m_pImage, Vector(0, 113), Vector(103.f, 113.f), Vector(103.f, 0.f), 0.1f, 4);
	m_pAnimator->CreateAnimation(L"MoveRightUp", m_pImage, Vector(412, 113), Vector(103.f, 113.f), Vector(103.f, 0.f), 0.05f, 11);
	m_pAnimator->CreateAnimation(L"IdleRight", m_pImage, Vector(0, 226), Vector(103.f, 113.f), Vector(103.f, 0.f), 0.1f, 4);
	m_pAnimator->CreateAnimation(L"MoveRight", m_pImage, Vector(412, 339), Vector(103.f, 113.f), Vector(103.f, 0.f), 0.05f, 10);
	m_pAnimator->CreateAnimation(L"IdleRightDown", m_pImage, Vector(0, 452), Vector(103.f, 113.f), Vector(103.f, 0.f), 0.1f, 4);
	m_pAnimator->CreateAnimation(L"MoveRightDown", m_pImage, Vector(412, 452), Vector(103.f, 113.f), Vector(103.f, 0.f), 0.05f, 12);
	m_pAnimator->CreateAnimation(L"IdleDown", m_pImage, Vector(0, 565), Vector(103.f, 113.f), Vector(103.f, 0.f), 0.1f, 9);
	m_pAnimator->CreateAnimation(L"MoveDown", m_pImage, Vector(0.f, 678), Vector(103.f, 113.f), Vector(103.f, 0.f), 0.05f, 13);

	m_pAnimator->CreateAnimation(L"IdleLeftUp", m_pImageLeft, Vector(0, 0), Vector(103.f, 113.f), Vector(103.f, 0.f), 0.1f, 4);
	m_pAnimator->CreateAnimation(L"MoveLeftUp", m_pImageLeft, Vector(412, 0), Vector(103.f, 113.f), Vector(103.f, 0.f), 0.05f, 11);
	m_pAnimator->CreateAnimation(L"IdleLeft", m_pImageLeft, Vector(0, 113), Vector(103.f, 113.f), Vector(103.f, 0.f), 0.1f, 4);
	m_pAnimator->CreateAnimation(L"MoveLeft", m_pImageLeft, Vector(412, 226), Vector(103.f, 113.f), Vector(103.f, 0.f), 0.05f, 10);
	m_pAnimator->CreateAnimation(L"IdleLeftDown", m_pImageLeft, Vector(0, 339), Vector(103.f, 113.f), Vector(103.f, 0.f), 0.1f, 4);
	m_pAnimator->CreateAnimation(L"MoveLeftDown", m_pImageLeft, Vector(412, 339), Vector(103.f, 113.f), Vector(103.f, 0.f), 0.05f, 12);
	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(40, 60), Vector(0, 0));
}

void COverWorldPlayer::Update()
{
	m_bIsMove = false;

	if (BUTTONSTAY(VK_LEFT))
	{
		m_vecPos.x -= m_fSpeed * DT;
		m_bIsMove = true;
		m_vecMoveDir.x = -1;
	}
	else if (BUTTONSTAY(VK_RIGHT))
	{
		m_vecPos.x += m_fSpeed * DT;
		m_bIsMove = true;
		m_vecMoveDir.x = +1;
	}
	else
	{
		m_vecMoveDir.x = 0;
	}

	if (BUTTONSTAY(VK_UP))
	{
		m_vecPos.y -= m_fSpeed * DT;
		m_bIsMove = true;
		m_vecMoveDir.y = +1;
	}
	else if (BUTTONSTAY(VK_DOWN))
	{
		m_vecPos.y += m_fSpeed * DT;
		m_bIsMove = true;
		m_vecMoveDir.y = -1;
	}
	else
	{
		m_vecMoveDir.y = 0;
	}

	AnimatorUpdate();
}

void COverWorldPlayer::Render()
{
}

void COverWorldPlayer::Release()
{
}

void COverWorldPlayer::AnimatorUpdate()
{
	if (m_vecMoveDir.Length() > 0)
		m_vecLookDir = m_vecMoveDir;

	wstring str = L"";

	if (m_bIsMove)	str += L"Move";
	else			str += L"Idle";

	if (m_vecLookDir.x > 0) str += L"Right";
	else if (m_vecLookDir.x < 0) str += L"Left";

	if (m_vecLookDir.y > 0) str += L"Up";
	else if (m_vecLookDir.y < 0) str += L"Down";

	m_pAnimator->Play(str, false);
}

void COverWorldPlayer::OnCollisionEnter(CCollider* pOtherCollider)
{
}

void COverWorldPlayer::OnCollisionStay(CCollider* pOtherCollider)
{
}

void COverWorldPlayer::OnCollisionExit(CCollider* pOtherCollider)
{
}
