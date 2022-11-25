#include "framework.h"
#include "CSceneOverWorld.h"

#include "COverWorldObject.h"
#include "COverWorldPlayer.h"
#include "CCameraController.h"
#include "CImageObject.h"
#include "CGameManager.h"

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
}

void CSceneOverWorld::Enter()
{
	pBackLayer = RESOURCE->LoadImg(L"overMap", L"Image\\overmap.png");

	pBackground = new CImageObject();
	pBackground->SetImage(pBackLayer);
	pBackground->SetPos(1500, 500);
	AddGameObject(pBackground);

	COverWorldObject* pObjGoToBossStage = new COverWorldObject();
	pObjGoToBossStage->SetPos(1366, 900);
	AddGameObject(pObjGoToBossStage);

	pPlayer = new COverWorldPlayer();
	SETOVERWORLDPLAYER(pPlayer);
	SETOVERWORLDPLAYERPOS;
	AddGameObject(pPlayer);


	pTopper = RESOURCE->LoadImg(L"overMapTopper", L"Image\\overmap_topper.png");

	pTopperObject = new CImageObject();
	pTopperObject->SetImage(pTopper);
	pTopperObject->SetPos(1284.5 - 500, 1213.5 - 720);
	pTopperObject->SetLayer(Layer::FrontLayer);
	AddGameObject(pTopperObject);

	CCameraController* pCamController = new CCameraController();
	pCamController->SetOverWorldPlayer(pPlayer);
	AddGameObject(pCamController);

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
	GETOVERWORLDPLAYERPOS;
	CAMERA->FadeOut(0.25f);
	DeleteAll();
	RESOURCE->Release();
}

void CSceneOverWorld::Release()
{
}
