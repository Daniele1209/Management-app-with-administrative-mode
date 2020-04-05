#include "turret.h"

Turret::Turret() : location(""), size(0), aura_level(0), vision(""){}

Turret::Turret(const std::string& location, const int size, const int aura_level, const std::string& vision) {
	this->location = location;
	this->size = size;
	this->aura_level = aura_level;
	this->vision = vision;
}

bool Turret::operator==(const Turret& t)
{
	return (this->location == t.location && this->size == t.size && this->aura_level == t.aura_level && this->vision == t.vision);
}
