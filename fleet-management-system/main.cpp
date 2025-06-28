#include <iostream>
#include <vector>
#include "include/CEO.h"
#include "include/Company.h"
#include "include/CompanyBusinessCard.h"
#include "include/ElectricVehicule.h"
#include "include/ElectricVehiculeSpecs.h"
#include "Employee.h"
#include "EmployeeIDCard.h"
#include "Fleet.h"
#include "FleetManager.h"
#include "HRManager.h"
#include "Vehicule.h"
#include "VehiculeSpecs.h"

int main()
{
    std::vector<std::string> NAMES = {
        "Alice Johnson",
        "Bob Smith",
        "Charlie Brown",
        "David Wilson",
        "Eve Davis",
        "Frank Clark",
        "Grace Martinez",
        "Hannah Lopez",
        "Ivy Walker",
        "Jack Taylor"
    };
    std::vector<std::string> POSITIONS = {
        "Tech Lead",
        "Sales",
        "Developer",
        "Developer",
        "Designer",
        "Tester",
        "Marketing",
        "Sales",
        "Support",
        "Intern"
    };

    std::vector<VehiculeSpecs> VEHICULES_SPECS{
            {"Toyota", "Corolla"},
            {"Ford", "Focus"},
            {"Honda", "Civic"},
            {"BMW", "3 Series"},
            {"BMW", "5 Series"},
            {"Audi", "A4"},
            {"Mercedes", "C-Class"},
            {"Chevrolet", "Malibu"},
            {"Nissan", "Altima"},
        };

    const std::vector<ElectricVehiculeSpecs> ELECTRIC_VEHICULES_SPECS{
            {"Tesla", "Model S", 15000, false, 400},
            {"Nissan", "Leaf", 25000, false, 250},
            {"BMW", "i3", 20000, false, 280},
            {"Audi", "e-tron", 5000, false, 300},
        };

    
    CEO ceo("John Doe");

    
    CompanyBusinessCard companyCard{
        "TechFleet Corp.",
        "123 Business Rd.",
        "0123456789",
        "techfleet@example.com"
    };
    ceo.launchCompany(companyCard);
    ceo.makeFleetFor(Fleet{}, companyCard.getName());

    auto company = ceo.getCompany(companyCard.getName());
    std::string companyName = company->getBusinessCard().getName();

    
    EmployeeIDCard HRManagerIDCard{
        companyName,
        static_cast<unsigned int>(company->employeesCount()),
        "Alen Rafael",
        "HR Manager"
    };
    ceo.setHRManagerFor(HRManager(HRManagerIDCard), companyName);
    auto managerOfHR = company->getHRManager();

    
    EmployeeIDCard fleetManagerIDCard{
        companyName,
            static_cast<unsigned int>(company->employeesCount()),
        "Elena Riwes",
        "Fleet Manager"
    };
    managerOfHR->setFleetManager(FleetManager(fleetManagerIDCard));
    
    
    auto fleetManager = company->getFleetManager();
    auto fleet = company->getFleet();

    std::vector<Vehicule> vehicules;
    for (auto spec : VEHICULES_SPECS)
    {
        vehicules.emplace_back(spec);
    }

    fleetManager->addVehicules(std::move(vehicules));

    
    unsigned int currentEmpsCount = static_cast<unsigned int>(company->employeesCount());
    std::vector<Employee> employees;
    for (unsigned int i = 0; i < 10; i++)
    {
        EmployeeIDCard empCard{
            companyCard.getName(),
            currentEmpsCount + i + 1,
            NAMES[i],
            POSITIONS[i],
        };
        employees.emplace_back(empCard);
    }
    company->getHRManager()->employEmployees(std::move(employees));

    company->getFleet()->display();
    std::cout << '\n';


    company->displayEmployees();
    std::cout << '\n';

    std::vector<std::shared_ptr<Vehicule>> vehiculesToBook;
    vehiculesToBook.push_back(fleet->getVehicule("Toyota", "Corolla"));

    for (auto& BMW : fleet->getBrand("BMW"))
    {
        vehiculesToBook.push_back(BMW);
    }

    for (size_t i = 0; i < vehiculesToBook.size(); i++)
    {
        fleetManager->assignVehiculeTo(
            vehiculesToBook[i],
            company->getEmployees()->at(i)
        );
    }

    for (auto& bookedVehicule : fleet->getBookedVehicules())
    {
        fleetManager->updateVehiculeMileAge(bookedVehicule, random() % 100000);
    }

    fleet->display();
    std::cout << '\n';

    std::vector<ElectricVehicule> electricVehicules;
    for (auto& spec : ELECTRIC_VEHICULES_SPECS)
    {
        electricVehicules.emplace_back(spec);
    }
    fleetManager->addVehicules(std::move(electricVehicules));

    fleet->display();
    std::cout << '\n';

    auto firedEmployee = managerOfHR->fireEmployee(company->getEmployees()->at(0));
    std::cout << "Employee " << firedEmployee->getIDCARD().getFullName() << " has been fired, here his full IDCard:" << std::endl;
    std::cout << firedEmployee->getIDCARD() << std::endl;
    std::cout << '\n';

    company->displayEmployees();
    return 0;
}
