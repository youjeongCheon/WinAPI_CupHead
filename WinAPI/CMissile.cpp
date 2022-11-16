#include "framework.h"
#include "CMissile.h"

#include "CRenderManager.h"
#include "CTimeManager.h"
#include "CEventManager.h"
#include "CCollider.h"

#include "CMissileSpawn.h"

CMissile::CMissile()
{
	m_vecScale = Vector(10, 10);
	m_vecDir = Vector(0, 0);
	m_fVelocity = 1300;
	m_layer = Layer::Missile;
	m_strName = L"미사일";
	m_bExMissile = false;
	bCreate = false;
	
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
	m_pLoopImage = RESOURCE->LoadImg(L"MissileLoop", L"Image\\missile_loop.png");
	m_pDeathImage = RESOURCE->LoadImg(L"MissileDeath", L"Image\\missile_death.png");
	m_pExLoopImage = RESOURCE->LoadImg(L"MissileExLoop", L"Image\\missile_EX_loop.png");
	m_pExDeathImage = RESOURCE->LoadImg(L"MissileExDeath", L"Image\\missile_EX_death.png");

	m_pAnimator = new CAnimator;
	
	m_pAnimator->CreateAnimation(L"LoopUp",	m_pLoopImage, Vector(0.f, 0.f), Vector(300, 300), Vector(300, 0.f), 0.15f, 7,false);
	m_pAnimator->CreateAnimation(L"LoopRightUp", m_pLoopImage, Vector(0.f, 300), Vector(300, 300), Vector(300, 0.f), 0.15f, 7, false);
	m_pAnimator->CreateAnimation(L"LoopRight", m_pLoopImage, Vector(0.f, 600), Vector(300, 300), Vector(300, 0.f), 0.15f, 7, false);
	m_pAnimator->CreateAnimation(L"LoopRightDown", m_pLoopImage, Vector(0.f, 900), Vector(300, 300), Vector(300, 0.f), 0.15f, 7, false);
	m_pAnimator->CreateAnimation(L"LoopDown", m_pLoopImage, Vector(0.f, 1200), Vector(300, 300), Vector(300, 0.f), 0.15f, 7, false);
	m_pAnimator->CreateAnimation(L"LoopLeftUp", m_pLoopImage, Vector(0.f, 1500), Vector(300, 300), Vector(300, 0.f), 0.15f, 7, false);
	m_pAnimator->CreateAnimation(L"LoopLeft", m_pLoopImage, Vector(0.f, 1800), Vector(300, 300), Vector(300, 0.f), 0.15f, 7,false);
	m_pAnimator->CreateAnimation(L"LoopLeftDown", m_pLoopImage, Vector(0.f, 2100), Vector(300, 300), Vector(300, 0.f), 0.15f, 7, false);

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

	if (bCreate == false)
	{
		CreateSpawn(m_vecPos);
		bCreate = true;
	}
	
	wstring str = L"";

	if (m_bExMissile == false)
		str += L"Loop";

	else
		str += L"ExLoop";

	if (m_vecDir.x >0)
		str += L"Right";
	else if (m_vecDir.x <0)
		str += L"Left";
	if (m_vecDir.y > 0)
		str += L"Down";
	else if (m_vecDir.y < 0)
		str += L"Up";

	//화면밖으로 나갈경우 삭제
	if (m_vecPos.x < CAMERALOOKAT.x - WINSIZEX * 0.5f ||
		m_vecPos.x > CAMERALOOKAT.x + WINSIZEX*0.5f ||
		m_vecPos.y < CAMERALOOKAT.y - WINSIZEY * 0.5f ||
		m_vecPos.y > CAMERALOOKAT.y + WINSIZEY * 0.5f
		)
	{
		DELETEOBJECT(this);
		Logger::Debug(L"미사일이 화면밖으로 나가 삭제");
	}
		

	m_pAnimator->Play(str, false);
}

void CMissile::Render()
{
}

void CMissile::Release()
{
}

void CMissile::OnCollisionEnter(CCollider* pOtherCollider)
{
	//Logger::Debug(L"미사일이 충돌체와 부딪혀 사라집니다.");

	//DELETEOBJECT(this);
}

void CMissile::CreateSpawn(Vector pos)
{
	CMissileSpawn* pSpawn = new CMissileSpawn();
	pSpawn->SetPos(pos);
	ADDOBJECT(pSpawn);
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

bool CMissile::GetExMissile()
{
	return m_bExMissile;
}
