#include "../include/HRManager.h"


const EmployeeIDCard& HRManager::getIDCard() const
{
    return IDCard;
}


void HRManager::setFleetManager(FleetManager&& fleetManager)
{
    company->fleetManager = std::make_shared<FleetManager>(
        std::move(fleetManager)
    );
    company->getFleetManager()->fleet = company->fleet;
}


void HRManager::employEmployee(Employee&& employee)
{
    if (getIDCard().getCompanyName() != employee.getIDCARD().getCompanyName())
    {
        throw std::invalid_argument("Company name mismatch");
    }

    bool exists = std::any_of(
        company->employees->begin(),
        company->employees->end(),
        [&employee](const std::shared_ptr<Employee>& emp)
        {
            return emp->getIDCARD().getID() == employee.getIDCARD().getID();
        }
    );
    if (!exists)
    {
        this->company->employees->push_back(
            std::make_shared<Employee>(std::move(employee))
        );
    }
    else
    {
        throw std::invalid_argument("The employee is already employed");
    }
}


void HRManager::employEmployees(std::vector<Employee>&& employees)
{
    for (auto& employee : employees)
    {
        employEmployee(std::move(employee));
    }
}


std::shared_ptr<Employee> HRManager::fireEmployee(
    const std::shared_ptr<Employee>& employee
)
{
    for (auto it = company->employees->begin(); it != company->employees->end();
         ++it)
    {
        if (*it == employee)
        {
            employee->getIDCARD().companyName = "";
            company->fleetManager->unassignAllVehiculesOf(employee);
            company->employees->erase(it);
            return employee;
        }
    }
    throw std::invalid_argument("Employee not found");
}


std::vector<std::shared_ptr<Employee>> HRManager::fireEmployees(
    std::vector<std::shared_ptr<Employee>>&& employees
)
{
    std::vector<std::shared_ptr<Employee>> firedEmployees;
    for (auto& employee : employees)
    {
        firedEmployees.push_back(std::move(fireEmployee(employee)));
    }
    return firedEmployees;
}
