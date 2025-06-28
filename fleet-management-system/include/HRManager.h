#pragma once
#include <string>
#include <memory>
#include <vector>

#include "Company.h"

#include "FleetManager.h"

class Company;

class CEO;


class HRManager
{
private:
    friend class CEO;

    std::shared_ptr<Company> company;
    EmployeeIDCard IDCard;

public:
    explicit HRManager(EmployeeIDCard IDCard) : IDCard(std::move(IDCard))
    {
    }


    [[nodiscard]] const EmployeeIDCard& getIDCard() const;


    void setFleetManager(FleetManager&& fleetManager);


    void employEmployee(Employee&& employee);


    void employEmployees(std::vector<Employee>&& employees);


    std::shared_ptr<Employee> fireEmployee(
        const std::shared_ptr<Employee>& employee
    );


    std::vector<std::shared_ptr<Employee>> fireEmployees(
        std::vector<std::shared_ptr<Employee>>&& employees
    );
};
