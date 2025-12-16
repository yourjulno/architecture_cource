#pragma once

#include <animals/Animal.h>

namespace jul::animals
{

class Predator: public Animal
{
    std::string name_ = "Predator";

public:

    explicit Predator(const std::string& name, int food = 0, bool is_healthy = true): Animal(name, food, is_healthy),
    name_(name) {}
};

}
