#include "../include/FleetManager.h"


void FleetManager::addVehicule(Vehicule& vehicule)
{
    if (const ElectricVehicule* eVehicule = dynamic_cast<const ElectricVehicule*>(&vehicule))
    {
        fleet->vehicules.push_back(
            std::make_shared<ElectricVehicule>(*eVehicule)
        );
    }
    else
    {
        fleet->vehicules.push_back(
            std::make_shared<Vehicule>(vehicule)
        );
    }
}


void FleetManager::addVehicules(std::vector<Vehicule>&& vehicules)
{
    for (auto& vehicule : vehicules)
    {
        addVehicule(vehicule); 
    }
}


void FleetManager::addVehicules(std::vector<ElectricVehicule>&& vehicules)
{
    for (auto& vehicule : vehicules)
    {
        addVehicule(vehicule); 
    }
}


void FleetManager::assignVehiculeTo(
    std::shared_ptr<Vehicule> vehicule,
    const std::shared_ptr<Employee>& employee
)
{
    if (!fleet->hasVehicule(vehicule))
        throw std::invalid_argument(
            "Vehicule does not exist in the fleet"
        );
    if (vehicule->getSpecs().booked)
        throw std::invalid_argument(
            "Vehicule is already assigned to an employee"
        );

    vehicule->specs.booked = true; 
    employee->bookedVehicules.push_back(std::move(vehicule)); 
}


void FleetManager::assignVehiculeTo(
    const std::string& brand,
    const std::string& model,
    const std::shared_ptr<Employee>& employee
)
{
    auto vehicule = fleet->getVehicule(brand, model);
    if (vehicule->getSpecs().booked)
        throw std::invalid_argument(
            "Vehicule is already assigned to an employee"
        );

    vehicule->specs.booked = true;
    employee->bookedVehicules.push_back(std::move(vehicule));
}


void FleetManager::assignVehiculesTo(
    const std::vector<std::shared_ptr<Vehicule>>& vehicules,
    const std::shared_ptr<Employee>& employee
)
{
    for (auto& vehicule : vehicules)
    {
        assignVehiculeTo(vehicule, employee); 
    }
}


void FleetManager::assignVehiculesTo(
    const std::vector<std::array<std::string, 2>>& brandModelCouples,
    const std::shared_ptr<Employee>& employee
)
{
    for (const auto& brandModelCouple : brandModelCouples)
    {
        assignVehiculeTo(
            brandModelCouple.at(0),
            brandModelCouple.at(1),
            employee
        );
    }
}


std::shared_ptr<Vehicule> FleetManager::unassignVehiculeOf(
    const std::shared_ptr<Vehicule>& vehicule,
    const std::shared_ptr<Employee>& employee
)
{
    if (!employee->hasBookedVehicule(vehicule)) throw std::invalid_argument(
        "Vehicule is not booked by Employee"
    );

    for (auto it = employee->bookedVehicules.begin(); it != employee->
         bookedVehicules.end(); ++it)
    {
        if (*it == vehicule)
        {
            vehicule->specs.booked = false; 
            employee->bookedVehicules.erase(it); 
            return vehicule;
        }
    }
    throw std::invalid_argument("Vehicule is not assigned to Employee");
}


std::shared_ptr<Vehicule> FleetManager::unassignVehiculeOf(
    const std::string& brand,
    const std::string& model,
    const std::shared_ptr<Employee>& employee
)
{
    return unassignVehiculeOf(fleet->getVehicule(brand, model), employee);
}


std::vector<std::shared_ptr<Vehicule>> FleetManager::unassignVehiculesOf(
    const std::vector<std::array<std::string, 2>>& brandModelCouples,
    const std::shared_ptr<Employee>& employee
)
{
    std::vector<std::shared_ptr<Vehicule>> unassignedVehicules;
    for (const auto& brandModelCouple : brandModelCouples)
    {
        unassignedVehicules.push_back(
            std::move(
                unassignVehiculeOf(
                    brandModelCouple[0],
                    brandModelCouple[1],
                    employee
                )
            )
        );
    }
    return unassignedVehicules;
}


std::vector<std::shared_ptr<Vehicule>> FleetManager::unassignVehiculesOf(
    const std::vector<std::shared_ptr<Vehicule>>& vehicules,
    const std::shared_ptr<Employee>& employee
)
{
    std::vector<std::shared_ptr<Vehicule>> unassignedVehicules;
    for (auto& vehicule : vehicules)
    {
        unassignedVehicules.push_back(
            std::move(unassignVehiculeOf(vehicule, employee))
        );
    }
    return unassignedVehicules;
}


std::vector<std::shared_ptr<Vehicule>> FleetManager::unassignAllVehiculesOf(
    const std::shared_ptr<Employee>& employee
)
{
    std::vector<std::shared_ptr<Vehicule>> unassignedVehicules;
    for (const auto& bookedVehicule : employee->bookedVehicules)
    {
        bookedVehicule->specs.booked = false; 
        unassignedVehicules.push_back(std::move(bookedVehicule)); 
    }
    employee->bookedVehicules.clear(); 
    return unassignedVehicules; 
}


void FleetManager::updateVehiculeMileAge(
    const std::shared_ptr<Vehicule>& vehicule,
    unsigned int newMileAge
)
{
    if (!fleet->hasVehicule(vehicule))
        throw std::invalid_argument(
            "Vehicule does not exist in the fleet"
        );
    vehicule->specs.mileAge = newMileAge; 
}
