#include "framework.h"
#include "CBlock.h"

#include "CGameObject.h"

CBlock::CBlock()
{
	m_pBlock = nullptr;
	m_pCube = nullptr;
	m_pCylinder_platform = nullptr;
	m_pPyramid = nullptr;
	m_pPlinth = nullptr;
	m_blockType = BlockType::Cube;
	m_strName = L"block";
	m_layer = Layer::Block;
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
	m_pCube =				RESOURCE->LoadImg(L"BlockCube", L"Image\\tutorial_cube.png");
	m_pCylinder_platform =	RESOURCE->LoadImg(L"BlockCylinder_platform", L"Image\\tutorial_cylinder_and_platform.png");
	m_pPyramid =			RESOURCE->LoadImg(L"BlockPyramid", L"Image\\tutorial_pyramid_topper.png");
	m_pPlinth =				RESOURCE->LoadImg(L"BlockPlinth", L"Image\\tutorial_plynth.png");

	switch (m_blockType)
	{
	case BlockType::Cube:
		m_pBlock = m_pCube;
		SetPos(1388, 505);
		AddCollider(ColliderType::Rect, Vector(140, 148), Vector(0, 0));
		break;
	case BlockType::Cylinder_platform:
	{
		m_pBlock = m_pCylinder_platform;
		SetPos(2137, 267);
		AddCollider(ColliderType::Rect, Vector(400, 43), Vector(0, 0));
		/*CBlock* pNullBlock1 = new CBlock();
		pNullBlock1->SetBlockType(BlockType::Null);
		pNullBlock1->GetCollider()->S*/
		break;
	}
	case BlockType::Pyramid:
		AddCollider(ColliderType::Rect, Vector(182.98, 147.61), Vector(0, 0));
		SetPos(1388, 505);
		break;
	case BlockType::Plinth:
		AddCollider(ColliderType::Rect, Vector(182.98, 147.61), Vector(0, 0));
		SetPos(1388, 505);
		break;
	case BlockType::Null:

		break;

	}


	

}

void CBlock::Update()
{

}

void CBlock::Render()
{
	if (!(BlockType::Null == m_blockType))
	{
		RENDER->Image(m_pBlock,
			m_vecPos.x - m_pBlock->GetWidth() * 0.5f,
			m_vecPos.y - m_pBlock->GetHeight() * 0.5f,
			m_vecPos.x + m_pBlock->GetWidth() * 0.5f,
			m_vecPos.y + m_pBlock->GetHeight() * 0.5f
		);
	}
}

void CBlock::Release()
{
}

void CBlock::AnimatorUpdate()
{
}

void CBlock::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"플레이어")
	{
		Logger::Debug(L"충돌진입");
	}
	
}

void CBlock::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CBlock::OnCollisionExit(CCollider* pOtherCollider)
{
}
