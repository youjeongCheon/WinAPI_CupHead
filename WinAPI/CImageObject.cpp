#include "framework.h"
#include "CImageObject.h"

#include "CImage.h"

CImageObject::CImageObject()
{
	m_pImage = nullptr;
	m_bChange = false;
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


void CImageObject::Init()
{
}

void CImageObject::Update()
{
}

void CImageObject::Render()
{
	if (nullptr != m_pImage)
	{
		if (!m_bChange)
		{
			RENDER->Image(
				m_pImage,
				0,
				0,
				(float)m_pImage->GetWidth(),
				(float)m_pImage->GetHeight());
		}
		
		else
		{
			RENDER->Image(
				m_pImage,
				0,
				0,
				m_vecScale.x,
				m_vecScale.y);
		}
	}
}

void CImageObject::Release()
{
}
