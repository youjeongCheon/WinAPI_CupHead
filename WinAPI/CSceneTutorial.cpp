#include "framework.h"
#include "CSceneTutorial.h"

#include "CPlayer.h"
#include "CMonster.h"
#include "CCameraController.h"
#include "CImageObject.h"

CSceneTutorial::CSceneTutorial()
{
	pPlayer = nullptr;
	pBackLayer = nullptr;
	pFrontLayer = nullptr;

	pBackground = nullptr;
	pFrontground = nullptr;
}

CSceneTutorial::~CSceneTutorial()
{
}

void CSceneTutorial::Init()
{
	pBackLayer = RESOURCE->LoadImg(L"BackLayer", L"Image\\tutorial_room_back_layer.png");
	pFrontLayer = RESOURCE->LoadImg(L"FrontLayer", L"Image\\tutorial_room_front_layer.png");

	pBackground = new CImageObject();
	pBackground->SetImage(pBackLayer);
	pBackground->ChangeScale(true, Vector(WINSIZEX, WINSIZEY));
	pBackground->SetScreenFixed(true);
	AddGameObject(pBackground);

#pragma region Object
	CImage* pArrowDuck = RESOURCE->LoadImg(L"ArrowDuck", L"Image\\tutorial_arrow_duck.png");
	CImageObject* pObjArrowDuck = new CImageObject();
	pObjArrowDuck->SetImage(pArrowDuck);
	pObjArrowDuck->SetPos(640, 360);
	AddGameObject(pObjArrowDuck);

#pragma endregion 

	pPlayer = new CPlayer();
	pPlayer->SetPos(PLAYERSTARTPOS);
	AddGameObject(pPlayer);

	pFrontground = new CImageObject();
	pFrontground->SetImage(pFrontLayer);
	pFrontground->SetLayer(Layer::FrontLayer);
	pFrontground->ChangeScale(true, Vector(WINSIZEX, WINSIZEY));
	pBackground->SetScreenFixed(true);
	AddGameObject(pFrontground);



	CCameraController* pCamController = new CCameraController(pPlayer);
	AddGameObject(pCamController);
}

void CSceneTutorial::Enter()
{
	CAMERA->FadeIn(0.25f);
}

void CSceneTutorial::Update()
{

	if (BUTTONDOWN(VK_ESCAPE))
	{
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::Title, 0.25f);
	}
}

void CSceneTutorial::Render()
{
}

void CSceneTutorial::Exit()
{
}

void CSceneTutorial::Release()
{
}
