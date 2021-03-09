#pragma once

#define PARENT_TYPE(parentType) \
using TBaseClass = parentType;  \
using parentType::parentType