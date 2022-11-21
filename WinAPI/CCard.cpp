#include "framework.h"
#include "CCard.h"

CCard::CCard()
{
	m_pAnimator = nullptr;
	m_pImgCard = nullptr;
    bDeleteCard = true;
}

CCard::~CCard()
{
}

void CCard::SetDeleteCard(bool bDelete)
{
    bDeleteCard = bDelete;
}

void CCard::Init()
{
	m_pImgCard = RESOURCE->LoadImg(L"Card", L"Image\\Card.png");
    m_pAnimator = new CAnimator;
    m_pAnimator->CreateAnimation(L"Null", m_pImgCard, Vector(0, 0), Vector(1, 1), Vector(1, 0), 0.1f, 1, false);
    m_pAnimator->CreateAnimation(L"Front", m_pImgCard, Vector(0, 0), Vector(30, 40), Vector(30, 0), 0.1f, 1, false);
    m_pAnimator->CreateAnimation(L"Back", m_pImgCard, Vector(30, 0), Vector(30, 40), Vector(30, 0), 1.0f, 6);
    AddComponent(m_pAnimator);
}

void CCard::Update()
{
    if (bDeleteCard == true)
    {
        m_pAnimator->Play(L"Null");
        fCoolTime = 0;
    }
    else
    {
        fCoolTime += DT;

        if (fCoolTime < 6.0f)
            m_pAnimator->Play(L"Back");
        else
            m_pAnimator->Play(L"Front");
    }
    
}

void CCard::Render()
{
}

void CCard::Release()
{
}
