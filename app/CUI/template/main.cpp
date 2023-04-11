#include <iostream>

#include "rtklib.h"
#include <Eigen/Dense>
#include <yaml-cpp/yaml.h>

#include<absl/time/time.h>


int main()
{

    //rtklib
    double t=timeget().sec;


    //eigen
     Eigen::MatrixXd cov;


    //yaml
    YAML::Node config;

    absl::Time  a;




    std::cout << "Hello World!" << std::endl;
    return 0;
}
