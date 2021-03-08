#pragma once
#include "GameSystem.h"
#include "Entity.h"
#include <vector>
#include <memory>

class EntitySystem : public GameSystem
{
public:
    virtual void Update();

private:
    void StartSpawnedEntities();
    void UpdateActiveEntities();

    std::vector< std::shared_ptr< Entity > > m_spawnedEntities;
    std::vector< std::shared_ptr< Entity > > m_activeEntities;
};