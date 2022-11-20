#include "framework.h"
#include "CSceneBossStage.h"

#include "CGameManager.h"
#include "CPlayer.h"
#include "CMonsterPotato.h"
#include "CGround.h"
#include "CImageObject.h"
#include "CCloud.h"

#include "CMonsterCarrot.h"
#include "CCameraController.h"

CSceneBossStage::CSceneBossStage()
{
	pPlayer = nullptr;
	
}

CSceneBossStage::~CSceneBossStage()
{
}

void CSceneBossStage::Init()
{
	CImage* pImgBackSky = RESOURCE->LoadImg(L"BossStage_BackSky", L"Image\\Botanic-Panic_Sky.png");
	CImageObject* pObjBackSky = new CImageObject();
	pObjBackSky->SetImage(pImgBackSky);
	pObjBackSky->SetPos(WINSIZEX * 0.5f, WINSIZEY * 0.5f);
	AddGameObject(pObjBackSky);

	CCloud* pCloud1 = new CCloud();
	pCloud1->SetPos(WINSIZEX * 0.5f, WINSIZEY * 0.5f);
	AddGameObject(pCloud1);

	CCloud* pCloud2 = new CCloud();
	pCloud2->SetPos(WINSIZEX * 1.5f, WINSIZEY * 0.5f);
	AddGameObject(pCloud2);

	/*CImage* pImgCloud = RESOURCE->LoadImg(L"BossStage_Cloud", L"Image\\Botanic-Panic_Cloud.png");
	CImageObject* pObjCloud = new CImageObject();
	pObjCloud->SetImage(pImgCloud);
	pObjCloud->SetPos(WINSIZEX * 0.5f, WINSIZEY * 0.5f);
	AddGameObject(pObjCloud);*/

	CImage* pImgPlant = RESOURCE->LoadImg(L"BossStage_Plant", L"Image\\Botanic-Panic_PlantLayer.png");
	CImageObject* pObjPlant = new CImageObject();
	pObjPlant->SetImage(pImgPlant);
	pObjPlant->SetPos(WINSIZEX * 0.5f, WINSIZEY * 0.5f);
	AddGameObject(pObjPlant);

	CImage* pImgGround = RESOURCE->LoadImg(L"BossStage_Ground", L"Image\\Botanic-Panic_Ground.png");
	CImageObject* pObjGround = new CImageObject();
	pObjGround->SetImage(pImgGround);
	pObjGround->SetPos(WINSIZEX * 0.5f, WINSIZEY * 0.5f);
	pObjGround->SetLayer(Layer::Ground);
	AddGameObject(pObjGround);

	// ¸ó½ºÅÍ
	CMonsterPotato* pMonsterPotato = new CMonsterPotato();
	pMonsterPotato->SetPos(WINSIZEX * 0.8, WINSIZEY * 0.6+10);
	AddGameObject(pMonsterPotato);

	pPlayer = new CPlayer();
	pPlayer->SetPos(PLAYERSTARTPOS);
	AddGameObject(pPlayer);
	SETPLAYER(pPlayer);

	CImage* pImgFrontLayer = RESOURCE->LoadImg(L"BossStage_FrontLayer", L"Image\\Botianic-Panic_FrontLayer.png");
	CImageObject* pObjFrontLayer = new CImageObject();
	pObjFrontLayer->SetImage(pImgFrontLayer);
	pObjFrontLayer->SetLayer(Layer::FrontLayer);
	pObjFrontLayer->SetPos(WINSIZEX * 0.5f, WINSIZEY * 0.5f);
	AddGameObject(pObjFrontLayer);

	CGround* pGround = new CGround();
	pGround->SetPos(2500, GROUNDPOSY);
	AddGameObject(pGround);

	CCameraController* pCamController = new CCameraController();
	AddGameObject(pCamController);
}

void CSceneBossStage::Enter()
{
	Init();
	CAMERA->FadeIn(0.25f);
}

void CSceneBossStage::Update()
{
	if (pPlayer->GetPos().x > WINSIZEX-100)
		pPlayer->SetPos(WINSIZEX - 100, pPlayer->GetPos().y);

	if (BUTTONDOWN(VK_ESCAPE))
	{
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::Title, 0.25f);
	}

	
}

void CSceneBossStage::Render()
{
}

void CSceneBossStage::Exit()
{
	CAMERA->FadeOut(0.25f);
	SceneRelease();
}

void CSceneBossStage::Release()
{
}
