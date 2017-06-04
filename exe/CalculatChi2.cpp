#include <stdlib.h> 
#include <iostream>
#include "TMath.h"

int main(int argc, char ** argv){
  if(argc!=3){
    std::cerr<<"usage: "<<argv[0]<<" Chi2 NDF"<<std::endl;
    return 1;
  }
  std::cout << "The P value for a chi2 of "<<argv[1]<<" for NDF of "<<argv[2] 
	    <<" is: "<<TMath::Prob(atof(argv[1]), atoi(argv[2])) <<std::endl;
  return 0;
}
