#pragma once

#include <animals/predators/Predator.h>

namespace jul::animals
{

class Tiger: public Predator
{
    std::string name_ = "Тигр";
    int food_;
    bool is_healthy_;

public:

    explicit Tiger(const std::string& name, int food = 10, bool is_healthy = true):
    Predator(name, food, is_healthy), name_(name), food_(food), is_healthy_(is_healthy) {}


    void display() const noexcept override
    {
        std::cout << name_ << " (ТИГР) потребляет " << food_ << " кг еды в сутки " << std::endl;
        if (!is_healthy_) std::cout << name_ << " [НЕЗДОРОВ] " << std::endl;
    }

};

}
