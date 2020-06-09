#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using ComponentID = std::size_t;

//returns an incremented ID
inline ComponentID GetComponentTypeID()
{
    static ComponentID lastID = 0;
    return lastID++;
}

template <typename T> inline ComponentID GetComponentTypeID() noexcept
{
    static ComponentID typeID = GetComponentTypeID();
    return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component
{
public:
    Entity* entity_;

    virtual void Init() {}
    virtual void Update() {}
    virtual void Draw() {}

    virtual ~Component() {}
};

//entity is made up of components (like position or a sprite)
class Entity
{
private:
    bool active_= true;
    std::vector<std::unique_ptr<Component>> components_;

    ComponentArray compArray_;
    ComponentBitSet compBitSet_;

public:
    void Update()
    {
        for(auto& c : components_) c->Update();
    }

    void Draw()
    {
        for (auto& c : components_) c->Draw();
    }

    bool IsActive() {return active_; }
    void Destroy() {active_ = false; }
    

    template <typename T> bool HasComponent() const
    {
        return compBitSet_[GetComponentTypeID<T>];
    }

    template <typename T, typename... TArgs>
    T& AddComponent(TArgs&&... mArgs)
    {
        T* c(new T(std::forward<TArgs>(mArgs)...));
        c->entity_ = this;
        std::unique_ptr<Component> uPtr { c };
        components_.emplace_back(std::move(uPtr));
        
        compArray_[GetComponentTypeID<T>()] = c; 
        compBitSet_[GetComponentTypeID<T>()] = true;

        c->Init();
        return *c;
    }

    template <typename T> T& GetComponent() const
    {
        auto ptr(compArray_[GetComponentTypeID<T>()]);
        return *static_cast<T*>(ptr);
    }

};

class ComponentManager
{
private:
    std::vector<std::unique_ptr<Entity>> entities_;

public:
    void Update()
    {
        for (auto& e : entities_) { e->Update(); }
    }

    void Draw ()
    {
        for (auto& e : entities_) 
        {   
            e->Draw();
        }
    }

    void Refresh()
    {
        entities_.erase(std::remove_if(std::begin(entities_), std::end(entities_),
        [](const std::unique_ptr<Entity> &mEntity)
        {
            return !mEntity->IsActive();
        }),
        std::end(entities_));
    }

    Entity& AddEntity()
    {
        Entity* e = new Entity();
        std::unique_ptr<Entity> uPtr{e};
        entities_.emplace_back(std::move(uPtr));
        return *e;
    }
};




























