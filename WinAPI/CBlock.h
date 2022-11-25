#pragma once
#include "CGameObject.h"

class CImage;

enum class BlockType { Cube, Cylinder_platform, Plinth, Cylinder2,Exit_Door};
class CBlock : public CGameObject
{
public:
	CBlock();
	virtual~CBlock();

private:
	BlockType m_blockType;

	CImage* m_pBlock;
	CImage* m_pCube;
	CImage* m_pCylinder_platform;
	CImage* m_pPlinth;
	CImage* m_pEixitDoor;
	CImage* m_pCylinder2;

public:
	void SetBlockType(BlockType blockType);

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

