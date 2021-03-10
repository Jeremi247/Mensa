#pragma once
#include "Entity.h"
#include "GlobalMacros.h"

class Player : public ent::Entity
{
    PARENT_TYPE( Entity );

public:
    virtual void Start() override;
    virtual void Update() override;
};