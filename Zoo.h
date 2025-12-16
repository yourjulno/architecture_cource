#pragma once

#include <animals/herbo/Monkey.h>
#include <animals/herbo/Rabbit.h>
#include <animals/predators/Tiger.h>
#include <animals/predators/Wolf.h>

#include <things/Table.h>
#include <things/Computer.h>
#include <DiContainer.h>

#include <utility>
#include <vector>
#include <Clinic.h>

namespace jul::animals
{

class Zoo
{
    std::vector<std::shared_ptr<Animal>> animals_;
    std::vector<std::shared_ptr<Thing>> things_;
    std::shared_ptr<IVeterinaryClinic> clinic_;
    std::shared_ptr<DiContainer> container_;

public:

     Zoo(std::shared_ptr<IVeterinaryClinic> clinic, std::shared_ptr<DiContainer> container)
            : clinic_(clinic), container_(container) {}

    [[nodiscard]] int get_full_food() const noexcept
    {
        int food_sum = 0;
        for (const auto & animal : animals_)
        {
            food_sum += animal->food();
        }
        return food_sum;
    }

    void display_all_animals() const noexcept
    {
         std::cout << "=== ВСЕ ЖИВОТНЫЕ ===\n";
        for (const auto & animal : animals_)
        {
            animal->display();
        }
    }

    void display_inventory() const
    {
        std::cout << "=== ИНВЕНТАРНЫЙ УЧЕТ ===\n";
        for (const auto& item : things_) {
            item->get_info();
        }
    }

    bool add_animal(const std::shared_ptr<Animal>& animal)
    {
        if (clinic_->checkHealth(animal)) {
            animals_.push_back(animal);
            return true;
        }
        return false;
    }

    void add_thing(const std::shared_ptr<Thing>& thing)
    {
        things_.push_back(thing);
    }

};
}
