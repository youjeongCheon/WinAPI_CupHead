#include "framework.h"
#include "CSceneTitle.h"

#include "CImageObject.h"
#include "CTitleObject.h"

CSceneTitle::CSceneTitle()
{
	pTitleText = nullptr;
	pBackLayer = nullptr;
	pBackground = nullptr;

	fCoolTime = 0;
}

CSceneTitle::~CSceneTitle()
{
}

void CSceneTitle::Init()
{

}

void CSceneTitle::Enter()
{
	pTitleText = RESOURCE->LoadImg(L"title_text", L"Image\\Title_Text.png");

	pBackLayer = RESOURCE->LoadImg(L"title_screen_background", L"Image\\title_screen_background.png");
	pBackground = new CImageObject();
	pBackground->SetImage(pBackLayer);
	pBackground->ChangeScale(true, Vector(WINSIZEX, WINSIZEY));
	pBackground->SetPos(WINSIZEX * 0.5f, WINSIZEY * 0.5f);
	AddGameObject(pBackground);

	CTitleObject* pObject = new CTitleObject();
	pObject->SetPos(WINSIZEX * 0.5f, WINSIZEY * 0.55f);
	AddGameObject(pObject);

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
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::BossStage, 0.25f);
	}
	if (BUTTONDOWN(VK_F9))
	{
		CHANGESCENE(GroupScene::TileTool);
	}

	fCoolTime += DT;
	if (fCoolTime > 1.6f)
		fCoolTime = 0;
	
}

void CSceneTitle::Render()
{
	if(fCoolTime<0.8f)
		RENDER->Image(pTitleText, WINSIZEX * 0.5f-300, WINSIZEY * 0.8f, WINSIZEX * 0.5f+300, WINSIZEY * 0.8f+200);
}

void CSceneTitle::Exit()
{
	CAMERA->FadeOut(0.25f);
	DeleteAll();
	RESOURCE->Release();
}

void CSceneTitle::Release()
{
}
