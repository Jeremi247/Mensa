#include "EntitySystem.h"

void EntitySystem::Update()
{
    StartSpawnedEntities();
    UpdateActiveEntities();
}

void EntitySystem::StartSpawnedEntities()
{
    int newCapacity = m_activeEntities.size() + m_spawnedEntities.size();
    m_activeEntities.reserve( newCapacity );

    for (std::shared_ptr< Entity >& entity : m_spawnedEntities)
    {
        entity->Start();
        m_activeEntities.push_back( entity );
    }

    m_spawnedEntities.clear();
}

void EntitySystem::UpdateActiveEntities()
{
    for (std::shared_ptr< Entity >& entity : m_activeEntities)
    {
        entity->Update();
    }
}