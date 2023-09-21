#pragma once

enum KPhysicCollisionShape {
	K_Box,
	K_Sphere
};

class PhysicCollision {
public:
	int m_shapeType;
};