#include <stdlib.h> 
#include <iostream>
#include "analysis/MyHeader.h"

int main(int argc, char ** argv){
  if(argc!=3){
    std::cerr<<"usage: "<<argv[0]<<" Chi2 NDF"<<std::endl;
    return 1;
  }
  CallDummyFunction();
  std::cout << "The P value for a chi2 of "<<argv[1]<<" for NDF of "<<argv[2] 
	    <<" is: "<<CallROOTChi2Calculation(atof(argv[1]), atoi(argv[2])) <<std::endl;
  return 0;
}
