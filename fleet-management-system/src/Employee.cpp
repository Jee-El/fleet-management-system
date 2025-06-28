#include "../include/Employee.h"


EmployeeIDCard& Employee::getIDCARD()
{
    return IDCard;
}


const std::vector<std::shared_ptr<Vehicule>>& Employee::
getBookedVehicules() const
{
    return bookedVehicules;
}


bool Employee::hasBookedVehicule(
    const std::shared_ptr<Vehicule>& vehicule
) const
{
    for (const auto& bookedVehicule : bookedVehicules)
    {
        if (bookedVehicule == vehicule) return true;
    }
    return false;
}


void Employee::displayBookings() const
{
    bookedVehicules.at(0)->display();
    for (size_t i = 1; i < bookedVehicules.size(); i++)
    {
        std::cout << *bookedVehicules[i] << std::endl;
    }
}
