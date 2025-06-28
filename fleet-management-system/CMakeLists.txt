cmake_minimum_required(VERSION 3.30)
project(fleet-management-system)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra)

include_directories(include)

add_executable(main
        include/Company.h
        include/CompanyBusinessCard.h
        include/CEO.h
        include/ElectricVehicule.h
        include/ElectricVehiculeSpecs.h
        include/Employee.h
        include/HRManager.h
        include/Fleet.h
        include/FleetManager.h
        include/ForwardDeclarations.h
        include/EmployeeIDCard.h
        include/Vehicule.h
        include/VehiculeSpecs.h
        src/Company.cpp
        src/CompanyBusinessCard.cpp
        src/CEO.cpp
        src/ElectricVehicule.cpp
        src/ElectricVehiculeSpecs.cpp
        src/Employee.cpp
        src/HRManager.cpp
        src/Fleet.cpp
        src/FleetManager.cpp
        src/EmployeeIDCard.cpp
        src/Vehicule.cpp
        src/VehiculeSpecs.cpp
        main.cpp
)
