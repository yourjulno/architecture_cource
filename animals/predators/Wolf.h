#pragma once

#include <animals/predators/Predator.h>

namespace jul::animals
{

class Wolf: public Predator
{
    std::string name_ = "Волк";
    int food_;
    bool is_healthy_;

public:

    explicit Wolf(const std::string& name = "Волк", int food = 10, bool is_healthy = true):
    Predator(name, food, is_healthy), name_(name), food_(food), is_healthy_(is_healthy) {}

    void display() const noexcept override
    {
        std::cout << name_ << " (ВОЛК) потребляет " << food_ << " кг еды в сутки " << std::endl;
        if (!is_healthy_) std::cout << name_ << " [НЕЗДОРОВ] " << std::endl;
    }

};

}
