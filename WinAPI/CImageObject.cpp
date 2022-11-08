#include "framework.h"
#include "CImageObject.h"

#include "CImage.h"

CImageObject::CImageObject()
{
	m_pImage = nullptr;
	m_bChange = false;
	m_bScreenFixed = false;
	m_vecRenderPos = Vector(0, 0);
}

CImageObject::~CImageObject()
{
}

CImage* CImageObject::GetIamge()
{
    return m_pImage;
}

void CImageObject::SetImage(CImage* pImage)
{
	m_pImage = pImage;
}

void CImageObject::ChangeScale(bool change, Vector scale)
{
	m_bChange = change;
	SetScale(scale);
}

void CImageObject::SetScreenFixed(bool fixed)
{
	m_bScreenFixed = fixed;
}


void CImageObject::Init()
{
}

void CImageObject::Update()
{
	if (m_bScreenFixed)
		m_vecPos=CAMERALOOKAT;
	
}

void CImageObject::Render()
{
	if (nullptr != m_pImage)
	{
		if (!m_bChange)
		{
			RENDER->Image(
				m_pImage,
				m_vecRenderPos.x - (float)m_pImage->GetWidth(), 
				m_vecRenderPos.y - (float)m_pImage->GetHeight(),
				(float)m_pImage->GetWidth(),
				(float)m_pImage->GetHeight());
		}
		
		else
		{
			RENDER->Image(
				m_pImage,
				m_vecPos.x - m_vecScale.x *0.5f,
				m_vecPos.y - m_vecScale.y *0.5f,
				m_vecPos.x+ m_vecScale.x * 0.5f,
				m_vecPos.y + m_vecScale.y * 0.5f);
		}
	}
}

void CImageObject::Release()
{
}
