#include "framework.h"
#include "CBlock.h"

#include "CGameObject.h"
#include "CCollider.h"

CBlock::CBlock()
{
	m_pBlock = nullptr;
	m_pCube = nullptr;
	m_pCylinder_platform = nullptr;
	m_pPlinth = nullptr;
	m_pCylinder2 = nullptr;
	m_pEixitDoor = nullptr;
	m_blockType = BlockType::Cube;
	m_layer = Layer::Obstacle;
	m_strName = L"block";
}

CBlock::~CBlock()
{
}

void CBlock::SetBlockType(BlockType blockType)
{
	m_blockType = blockType;
}

void CBlock::Init()
{
	m_pCube = RESOURCE->LoadImg(L"BlockCube", L"Image\\tutorial_cube.png");
	m_pCylinder_platform = RESOURCE->LoadImg(L"BlockCylinder_platform", L"Image\\tutorial_cylinder_and_platform.png");
	m_pPlinth = RESOURCE->LoadImg(L"BlockPlinth", L"Image\\tutorial_plynth.png");
	m_pCylinder2 = RESOURCE->LoadImg(L"BlockCylinder2", L"Image\\tutorial_cylinder_2.png");
	m_pEixitDoor = RESOURCE->LoadImg(L"BlockExitDoor", L"Image\\tutorial_exit_door.png");
	switch (m_blockType)
	{
	case BlockType::Cube:
		m_pBlock = m_pCube;
		SetPos(1388, 505);
		break;
	case BlockType::Cylinder_platform:
		m_pBlock = m_pCylinder_platform;
		SetPos(2111, 321);
		break;
	case BlockType::Plinth:
		m_pBlock = m_pPlinth;
		SetPos(3019, 453);
		break;
	case BlockType::Cylinder2:
		m_pBlock = m_pCylinder2;
		SetPos(4020, 431);
		break;
	case BlockType::Exit_Door:
		m_pBlock = m_pEixitDoor;
		SetPos(5000,487);
		m_strName = L"ExitDoor";
		AddCollider(ColliderType::Rect, Vector(120, 171), Vector(0, 0));
		break;
	}


}

void CBlock::Update()
{

}

void CBlock::Render()
{
	RENDER->Image(m_pBlock,
		m_vecPos.x - m_pBlock->GetWidth() * 0.5f,
		m_vecPos.y - m_pBlock->GetHeight() * 0.5f,
		m_vecPos.x + m_pBlock->GetWidth() * 0.5f,
		m_vecPos.y + m_pBlock->GetHeight() * 0.5f);
}

void CBlock::Release()
{
}

void CBlock::OnCollisionEnter(CCollider* pOtherCollider)
{
	
}

void CBlock::OnCollisionStay(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"플레이어")
	{
		if (BUTTONDOWN('Z'))
		{
			CAMERA->FadeOut(0.25f);
			CHANGESCENE(GroupScene::Stage01);
		}
	}
}

void CBlock::OnCollisionExit(CCollider* pOtherCollider)
{
}
