#pragma once
#include "GlobalMacros.h"
#include "GameSystem.h"
#include "Entity.h"
#include <vector>
#include <memory>

class EntitySystem : public GameSystem
{
    PARENT_TYPE( GameSystem );

public:
    virtual void Update() override;

private:
    void StartSpawnedEntities();
    void UpdateActiveEntities();

    std::vector< std::shared_ptr< Entity > > m_spawnedEntities;
    std::vector< std::shared_ptr< Entity > > m_activeEntities;
};