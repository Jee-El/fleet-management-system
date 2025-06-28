#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

#include "Vehicule.h"
#include "ElectricVehicule.h"


class Fleet
{
private:
    friend class FleetManager;

    std::vector<std::shared_ptr<Vehicule>> vehicules;

public:
    Fleet() = default;


    explicit Fleet(std::vector<std::shared_ptr<Vehicule>>&& vehicules)
        : vehicules(std::move(vehicules))
    {
    }


    [[nodiscard]] std::shared_ptr<std::vector<std::shared_ptr<Vehicule>>>
    getVehicules() const;


    [[nodiscard]] std::vector<std::shared_ptr<Vehicule>> getBrand(
        const std::string& brand
    ) const;


    [[nodiscard]] std::shared_ptr<Vehicule> getVehicule(
        const std::string& brand,
        const std::string& model
    ) const;


    [[nodiscard]] std::shared_ptr<Vehicule> getVehicule(
        const std::string& brand,
        const std::string& model,
        bool booked
    ) const;


    [[nodiscard]] std::shared_ptr<Vehicule> getVehicule(
        const std::string& brand,
        const std::string& model,
        unsigned int mileAge,
        bool booked = false
    ) const;


    [[nodiscard]] bool hasVehicule(
        const std::shared_ptr<Vehicule>& vehicule
    ) const;


    [[nodiscard]] bool hasVehicule(
        const std::string& brand,
        const std::string& model
    ) const;


    [[nodiscard]] std::vector<std::shared_ptr<Vehicule>>
    getAvailableVehicules() const;


    [[nodiscard]] std::vector<std::shared_ptr<Vehicule>>
    getBookedVehicules() const;


    void displayAvailableVehicules() const;


    void displayBookedVehicules() const;


    void display() const;
};
