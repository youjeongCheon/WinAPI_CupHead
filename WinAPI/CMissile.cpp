#include "framework.h"
#include "CMissile.h"

#include "CRenderManager.h"
#include "CTimeManager.h"
#include "CEventManager.h"
#include "CCollider.h"

CMissile::CMissile()
{
	m_vecScale = Vector(10, 10);
	m_vecDir = Vector(0, 0);
	m_fVelocity = 1000;
	m_layer = Layer::Missile;
	m_strName = L"미사일";
	m_bExMissile = false;

	m_pSpawnImage = nullptr;
	m_pLoopImage = nullptr;
	m_pDeathImage = nullptr;
	m_pExLoopImage = nullptr;
	m_pExDeathImage = nullptr;
	
}

CMissile::~CMissile()
{
}

void CMissile::Init()
{
	m_pSpawnImage = RESOURCE->LoadImg(L"MissileSpawn", L"Image\\missile_spawn.png");
	m_pLoopImage = RESOURCE->LoadImg(L"MissileLoop", L"Image\\missile_loop.png");
	m_pDeathImage = RESOURCE->LoadImg(L"MissileDeath", L"Image\\missile_death.png");
	m_pExLoopImage = RESOURCE->LoadImg(L"MissileExLoop", L"Image\\missile_EX_loop.png");
	m_pExDeathImage = RESOURCE->LoadImg(L"MissileExDeath", L"Image\\missile_EX_death.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Spawn", m_pSpawnImage, Vector(0.f, 0.f), Vector(150, 150), Vector(150, 0.f), 0.05f, 4,false);
	m_pAnimator->CreateAnimation(L"LoopRight", m_pLoopImage, Vector(0.f, 0.f), Vector(200.f, 100), Vector(200.f, 0.f), 0.05f, 7,false);
	m_pAnimator->CreateAnimation(L"LoopLeft", m_pLoopImage, Vector(0.f, 100), Vector(200.f, 100), Vector(200.f, 0.f), 0.05f, 7,false);
	m_pAnimator->CreateAnimation(L"Death", m_pDeathImage, Vector(0.f, 0.f), Vector(300, 300), Vector(300, 0.f), 0.05f, 9,false);
	m_pAnimator->CreateAnimation(L"ExLoopRight", m_pExLoopImage, Vector(0.f, 0.f), Vector(500, 200.f), Vector(500, 0.f), 0.05f, 8);
	m_pAnimator->CreateAnimation(L"ExLoopLeft", m_pExLoopImage, Vector(0.f, 200), Vector(500, 200.f), Vector(500, 0.f), 0.05f, 8);
	m_pAnimator->CreateAnimation(L"ExDeath", m_pExDeathImage, Vector(0.f, 0.f), Vector(550, 550), Vector(550, 0.f), 0.05f, 9,false);

	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Circle, Vector(10, 10), Vector(0, 0));
}

void CMissile::Update()
{
	m_vecPos += m_vecDir  * m_fVelocity * DT;

	wstring str = L"";

	if (m_bExMissile == false)
		str += L"Loop";

	else
		str += L"ExLoop";

	if (m_vecDir.x >0)
		str += L"Right";
	else if (m_vecDir.x <0)
		str += L"Left";

	// 화면밖으로 나갈경우 삭제
	if (m_vecPos.x < 0 ||
		m_vecPos.x > WINSIZEX ||
		m_vecPos.y < 0 ||
		m_vecPos.y > WINSIZEY)
		DELETEOBJECT(this);

	m_pAnimator->Play(str, false);
}

void CMissile::Render()
{
	RENDER->FrameCircle(
		m_vecPos.x,
		m_vecPos.y,
		m_vecScale.x);
}

void CMissile::Release()
{
}

void CMissile::OnCollisionEnter(CCollider* pOtherCollider)
{
	Logger::Debug(L"미사일이 충돌체와 부딪혀 사라집니다.");
	DELETEOBJECT(this);
}

void CMissile::SetDir(Vector dir)
{
	m_vecDir = dir.Normalized();
}

void CMissile::SetVelocity(float velocity)
{
	m_fVelocity = velocity;
}

void CMissile::SetExMissile(bool bExMissile)
{
	m_bExMissile = bExMissile;
}
