# Overview over programming techniques

## Modularity & Abstraction
What:
 - Break code into small,
 - focused units (modules, functions, classes).
 - Hide implementation behind clear interfaces.

Why:
 - Easier maintenance,
 - testing,
 - reuse.

```python
# math_utils.py
def mean(xs: list[float]) -> float:
       return sum(xs) / len(xs)

# main.py
from math_utils import mean
```

## Separation of Concerns (SoC)
What:
 - Keep distinct responsibilities apart (e.g., UI vs. business logic vs. data access).

Why:
 - Reduces coupling,
 - increases clarity.

```python
# data.py
def fetch_users(db):
    return db.query("SELECT id, name FROM users")

# business.py
def active_user_names(users):
    return [u["name"] for u in users if u.get("active")]

# ui.py
def render(names):
    print("\n".join(names))
```

## DRY (Don't Repeat Yourself)
What:
 - Avoid duplicating logic;
 - centralize it.

Why:
 - Fewer bugs,
 - consistent behavior.

```python
def validate_email(email: str) -> bool:
    return "@" in email and "." in email

def register(email):
    if not validate_email(email):
        raise ValueError("Invalid email")
    # ...

def update_profile(email):
    if not validate_email(email):
        raise ValueError("Invalid email")
```

## KISS & YAGNI
### KISS (Keep It Simple, Stupid)
Prefer straightforward solutions.

```python
# KISS: simple map instead of over-engineered class hierarchy
TAX_RATES = {"DE": 0.19, "US": 0.07, "UK": 0.20}
def price_with_tax(price, country):
    return price * (1 + TAX_RATES.get(country, 0))
```

### YAGNI (You Aren’t Gonna Need It)
Don’t build for speculative future features.

## Defensive Programming
What:
 - Validate inputs,
 - fail fast,
 - handle edge cases.

 Why:
 - Robustness in the face of bad data or misuse.

```python
def divide(a: float, b: float) -> float:def
    if b == 0:
        raise ZeroDivisionError("b must not be zero")
```

## Error Handling & Resilience
What:
 - Use exceptions,
 - retries,
 - timeouts,
 - circuit breakers.

Why:
 - Better user experience and system stability.

```python
import time

def retry(fn, attempts=3, delay=0.2):
    for i in range(attempts):
        try:
            return fn()
        except Exception as e:
            if i == attempts - 1:
                raise
```

## Logging & Observability
What:
 - Structured logs,
 - metrics,
 - tracing.

Why:
 - Diagnosing issues in production.

```python
import logging

logging.basicConfig(level=logging.INFO)

def process(order_id):
    logging.info("processing order_id=%s", order_id)
    # ...
```


## Test-Driven Development (TDD)
What:
 - Write tests first, then implement.

Why:
 - Clarifies requirements,
 - improves design.

```python
# test_math_utils.py
def test_mean():
    assert mean([1, 2, 3]) == 2
```

## Refactoring
What:
 - Improve code structure without changing behavior.

Why:
 - Maintainability,
 - reduce tech debt.

```python
# Before: long function
def compute(a, b, c):
    # ...
    pass

# After: extract helpers
def compute(a, b, c):
    part1 = _normalize_inputs(a, b, c)
    part2 = _calculate(part1)
    return _format(part2)
```

## Performance & Complexity Awareness
What:
 - Reason about time/space complexity;
 - profile hotspots.

Why:
 - Scalability and cost control.

```python
# Avoid O(n^2) lookups
items = [1, 2, 3, 2]
seen = set(items)  # O(n)
```

## Concurrency Models
 - Threads: Parallel I/O, limited CPU-bound gains due to GIL in CPython.
 - Async/await: Efficient I/O concurrency.
 - Processes: True CPU parallelism.

```python
# Async example (Python)
import asyncio

async def fetch(url):
    # await aiohttp.get(url) ...
    return url

async def main(urls):
    results = await asyncio.gather(*(fetch(u) for u in urls))
    return results
```

## Functional Techniques
What:
 - Pure functions,
 - immutability,
 - higher-order functions.

Why:
 - Easier reasoning,
 - fewer side effects.

```python
def apply_discount(price, pct):
       return price * (1 - pct)

prices = [100, 200]
```

## OOP Principles & SOLID
### Single Responsibility
One reason to change.
### Open/Closed
Open for extension, closed for modification.
### Liskov Substitution
Subtypes must be substitutable.
### Interface Segregation
Prefer small interfaces.
### Dependency Inversion
Depend on abstractions.
￼
￼
```python
from abc import ABC, abstractmethod

class Notifier(ABC):
    @abstractmethod
    def send(self, msg: str) -> None: ...

class EmailNotifier(Notifier):
    def send(self, msg): print(f"Email: {msg}")

class Service:
    def __init__(self, notifier: Notifier):  # Dependency Inversion
        self.notifier = notifier
```


## Dependency Injection (DI)
What:
 - Provide dependencies from the outside.

Why:
 - Testability, modularity.

```python
mock = EmailNotifier()
svc = Service(mock)
svc.run()
```

## Clean Code Practices
 - Meaningful names,
 - small functions,
 - consistent style,
 - avoid magic numbers.

Code comments that explain *why*, not *what*.


### Choosing the Right Pattern/Technique
 - Use Strategy when you need interchangeable algorithms (e.g., different sort or compression methods).
 - Use Observer for event-driven systems or GUIs (UI reacts to model changes).
 - Use Decorator to add cross-cutting concerns (logging, caching) without altering core classes.
 - Use Factory/Abstract Factory when object creation is complex or varies by environment.
 - Use Facade to simplify a messy subsystem for clients.
 - Prefer DI & SOLID principles for testability and modularity.
 - Avoid overusing Singleton; consider DI containers or configuration objects instead.

### Anti-Patterns to Watch Out For
 - God Object / Blob: One class does everything → split responsibilities.
 - Spaghetti Code: Tangled dependencies → apply SoC and modular design.
 - Golden Hammer: One tool for every problem → choose patterns per context.
 - Premature Optimization: Optimize only after measuring → profile first.
 - Copy-Paste Programming: Leads to divergence → refactor to DRY.
