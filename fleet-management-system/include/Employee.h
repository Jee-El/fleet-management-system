#pragma once
#include <vector>
#include <memory>
#include "ForwardDeclarations.h"
#include "EmployeeIDCard.h"
#include "Vehicule.h"

/**
 * @class Employee
 * @brief Représente un employé dans le système de gestion de flotte.
 *
 * Cette classe gère les informations d'identité d'un employé, représentées par une carte ID (EmployeeIDCard),
 * ainsi que les véhicules qu'il a réservés.
 */
class Employee
{
private:
    friend class FleetManager;

    EmployeeIDCard IDCard;
    std::vector<std::shared_ptr<Vehicule>> bookedVehicules;

public:
    explicit Employee(EmployeeIDCard IDCard) : IDCard(std::move(IDCard))
    {
    }


    [[nodiscard]] EmployeeIDCard& getIDCARD();


    [[nodiscard]] const std::vector<std::shared_ptr<Vehicule>>&
    getBookedVehicules() const;


    bool hasBookedVehicule(const std::shared_ptr<Vehicule>& vehicule) const;


    void displayBookings() const;
};
