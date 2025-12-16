#pragma once

#include <animals/IAlive.h>
#include <iostream>
#include <utility>

namespace jul::animals
{

class Animal: public IAlive
{
    std::string name_ = "Animal";
    int food_ = 0;
    bool healthy_ = true;

public:

    explicit Animal(std::string name = "Animal", int food = 0, bool healthy = true):
    name_(std::move(name)), food_(food), healthy_(healthy) {}

    [[nodiscard]] std::string get_name() const override
    {
        return name_;
    }

    [[nodiscard]] int food() const override
    {
        return food_;
    }

    [[nodiscard]] bool is_healthy() const noexcept
    {
        return healthy_;
    }

    virtual void display() const noexcept
    {
        std::cout << name_ << " потребляет " << food_ << " кг еды в сутки " << std::endl;
        if (!healthy_) std::cout << name_ << " [НЕЗДОРОВ] " << std::endl;
    }
};

}
