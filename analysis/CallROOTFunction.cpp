#include "TMath.h"
#include "analysis/MyHeader.h"

double CallROOTChi2Calculation(double chi2, int ndf){
  return TMath::Prob(chi2, ndf);
}
