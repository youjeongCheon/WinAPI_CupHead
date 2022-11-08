#include "framework.h"
#include "CMissileSpawn.h"

CMissileSpawn::CMissileSpawn()
{
	m_pSpawnImage = nullptr;
	m_pAnimator = nullptr;
}

CMissileSpawn::~CMissileSpawn()
{
}

void CMissileSpawn::Init()
{
	m_pSpawnImage = RESOURCE->LoadImg(L"MissileSpawn", L"Image\\missile_spawn.png");
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"Spawn", m_pSpawnImage, Vector(0.f, 0.f), Vector(150, 150), Vector(150, 0.f), 0.05f, 4, false);
	AddComponent(m_pAnimator);
	Logger::Debug(L"Spawn 생성");
}

void CMissileSpawn::Update()
{
	fCoolTime += DT;
	
	m_pAnimator->Play(L"Spawn", false);

	if (fCoolTime > 0.2)
	{
		DELETEOBJECT(this);
		Logger::Debug(L"Spawn 제거");
	}
		

}

void CMissileSpawn::Render()
{
}

void CMissileSpawn::Release()
{
}
