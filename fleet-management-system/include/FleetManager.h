#pragma once
#include <iostream>
#include "ForwardDeclarations.h"
#include "Fleet.h"
#include "Employee.h"

class HRManager;


class FleetManager
{
private:
    friend class HRManager;

    EmployeeIDCard IDCard;
    std::shared_ptr<Fleet> fleet;

public:
    explicit FleetManager(
        EmployeeIDCard IDCard
    ) : IDCard(std::move(IDCard))
    {
    }


    void addVehicule(Vehicule& vehicule);


    void addVehicules(std::vector<Vehicule>&& vehicules);


    void addVehicules(std::vector<ElectricVehicule>&& vehicules);


    void assignVehiculeTo(
        std::shared_ptr<Vehicule> vehicule,
        const std::shared_ptr<Employee>& employee
    );


    void assignVehiculeTo(
        const std::string& brand,
        const std::string& model,
        const std::shared_ptr<Employee>& employee
    );


    void assignVehiculesTo(
        const std::vector<std::array<std::string, 2>>& brandModelCouples,
        const std::shared_ptr<Employee>& employee
    );


    void assignVehiculesTo(
        const std::vector<std::shared_ptr<Vehicule>>& vehicules,
        const std::shared_ptr<Employee>& employee
    );


    std::shared_ptr<Vehicule> unassignVehiculeOf(
        const std::shared_ptr<Vehicule>& vehicule,
        const std::shared_ptr<Employee>& employee
    );


    std::shared_ptr<Vehicule> unassignVehiculeOf(
        const std::string& brand,
        const std::string& model,
        const std::shared_ptr<Employee>& employee
    );


    std::vector<std::shared_ptr<Vehicule>> unassignVehiculesOf(
        const std::vector<std::array<std::string, 2>>& brandModelCouples,
        const std::shared_ptr<Employee>& employee
    );


    std::vector<std::shared_ptr<Vehicule>> unassignVehiculesOf(
        const std::vector<std::shared_ptr<Vehicule>>& vehicules,
        const std::shared_ptr<Employee>& employee
    );


    std::vector<std::shared_ptr<Vehicule>> unassignAllVehiculesOf(
        const std::shared_ptr<Employee>& employee
    );


    void updateVehiculeMileAge(
        const std::shared_ptr<Vehicule>& vehicule,
        unsigned int newMileAge
    );
};
