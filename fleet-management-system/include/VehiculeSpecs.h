#pragma once
#include <string>
#include <utility>
#include <iostream>
#include <iomanip>

class FleetManager;


struct VehiculeSpecs
{
    friend class FleetManager;

private:
    const std::string brand;
    const std::string model;
    unsigned int mileAge{};
    bool booked{};

protected:
    virtual void print(std::ostream& os) const;

public:
    virtual ~VehiculeSpecs() = default;


    VehiculeSpecs(std::string brand, std::string model)
        : brand(std::move(brand)), model(std::move(model))
    {
    }


    VehiculeSpecs(
        std::string brand,
        std::string model,
        unsigned int mileAge,
        bool booked
    ) : brand(std::move(brand)),
        model(std::move(model)),
        mileAge(mileAge),
        booked(booked)
    {
    }


    [[nodiscard]] const std::string& getBrand() const;


    [[nodiscard]] const std::string& getModel() const;


    [[nodiscard]] unsigned int getMileAge() const;


    [[nodiscard]] bool isBooked() const;


    virtual void display() const;


    friend std::ostream& operator<<(
        std::ostream& os,
        const VehiculeSpecs& specs
    );
};
