#pragma once

#include <animals/Animal.h>

namespace jul::animals
{

class Herbo: public Animal
{
    std::string name_ = "Herbo";

public:

    explicit Herbo(const std::string& name, int food = 0, bool is_healthy = true):
    Animal(name, food, is_healthy), name_(name){}

    virtual void graze() const noexcept
    {
        std::cout << name_ << " пасётся и ест " << std::endl;
    }
};

}
