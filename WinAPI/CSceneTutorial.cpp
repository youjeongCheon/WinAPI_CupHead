#include "framework.h"
#include "CSceneTutorial.h"

#include "CPlayer.h"
#include "CMonserPyrimid.h"
#include "CMonster.h"
#include "CCameraController.h"
#include "CImageObject.h"
#include "CBlock.h"
#include "CGround.h"
#include "CObstacle.h"
#include "CParryObject.h"

CSceneTutorial::CSceneTutorial()
{
	pPlayer = nullptr;
	pBackLayer = nullptr;
	pFrontLayer = nullptr;

	pBackground = nullptr;
	pFrontground = nullptr;
	parryNum = 0;
	pParryObject1=nullptr;
	pParryObject2=nullptr;
	pParryObject3=nullptr;
}

CSceneTutorial::~CSceneTutorial()
{
}

int CSceneTutorial::GetParryNum()
{
	return parryNum;
}

void CSceneTutorial::SetParryNum(int num)
{
	parryNum = num;
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

	CGround* pGround = new CGround();
	pGround->SetPos(0, GROUNDPOSY);
	AddGameObject(pGround);

#pragma region Tutorial_Object
	CImage* pArrowDuck = RESOURCE->LoadImg(L"ArrowDuck", L"Image\\tutorial_arrow_duck.png");
	CImageObject* pObjArrowDuck = new CImageObject();
	pObjArrowDuck->SetImage(pArrowDuck);
	pObjArrowDuck->SetPos(640, 430);
	AddGameObject(pObjArrowDuck);

	CBlock* pBlockCube = new CBlock();
	pBlockCube->SetBlockType(BlockType::Cube);
	AddGameObject(pBlockCube);

	CObstacle* pObstacleCube = new CObstacle();
	pObstacleCube->SetScale(132, 147);
	pObstacleCube->SetPos(1381.f, pObstacleCube->GetOnGroundPosY());
	AddGameObject(pObstacleCube);

	CBlock* pBlockCP = new CBlock();
	pBlockCP->SetBlockType(BlockType::Cylinder_platform);
	AddGameObject(pBlockCP);

	CObstacle* pObstacleCP1 = new CObstacle();
	pObstacleCP1->SetScale(78, 266);
	pObstacleCP1->SetPos(1898, pObstacleCP1->GetOnGroundPosY());
	AddGameObject(pObstacleCP1);

	CObstacle* pObstacleCP2 = new CObstacle();
	pObstacleCP2->SetScale(400, 20);
	pObstacleCP2->SetPos(2152, 334);
	AddGameObject(pObstacleCP2);

	CObstacle* pObstacleCP3 = new CObstacle();
	pObstacleCP3->SetScale(114, 287);
	pObstacleCP3->SetPos(2321, 174);
	AddGameObject(pObstacleCP3);

	CBlock* pBlockPlinth = new CBlock();
	pBlockPlinth->SetBlockType(BlockType::Plinth);
	AddGameObject(pBlockPlinth);

	CObstacle* pObstaclePlinth = new CObstacle();
	pObstaclePlinth->SetScale(141, 214);
	pObstaclePlinth->SetPos(2994, pObstaclePlinth->GetOnGroundPosY());
	AddGameObject(pObstaclePlinth);

	CMonserPyrimid* pMonserPyrimid = new CMonserPyrimid();
	AddGameObject(pMonserPyrimid);

	CParryObject* pParryObject1 = new CParryObject();
	pParryObject1->SetPos(3400, 300);
	pParryObject1->SetNum(0);
	pParryObject1->SetScene(this);
	AddGameObject(pParryObject1);

	CParryObject* pParryObject2 = new CParryObject();
	pParryObject2->SetPos(3550, 300);
	pParryObject2->SetNum(1);
	pParryObject2->SetScene(this);
	AddGameObject(pParryObject2);

	CParryObject* pParryObject3 = new CParryObject();
	pParryObject3->SetPos(3700, 300);
	pParryObject3->SetNum(2);
	pParryObject3->SetScene(this);
	AddGameObject(pParryObject3);

	CBlock* pExitDoor = new CBlock();
	pExitDoor->SetBlockType(BlockType::Exit_Door);
	AddGameObject(pExitDoor);

#pragma endregion 

	pPlayer = new CPlayer();
	pPlayer->SetPos(PLAYERSTARTPOS);
	AddGameObject(pPlayer);

	pFrontground = new CImageObject();
	pFrontground->SetImage(pFrontLayer);
	pFrontground->SetLayer(Layer::FrontLayer);
	pFrontground->ChangeScale(true, Vector(WINSIZEX, WINSIZEY));
	pFrontground->SetScreenFixed(true);
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
	RENDER->Text(L"THE TUTORIAL", 0, 300, 500, 300,Color(),30.0F);
}

void CSceneTutorial::Exit()
{
}

void CSceneTutorial::Release()
{
}
