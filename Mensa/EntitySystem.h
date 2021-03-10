#pragma once
#include "GlobalMacros.h"
#include "GameSystem.h"
#include "Entity.h"
#include <vector>
#include <memory>

namespace ent
{
    class EntitySystem : public GameSystem
    {
        PARENT_TYPE( GameSystem );

    public:
        virtual void Update() override;

        template<typename T, typename... Args>
        std::shared_ptr< T > SpawnEntity( const Args&... args )
        {
            std::shared_ptr< T > spawnedEntity = std::make_shared< T >( GetGame(), args... );
            spawnedEntity->Initialize();
            m_spawnedEntities.push_back( spawnedEntity );

            return spawnedEntity;
        }

    private:
        void StartSpawnedEntities();
        void UpdateActiveEntities();

        std::vector< std::shared_ptr< Entity > > m_spawnedEntities;
        std::vector< std::shared_ptr< Entity > > m_activeEntities;
    };
}