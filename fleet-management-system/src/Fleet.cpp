#include "../include/Fleet.h"


std::shared_ptr<std::vector<std::shared_ptr<Vehicule>>> Fleet::
getVehicules() const
{
    return std::make_shared<std::vector<std::shared_ptr<Vehicule>>>(vehicules);
}


std::vector<std::shared_ptr<Vehicule>> Fleet::getBrand(
    const std::string& brand
) const
{
    std::vector<std::shared_ptr<Vehicule>> vehiculesOfBrand;
    for (auto vehicule : vehicules)
    {
        if (vehicule->getSpecs().getBrand() == brand)
        {
            vehiculesOfBrand.push_back(std::move(vehicule)); 
        }
    }
    return vehiculesOfBrand;
}


std::shared_ptr<Vehicule> Fleet::getVehicule(
    const std::string& brand,
    const std::string& model
) const
{
    for (auto& vehicule : vehicules)
    {
        if (
            vehicule->getSpecs().getBrand() == brand
            && vehicule->getSpecs().getModel() == model
        )
        {
            return {vehicule}; 
        }
    }
    throw std::invalid_argument("No such vehicule");
}


std::shared_ptr<Vehicule> Fleet::getVehicule(
    const std::string& brand,
    const std::string& model,
    bool booked
) const
{
    for (auto& vehicule : vehicules)
    {
        if (
            vehicule->getSpecs().getBrand() == brand
            && vehicule->getSpecs().getModel() == model
            && vehicule->getSpecs().isBooked() == booked
        )
        {
            return {vehicule}; 
        }
    }
    throw std::invalid_argument("No such vehicule");
}


std::shared_ptr<Vehicule> Fleet::getVehicule(
    const std::string& brand,
    const std::string& model,
    unsigned int mileAge,
    bool booked
) const
{
    for (auto& vehicule : vehicules)
    {
        if (
            vehicule->getSpecs().getBrand() == brand
            && vehicule->getSpecs().getModel() == model
            && vehicule->getSpecs().getMileAge() == mileAge
            && vehicule->getSpecs().isBooked() == booked
        )
        {
            return {vehicule}; 
        }
    }
    throw std::invalid_argument("No such vehicule");
}


bool Fleet::hasVehicule(const std::shared_ptr<Vehicule>& vehicule) const
{
    return std::any_of(
        vehicules.begin(),
        vehicules.end(),
        [&vehicule](const std::shared_ptr<Vehicule>& v)
        {
            return vehicule == v;
        }
    );
}


bool Fleet::hasVehicule(
    const std::string& brand,
    const std::string& model
) const
{
    return std::any_of(
        vehicules.begin(),
        vehicules.end(),
        [&brand, &model](const std::shared_ptr<Vehicule>& v)
        {
            return v->getSpecs().getBrand() == brand &&
                v->getSpecs().getModel() == model;
        }
    );
}


std::vector<std::shared_ptr<Vehicule>> Fleet::getAvailableVehicules() const
{
    std::vector<std::shared_ptr<Vehicule>> availableVehicules;
    for (auto& vehicule : vehicules)
    {
        if (!vehicule->getSpecs().isBooked())
        {
            availableVehicules.push_back(vehicule);
        }
    }
    return availableVehicules;
}


std::vector<std::shared_ptr<Vehicule>> Fleet::getBookedVehicules() const
{
    std::vector<std::shared_ptr<Vehicule>> availableVehicules;
    for (auto& vehicule : vehicules)
    {
        if (vehicule->getSpecs().isBooked())
        {
            availableVehicules.push_back(vehicule);
        }
    }
    return availableVehicules;
}


void Fleet::displayAvailableVehicules() const
{
    for (const auto& vehicule : vehicules)
    {
        if (!vehicule->getSpecs().isBooked()) { vehicule->display(); }
    }
}


void Fleet::displayBookedVehicules() const
{
    for (const auto& vehicule : vehicules)
    {
        if (vehicule->getSpecs().isBooked()) { vehicule->display(); }
    }
}


void Fleet::display() const
{
    vehicules.at(0)->display(); 
    for (const auto& vehicule : vehicules)
    {
        std::cout << *vehicule << std::endl; 
    }
}