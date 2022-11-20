#include "framework.h"
#include "CCloud.h"

CCloud::CCloud()
{
	pImgCloud = nullptr;
	m_vecDir = Vector(-1, 0);
	m_fVelocity = 30;
}

CCloud::~CCloud()
{
}

void CCloud::Init()
{
	pImgCloud = RESOURCE->LoadImg(L"BossStage_Cloud", L"Image\\Botanic-Panic_Cloud.png");
}

void CCloud::Update()
{
	m_vecPos += m_vecDir * m_fVelocity * DT;
	if (m_vecPos.x < -0.5f * WINSIZEX)
		m_vecPos.x = 1.5f * WINSIZEX;
}

void CCloud::Render()
{
	RENDER->Image(pImgCloud,
		m_vecPos.x - 0.5f * pImgCloud->GetWidth(),
		m_vecPos.y - 0.5f * pImgCloud->GetHeight(),
		m_vecPos.x + 0.5f * pImgCloud->GetWidth(),
		m_vecPos.y + 0.5f * pImgCloud->GetHeight()
	);
}

void CCloud::Release()
{
}
