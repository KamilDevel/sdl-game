#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using ComponentTypeId = std::size_t;

inline ComponentTypeId getComponentTypeId()
{
    static ComponentTypeId lastComponentTypeId = 0x00;

    return lastComponentTypeId++;
}

template <typename T>
inline ComponentTypeId getComponentTypeId() noexcept
{
    static ComponentTypeId componentTypeId = getComponentTypeId();

    return componentTypeId;
}

constexpr std::size_t maxComponents = 32;

using ComponentArray = std::array<Component*, maxComponents>;
using ComponentBitSet = std::bitset<maxComponents>;

class Component
{
public:
    Entity* _entity;

    virtual void init(void) { }
    virtual void update(void) { }
    virtual void draw(void) { }
    virtual ~Component() { }
};

class Entity
{
private:
    bool _active = true;
    std::vector<std::unique_ptr<Component>> _components;
    ComponentArray _componentArray;
    ComponentBitSet _componentBitSet;
public:
    void update(void)
    {
        for(auto& component : _components) component->update();
    }

    void draw()
    {
        for(auto& component : _components) component->draw();
    }

    bool isActive(void) const
    {
        return _active;
    }

    void destroy(void)
    {
        _active = false;
    }

    template <typename T>
    bool hasComponent(void) const
    {
        return _componentBitSet[getComponentTypeId<T>()];
    }

    template <typename T, typename... TArgs>
    T& addComponent(TArgs&&... args)
    {
        T* component(new T(std::forward<TArgs>(args)...));
        component->_entity = this;
        std::unique_ptr<Component> cPtr { component };
        _components.emplace_back(std::move(cPtr));

        _componentArray[getComponentTypeId<T>()] = component;
        _componentBitSet[getComponentTypeId<T>()] = true;

        component->init();

        return *component;
    }

    template <typename T>
    T& getComponent() const
    {
        auto ptr(_componentArray[getComponentTypeId<T>()]);

        return *static_cast<T*>(ptr);
    }
};

class ECS_Manager
{
private:
    std::vector<std::unique_ptr<Entity>> _entities;
public:
    void update()
    {
        for(auto& entity : _entities) entity->update();
    }

    void draw()
    {
        for(auto& entity : _entities) entity->draw();
    }

    void gc()
    {
        _entities.erase(std::remove_if(
            std::begin(_entities),
            std::end(_entities),
            [](const std::unique_ptr<Entity> &entity) {
                return !entity->isActive();
            }), std::end(_entities)
        );
    }

    Entity& addEntity()
    {
        Entity* entityPtr = new Entity();
        std::unique_ptr<Entity> uPtr { entityPtr };
        _entities.emplace_back(std::move(uPtr));

        return *entityPtr;
    }
};



