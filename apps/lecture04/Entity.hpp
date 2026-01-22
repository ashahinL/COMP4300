#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <tuple>
#include <string>
#include <cstddef>
#include "Component.hpp"

using ComponentTuple = std::tuple<
    PositionComponent,
    VelocityComponent,
    ColorComponent>;

class Entity
{
  private:
    ComponentTuple components;
    bool alive = true;
    std::string name = "default";
    std::size_t id;

  public:
    template <typename T, typename... Args>
    void addComponent(Args... args);
    template <typename T>
    void removeComponent();
    template <typename T>
    T &getComponent();
    template <typename T>
    bool hasComponent();
    bool isAlive() const;
    void destroy();
    const std::string &getName() const;
    void setName(const std::string &newName);
    std::size_t getId() const;
};

template <typename T, typename... Args>
void Entity::addComponent(Args... args)
{
    std::get<T>(components) = T(args...);
    std::get<T>(components).exists = true;
}

template <typename T>
void Entity::removeComponent()
{
    std::get<T>(components) = T{};
    std::get<T>(components).exists = false;
}

template <typename T>
T &Entity::getComponent()
{
    return std::get<T>(components);
}

template <typename T>
bool Entity::hasComponent()
{
    return std::get<T>(components).exists;
}

#endif   // ENTITY_HPP