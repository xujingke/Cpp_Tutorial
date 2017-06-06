#include <stdlib.h> 
#include <iostream>
#include "analysis/MyHeader.h"

int main(int argc, char ** argv){
  if(argc!=2){
    std::cerr<<"usage: "<<argv[0]<<" <ROOT files to process>"<<std::endl;
    return 1;
  }
  FitELifetime(argv[1]);
  return 0;
}
