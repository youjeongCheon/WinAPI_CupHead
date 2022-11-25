#include "framework.h"
#include "CCard.h"

CCard::CCard()
{
    m_layer = Layer::FrontLayer;
	m_pAnimator = nullptr;
	m_pImgCard = nullptr;
    bDeleteCard = true;
    bCreateCard = false;
    fCoolTime = 0;
}

CCard::~CCard()
{
}

void CCard::Settingcard(bool bDelete, bool bCreate)
{
    bDeleteCard = bDelete;
    bCreateCard = bCreate;
}

void CCard::Init()
{
	m_pImgCard = RESOURCE->LoadImg(L"Card", L"Image\\Card.png");
    m_pAnimator = new CAnimator;
    m_pAnimator->CreateAnimation(L"Null", m_pImgCard, Vector(0, 0), Vector(1, 1), Vector(1, 0), 0.1f, 1, false);
    m_pAnimator->CreateAnimation(L"Front", m_pImgCard, Vector(0, 0), Vector(30, 40), Vector(30, 0), 0.1f, 1, false);
    m_pAnimator->CreateAnimation(L"Back", m_pImgCard, Vector(30, 0), Vector(30, 40), Vector(30, 0), 1.5f, 6);
    AddComponent(m_pAnimator);
}

void CCard::Update()
{

    
    if (bDeleteCard == true)
    {
        m_pAnimator->Play(L"Null");
        fCoolTime = 0;
    }
    else if (bCreateCard == true) //&&(bDeleteCard == false)
    {
        fCoolTime += DT;
        m_pAnimator->Play(L"Back");
        if (fCoolTime > 9.0f)
        {
            bCreateCard = false;
            int count = GETSPECIALATTACK;
            count++;
            SETSPECIALATTACK(count);
        }
    }
    else // (bDeleteCard == false)&&(bCreateCard == false)
    {
        m_pAnimator->Play(L"Front");
        fCoolTime = 0;
    }

}

void CCard::Render()
{
}

void CCard::Release()
{
}
