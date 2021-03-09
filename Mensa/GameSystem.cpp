#include "GameSystem.h"


GameSystem::GameSystem( const std::shared_ptr< Game >& gameInstance )
    : m_gameInstance( gameInstance )
{

}

const std::shared_ptr< Game >& GameSystem::GetGame()
{
    return m_gameInstance;
}