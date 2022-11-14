#include "framework.h"
#include "CSceneTitle.h"

#include "CImageObject.h"
#include "CTitleObject.h"

CSceneTitle::CSceneTitle()
{
	pBackLayer = nullptr;
	pBackground = nullptr;
}

CSceneTitle::~CSceneTitle()
{
}

void CSceneTitle::Init()
{
	pBackLayer = RESOURCE->LoadImg(L"title_screen_background", L"Image\\title_screen_background.png");
	pBackground = new CImageObject();
	pBackground->SetImage(pBackLayer);
	pBackground->ChangeScale(true, Vector(WINSIZEX, WINSIZEY));
	pBackground->SetPos(WINSIZEX * 0.5f, WINSIZEY * 0.5f);
	AddGameObject(pBackground);

	CTitleObject* pObject = new CTitleObject();
	pObject->SetPos(WINSIZEX * 0.5f, WINSIZEY * 0.55f);
	AddGameObject(pObject);
	
}

void CSceneTitle::Enter()
{	
	CAMERA->FadeIn(0.25f);
}

void CSceneTitle::Update()
{
	if (BUTTONDOWN(VK_F1))
	{
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::OverWorld,0.25f);
	}
	if (BUTTONDOWN(VK_SPACE))
	{
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::Tutorial, 0.25f);
	}
	if (BUTTONDOWN(VK_F5))
	{
		CHANGESCENE(GroupScene::TileTool);
	}

	
}

void CSceneTitle::Render()
{
	RENDER->Text(L"press space to start",
		WINSIZEX * 0.5f - 100,
		WINSIZEY * 0.5f - 10,
		WINSIZEX * 0.5f + 100,
		WINSIZEY * 0.5f + 10,
		Color(0, 0, 0, 1.f),
		20.f);
}

void CSceneTitle::Exit()
{

}

void CSceneTitle::Release()
{
}
