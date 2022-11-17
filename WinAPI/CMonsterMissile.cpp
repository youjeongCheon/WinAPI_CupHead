#include "framework.h"
#include "CMonsterMissile.h"

CMonsterMissile::CMonsterMissile()
{
	m_vecDir = Vector(0, 0);
	m_fVelocity = 1000;
	m_layer = Layer::MonsterMissile;
	m_strName = L"MonsterMissile";
}

CMonsterMissile::~CMonsterMissile()
{
}

void CMonsterMissile::SetDir(Vector dir)
{
	m_vecDir = dir.Normalized();
}

void CMonsterMissile::SetVelocity(float velocity)
{
	m_fVelocity = velocity;
}

