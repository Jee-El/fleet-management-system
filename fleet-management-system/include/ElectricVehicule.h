#pragma once
#include <iostream>

#include "ElectricVehiculeSpecs.h"

class ElectricVehicule : public Vehicule
{
private:
    ElectricVehiculeSpecs specs;

protected:
    void print(std::ostream& os) const override;

public:
    explicit ElectricVehicule(ElectricVehiculeSpecs specs)
        : Vehicule(specs), specs(std::move(specs))
    {
    }

    [[nodiscard]] const ElectricVehiculeSpecs& getSpecs() override;

    void display() const override;

    friend std::ostream& operator<<(
        std::ostream& os,
        const ElectricVehicule& eVehicule
    );
};
