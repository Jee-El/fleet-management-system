#pragma once

#include "Vehicule.h"

struct ElectricVehiculeSpecs : VehiculeSpecs
{
    friend class FleetManager;

private:
    int autonomy{0};

protected:
    void print(std::ostream& os) const override;

public:
    ElectricVehiculeSpecs(
        std::string brand,
        std::string model,
        int autonomy
    )
        : VehiculeSpecs(
              std::move(brand),
              std::move(model)
          ),
          autonomy(autonomy)
    {
    }

    ElectricVehiculeSpecs(
        std::string brand,
        std::string model,
        unsigned int mileAge,
        bool booked,
        int autonomy
    ) : VehiculeSpecs(
            std::move(brand),
            std::move(model),
            mileAge,
            booked
        ),
        autonomy(autonomy)
    {
    }

    [[nodiscard]] int getAutonomy() const;

    void display() const override;

    friend std::ostream& operator<<(
        std::ostream& os,
        const ElectricVehiculeSpecs& specs
    );
};
