#include "framework.h"
#include "COverWorldObject.h"

COverWorldObject::COverWorldObject()
{
	pImg = nullptr;
	m_layer = Layer::Obstacle;
	m_strName = L"OverWorldObj";
}

COverWorldObject::~COverWorldObject()
{
}

void COverWorldObject::Init()
{
	pImg = RESOURCE->LoadImg(L"BossStageIcon", L"Image\\Botanic_Panic_OverWorld.png");
	AddCollider(ColliderType::Rect, Vector(200, 200), Vector(0, 0));
}

void COverWorldObject::Update()
{
}

void COverWorldObject::Render()
{
	RENDER->Image(pImg,
		m_vecPos.x - pImg->GetWidth() * 0.5f,
		m_vecPos.y - pImg->GetHeight() * 0.5f,
		m_vecPos.x + pImg->GetWidth() * 0.5f,
		m_vecPos.y + pImg->GetHeight() * 0.5f);
}

void COverWorldObject::Release()
{
}

void COverWorldObject::OnCollisionEnter(CCollider* pOtherCollider)
{
}

void COverWorldObject::OnCollisionStay(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"OverWorldPlayer")
	{
		if (BUTTONDOWN('Z'))
		{
			CAMERA->FadeOut(0.25f);
			DELAYCHANGESCENE(GroupScene::BossStage, 0.25f);
		}
	}
}

void COverWorldObject::OnCollisionExit(CCollider* pOtherCollider)
{
}
