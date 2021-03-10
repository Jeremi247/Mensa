#pragma once
#include "Level.h"
#include <memory>

class Player;

class DefaultLevel : public Level
{
public:
    virtual void Start() override;

private:
    std::shared_ptr< Player > m_player;
};