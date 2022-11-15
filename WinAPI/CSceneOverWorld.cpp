#include "framework.h"
#include "CSceneOverWorld.h"

#include "COverWorldPlayer.h"
#include "CCameraController.h"
#include "CImageObject.h"

CSceneOverWorld::CSceneOverWorld()
{
	pPlayer = nullptr;
	pBackLayer=nullptr;
	pBackground = nullptr;
	pTopper = nullptr;
	pTopperObject = nullptr;
}

CSceneOverWorld::~CSceneOverWorld()
{
}

void CSceneOverWorld::Init()
{
	pBackLayer = RESOURCE->LoadImg(L"overMap", L"Image\\overmap.png");

	pBackground = new CImageObject();
	pBackground->SetImage(pBackLayer);
	pBackground->SetPos(1500, 500);
	AddGameObject(pBackground);

	pPlayer = new COverWorldPlayer();
	pPlayer->SetPos(OVERWORLDPLAYERSTARTPOS);
	AddGameObject(pPlayer);

	pTopper= RESOURCE->LoadImg(L"overMapTopper", L"Image\\overmap_topper.png");

	pTopperObject = new CImageObject();
	pTopperObject->SetImage(pTopper);
	pTopperObject->SetPos(1284.5- 500, 1213.5-720);
	pTopperObject->SetLayer(Layer::FrontLayer);
	AddGameObject(pTopperObject);

	CCameraController* pCamController = new CCameraController();
	pCamController->SetOverWorldPlayer(pPlayer);
	AddGameObject(pCamController);
}

void CSceneOverWorld::Enter()
{
	CAMERA->FadeIn(0.25f);
	LoadTile(GETPATH + L"Tile\\OverMap.tile");
}

void CSceneOverWorld::Update()
{
	CAMERA->SetTargetPos(pPlayer->GetPos());
	if (BUTTONDOWN(VK_ESCAPE))
	{
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::Title, 0.25f);
	}
}

void CSceneOverWorld::Render()
{
}

void CSceneOverWorld::Exit()
{
	CAMERA->FadeOut(0.25f);
}

void CSceneOverWorld::Release()
{
}