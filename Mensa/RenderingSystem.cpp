#include "RenderingSystem.h"
#include "ShapeRenderer.h"
#include <algorithm>

void RenderingSystem::Draw( sf::RenderWindow& window )
{
    ShapesMap shapesMap;
    std::vector< int > keys;

    GatherKeysAndShapes( keys, shapesMap );

    std::sort( keys.begin(), keys.end() );

    for( int key : keys )
    {
        const std::vector< std::shared_ptr< ShapeRenderer > >& shapeRenderers = shapesMap[key];
        for( const std::shared_ptr< ShapeRenderer >& shapeRenderer : shapeRenderers )
        {
            shapeRenderer->Draw( window );
        }
    }
}

void RenderingSystem::GatherKeysAndShapes( std::vector< int >& outKeys, ShapesMap& outMap )
{
    for( size_t i = 0; i < m_registeredRenderers.size(); ++i )
    {
        if( std::shared_ptr< ShapeRenderer > renderer = m_registeredRenderers[i].lock() )
        {
            int key = renderer->GetDrawOrder();
            outMap[key].push_back( renderer );
            outKeys.push_back( key );
        }
        else
        {
            m_registeredRenderers.erase( m_registeredRenderers.begin() + i );
            --i;
        }
    }
}

void RenderingSystem::Register( const std::weak_ptr< ShapeRenderer >& component )
{
    m_registeredRenderers.push_back( component );
}