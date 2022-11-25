#include "framework.h"
#include "CLayer.h"

CLayer::CLayer()
{
	m_vecAbsolutePos = Vector(0, 0);
	m_vecRenderPos = Vector(0, 0);
	m_bScreenFixed = true;
}

CLayer::~CLayer()
{
}

void CLayer::SetScreenFixed(bool fixed)
{
	m_bScreenFixed = fixed;
}

void CLayer::GameObjectInit()
{
}

void CLayer::GameObjectUpdate()
{
}

void CLayer::GameObjectRender()
{
}

void CLayer::GameObjectRelease()
{
}
