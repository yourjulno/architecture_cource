#pragma once

#include <animals/herbo/Herbo.h>

namespace jul::animals
{

class Rabbit: public Herbo
{
    std::string name_ = "Кролик";
    int food_;
    bool is_healthy_;

public:

    explicit Rabbit(const std::string& name = "Кролик", int food = 5, bool is_healthy = true):
    Herbo(name, food, is_healthy), name_(name), food_(food), is_healthy_(is_healthy) {}

    void display() const noexcept override
    {
        std::cout << name_ << " (КРОЛИК) потребляет " << food_ << " кг еды в сутки " << std::endl;
        if (!is_healthy_) std::cout << name_ << " [НЕЗДОРОВ] " << std::endl;
    }

};

}
