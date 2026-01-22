#include "Entity.hpp"

bool Entity::isAlive() const
{
	return alive;
}

void Entity::destroy()
{
	alive = false;
}

const std::string &Entity::getName() const
{
	return name;
}

void Entity::setName(const std::string &newName)
{
	name = newName;
}

std::size_t Entity::getId() const
{
	return id;
}