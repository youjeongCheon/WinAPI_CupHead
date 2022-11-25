#include "framework.h"
#include "CPotatoParry.h"

CPotatoParry::CPotatoParry()
{
	m_pImgParry = nullptr;
	m_pAnimator = nullptr;
	m_vecDir = Vector(-1, 0);
	m_vecPos = Vector(WINSIZEX * 0.8 - 200, WINSIZEY * 0.75);
	m_fVelocity = 800;
}

CPotatoParry::~CPotatoParry()
{
}

void CPotatoParry::Init()
{
	CParryObject::Init();

	m_pImgParry = RESOURCE->LoadImg(L"Potato", L"Image\\Botanic_Panic_Potato.png");
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"PotatoParry", m_pImgParry, Vector(1081, 6219), Vector(132, 139), Vector(133, 0), 0.1f, 4);
	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Circle, Vector(50, 50), Vector(0, 0));
}

void CPotatoParry::Update()
{
	m_pAnimator->Play(L"PotatoParry");

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

	if (GetParry() == false)
		DELETEOBJECT(this);
}

void CPotatoParry::Render()
{
}

void CPotatoParry::Release()
{
}
