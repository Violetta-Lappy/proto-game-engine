#pragma once

#include "../GameEngine/GEVector3.h"

class TransformComponent {
public:
	GEVector3 Position = GEVector3(0.0f, 0.0f, 0.0f);
	GEVector3 Rotation = GEVector3(0.0f, 0.0f, 0.0f);
	GEVector3 Scale = GEVector3(0.0f, 0.0f, 0.0f);	
};