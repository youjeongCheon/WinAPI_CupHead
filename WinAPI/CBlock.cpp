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
	m_blockType = BlockType::Cube;
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

	switch (m_blockType)
	{
	case BlockType::Cube:
		m_pBlock = m_pCube;
		SetPos(1388, 505);
		break;
	case BlockType::Cylinder_platform:
	{
		m_pBlock = m_pCylinder_platform;
		SetPos(2111, 321);
		break;
	}
	case BlockType::Plinth:
		m_pBlock = m_pPlinth;
		SetPos(3019, 453);
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
