#include "framework.h"
#include "CPotatoMissile.h"

CPotatoMissile::CPotatoMissile()
{
	m_pImgMissile = nullptr;
	m_pAnimator = nullptr;
	m_vecDir = Vector(-1, 0);
	m_vecPos = Vector(WINSIZEX * 0.8-200, WINSIZEY * 0.75);
	m_fVelocity = 800;
}

CPotatoMissile::~CPotatoMissile()
{
}

void CPotatoMissile::Init()
{
	m_pImgMissile= RESOURCE->LoadImg(L"Potato", L"Image\\Botanic_Panic_Potato.png");
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"PotatoMissile", m_pImgMissile, Vector(1, 6219), Vector(134, 138), Vector(135, 0), 0.1f, 8);
	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Circle, Vector(50, 50), Vector(0, 0));
}

void CPotatoMissile::Update()
{
	m_pAnimator->Play(L"PotatoMissile");

	m_vecPos += m_vecDir * m_fVelocity * DT;

	//화면밖으로 나갈경우 삭제
	if (m_vecPos.x < CAMERALOOKAT.x - WINSIZEX * 0.5f ||
		m_vecPos.x > CAMERALOOKAT.x + WINSIZEX * 0.5f ||
		m_vecPos.y < CAMERALOOKAT.y - WINSIZEY * 0.5f ||
		m_vecPos.y > CAMERALOOKAT.y + WINSIZEY * 0.5f
		)
	{
		DELETEOBJECT(this);
		Logger::Debug(L"미사일이 화면밖으로 나가 삭제");
	}
}

void CPotatoMissile::Render()
{
}

void CPotatoMissile::Release()
{
}
