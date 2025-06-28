#pragma once
#include <iostream>
#include <string>
#include <utility>

#include "VehiculeSpecs.h"


class Vehicule
{
private:
    friend class FleetManager;
    VehiculeSpecs specs;

protected:
    virtual void print(std::ostream& os) const;

public:
    explicit Vehicule(VehiculeSpecs specs) : specs(std::move(specs))
    {
    }


    [[nodiscard]] virtual const VehiculeSpecs& getSpecs();


    virtual void display() const;


    friend std::ostream& operator<<(std::ostream& os, const Vehicule& vehicule);


    virtual ~Vehicule() = default;
};
