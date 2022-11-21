#include "framework.h"
#include "CHPObject.h"

CHPObject::CHPObject()
{
    m_hp = 0;
    m_pImgHP = nullptr;
    m_pAnimator = 0;
    m_layer = Layer::FrontLayer;
    str = L"";
    m_vecPos = Vector(WINSIZEX * 0.05f, WINSIZEY * 0.95f);
}

CHPObject::~CHPObject()
{
}

int CHPObject::GetHP()
{
    return m_hp;
}

void CHPObject::SetHP(int hp)
{
    m_hp = hp;
}

void CHPObject::Init()
{
    m_pImgHP = RESOURCE->LoadImg(L"HP", L"Image\\Cuphead_Health.png");
    m_pAnimator = new CAnimator;
    m_pAnimator->CreateAnimation(L"HP=0", m_pImgHP, Vector(1, 1), Vector(79, 33), Vector(80, 1), 0.1f, 1,false);
    m_pAnimator->CreateAnimation(L"HP=1", m_pImgHP, Vector(81, 1), Vector(79, 33), Vector(80, 1), 0.1f, 3);
    m_pAnimator->CreateAnimation(L"HP=2", m_pImgHP, Vector(321, 1), Vector(79, 33), Vector(80, 1), 0.1f, 1,false);
    m_pAnimator->CreateAnimation(L"HP=3", m_pImgHP, Vector(401, 1), Vector(79, 33), Vector(80, 1), 0.1f, 1, false);
    AddComponent(m_pAnimator);
}

void CHPObject::Update()
{
    str = L"HP=";
    switch (m_hp)
    {
    case 0:
        str += L"0";
        break;
    case 1:
        str += L"1";
        break;
    case 2:
        str += L"2";
        break;
    case 3:
        str += L"3";
        break;
    }
    m_pAnimator->Play(str);
}

void CHPObject::Render()
{
}

void CHPObject::Release()
{
}
