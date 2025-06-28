#include "../include/Company.h"


const CompanyBusinessCard& Company::getBusinessCard() const
{
    return businessCard;
}


std::shared_ptr<HRManager> Company::getHRManager() const
{
    return {managerOfHR};
}


std::shared_ptr<FleetManager> Company::getFleetManager() const
{
    return {fleetManager};
}


std::shared_ptr<Fleet> Company::getFleet() const
{
    return {fleet};
}


std::shared_ptr<std::vector<std::shared_ptr<Employee>>> Company::
getEmployees() const
{
    return {employees};
}


size_t Company::employeesCount() const
{
    return employees->size();
}


void Company::displayEmployees() const
{
    employees->at(0)->getIDCARD().display();
    for (size_t i = 1; i < employees->size(); ++i)
    {
        std::cout << employees->at(i)->getIDCARD() << std::endl;
    }
}
