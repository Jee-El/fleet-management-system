#pragma once
#include <memory>
#include <vector>
#include "ForwardDeclarations.h"
#include "CompanyBusinessCard.h"
#include "Employee.h"

class CEO;

class Company
{
private:
    friend class CEO;
    friend class HRManager;

    CompanyBusinessCard businessCard;
    std::shared_ptr<HRManager> managerOfHR;
    std::shared_ptr<std::vector<std::shared_ptr<Employee>>> employees =
        std::make_shared<std::vector<std::shared_ptr<Employee>>>();
    std::shared_ptr<FleetManager> fleetManager;
    std::shared_ptr<Fleet> fleet;

public:
    explicit Company(CompanyBusinessCard businessCard) : businessCard(
        std::move(businessCard)
    )
    {
    }

    [[nodiscard]] const CompanyBusinessCard& getBusinessCard() const;

    [[nodiscard]] std::shared_ptr<HRManager> getHRManager() const;

    [[nodiscard]] std::shared_ptr<FleetManager> getFleetManager() const;

    [[nodiscard]] std::shared_ptr<Fleet> getFleet() const;

    [[nodiscard]] std::shared_ptr<std::vector<std::shared_ptr<Employee>>>
    getEmployees() const;

    [[nodiscard]] size_t employeesCount() const;

    void displayEmployees() const;
};
