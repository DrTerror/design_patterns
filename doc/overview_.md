# Overview ...

## Procedural Programming
What:
 - Code is organized as procedures/functions operating on data.

When:
 - Small programs,
 - performance-critical systems.

```cpp
int add(int a, int b) {
    return a + b;
}
```

Pros:
 - Simple,
 - fast

Cons:
 - Poor scalability for large systems


## Object-Oriented Programming (OOP)
What:
 - Organizes code around objects with state and behavior.
Core ideas:
 - Encapsulation,
 - inheritance,
 - polymorphism.

```cpp
class Enemy {
public:
    virtual void attack() = 0;
};
```

Pros:
 - Reusable,
 - extensible

Cons:
 - Can become over-engineered

## Functional Programming
What:
 - Emphasizes immutability and pure functions.

When:
 - Predictable logic,
 - parallel processing.

```cpp
auto square = [](int x) { return x * x; };
```

Pros:
 - Easier reasoning,
 - fewer bugs

Cons:
 - Less intuitive for state-heavy systems (e.g., games)

## Data-Oriented Programming (DOP)
What:
 - Organizes code around data layout, not objects.

When:
 - Games,
 - simulations,
 - performance-critical systems.

```cpp
struct Position { float x, y; };
struct Velocity { float vx, vy; };

Position positions[1000];
Velocity velocities[1000];
```

Pros:
 - Cache-friendly,
 - fast

Cons:
 - Less intuitive than OOP

## Component-Based Design
What:
 - Objects are composed of reusable components.
When:
 - Games,
 - ECS systems.

```cpp
struct HealthComponent { int hp; };
struct RenderComponent { Sprite sprite; };
```

Pros:
 - Flexible composition

Cons:
 - Indirection complexity

## Event-Driven Programming
What:
 - Code reacts to events (input, messages).

When:
 - GUIs,
 - games,
 - networked apps.

```cpp
onKeyPressed(Key::Space, []() {
    jump();
});
```

## Multithreading / Concurrency
What:
 - Multiple tasks run simultaneously.

When:
 - Background loading,
 - AI,
 - networking.

```cpp
std::thread worker(loadAssets);
```

----

## Architectural Patterns

### MVC (Model-View-Controller)
What:
 - Separates data,
 - UI,
 - logic.

Example
 - Model: Game state
 - View: Renderer
 - Controller: Input handling

### ECS (Entity-Component-System)
What:
 - Entities are IDs,
 - logic lives in systems.

```cpp
System<Position, Velocity>::update();
```

Excellent for: Games and simulations

### Layered Architecture
What:
 - Code organized in layers.

Example
 - UI
 - Gameplay
 - Engine
 - Platform

## Defensive & Maintenance Techniques
### RAII (C++)
What:
 - Resources tied to object lifetime.

```cpp
std::lock_guard<std::mutex> lock(m);
```

### Dependency Injection
What:
 - Dependencies passed in, not created internally.

```cpp
Player(Audio& audio);
```

### Separation of Concerns
What:
 - Each module has one responsibility.

| Category     | Examples                           |
|--------------|:----------------------------------:|
| Techniques   | OOP, DOP, Functional, Event-driven |
| Creational   | Singleton, Factory, Builder        |
| Structural   | Adapter, Decorator, Facade         |
| Behavioral   | Observer, Strategy, State          |
| Architecture | ECS, MVC, Layered                  |
