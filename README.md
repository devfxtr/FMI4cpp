# FMI4cpp (work in progress)

FMI4cpp is a cross-platform FMI 2.0 implementation written in modern C++.

Influenced by it's spiritual brother [FMI4j](https://github.com/SFI-Mechatronics/FMI4j), it aims to be
an easy to install, easy to use, object oriented and fast FMI implementation for C++.    

FMI4cpp supports both CoSimulation and Model Exchange. <br/>
For Model Exchange, solvers from [odeint](http://headmyshoulder.github.io/odeint-v2/doc/boost_numeric_odeint/getting_started/overview.html) can be used. 

### Why should I use this over other C/C++ FMI Libraries

Because this library provides a clean, easy to use API and is easy to install (through vcpkg).


### How do I use it in my own project?

Recommended way is to install [vcpkg](https://github.com/Microsoft/vcpkg) and run:
```
./vcpkg install fmi4cpp
``` 

The alternative is to fetch the dependencies manually, put them in the path somewhere and run the regular CMake install procedures. 


### Development dependencies

Install [vcpkg](https://github.com/Microsoft/vcpkg) and run:

```
./vcpkg install boost-property-tree boost-ublas boost-odeint libzip
``` 

Note that ```boost-ublas``` and ```boost-odeint``` are optional and can be omitted by passing ```-DFMI4CPP_WITH_ODEINT=OFF``` to CMake.

On linux you _might_ need to install some additional libraries:

```
./vcpkg install bzip2 openssl
``` 

These can probably also be installed through the native package handler. 

#### API

```cpp

#include <iostream>
#include <fmi4cpp/fmi2/fmi4cpp.hpp>

using namespace fmi4cpp::fmi2;

const double stop = 10.0;
const double stepSize = 1.0/100;

int main() {

    auto fmu = Fmu("path/to/fmu.fmu").asCoSimulationFmu();
    
    auto md = fmu->getModelDescription();
    std::cout << "modelIdentifier=" << md->modelIdentifier() << std::endl;
    
    auto var = md->getVariableByName("my_var").asRealVariable();
    cout << "Name=" << var.name() << ", start=" var.start().value_or(0) << endl;
    
    auto slave = fmu->newInstance();
    slave->setupExperiment();
    slave->enterInitializationMode();
    slave->exitInitializationMode();
   
    double t;
    double value;
    while ( (t = slave->getSimulationTime()) <= stop) {

        if (!slave->doStep(stepSize)) {
            //error handling
            break;
        }
        
        if (!var.read(*slave, value)) {
            //error handling
            break;
        }
        std::cout << "t=" << t << ", " << var.name() << "=" << value << std::endl;
     
    }
    
    slave->terminate();
    
}
```

***

#### Running examples/tests

In order to run the example/test code, a system variable named __TEST_FMUs__ must be present on your system. 
This variable should point to the location of the content found [here](https://github.com/markaren/TEST_FMUs).

The examples are built by default. To change this pass ```-DFMI4CPP_BUILD_EXAMPLES=OFF``` to CMake.
Test are on the other hand _not_ built by default. To change this pass ```-DFMI4CPP_BUILD_TESTS=ON``` to CMake.

To run the tests you will need an additional dependency:

```
./vcpkg install boost-test
``` 