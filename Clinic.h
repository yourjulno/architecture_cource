#pragma once
#include "animals/Animal.h"
#include <memory>

namespace jul::animals {

class IVeterinaryClinic
{
public:
    virtual ~IVeterinaryClinic() = default;
    virtual bool checkHealth(const std::shared_ptr<animals::Animal>& animal) = 0;
};

class VeterinaryClinic : public IVeterinaryClinic
{
public:

    VeterinaryClinic() = default;

    bool checkHealth(std::shared_ptr<animals::Animal> const& animal) override {
        // Симуляция проверки здоровья
        return animal->is_healthy();
    }
};

}