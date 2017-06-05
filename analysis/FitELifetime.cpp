//example of a ROOT macro that complies with C++ standard

#include <iostream>
#include "TChain.h"
#include "TH1F.h"
#include "TF1.h"
#include "TDirectory.h"
#include "TH1D.h"
#include "TH2F.h"

void FitELifetime(const char *fname){
  TChain *events = new TChain("events");
  int nfiles = events->Add(fname);
  if(nfiles<1){
    std::cout<<"Unable to load ROOT files into events TChain."<<std::endl;
    return;
  }
  events->Draw("pulse_area_phe:z_drift_samples*0.01>>dt(100,0,350, 200,2e3,2e4)", "golden==1 && pulse_classification==2 ", "colz");
  TH2F *dt = (TH2F*)(gDirectory->Get("dt"));
  if(!dt || dt->IsZombie()){
    std::cout<<"2D histogram did not draw correctly."<<std::endl;
    delete events;
    return;
  }

  dt->FitSlicesY();
  TH2F *dt_1 = (TH2F*)(gDirectory->Get("dt_1"));
  if(!dt_1 || dt_1->IsZombie()){
    std::cout<<"FitSlicesY() failed."<<std::endl;
    delete events;
    return;
  }

  dt_1->Draw("same");

  TF1 *fexp = new TF1("fexp", "expo", 10, 320);
  dt_1->Fit(fexp, "R");

  double elifetime = fexp->GetParameter(1);
  if(elifetime!=0) std::cout<<"Electron lifetime fit result: "<<-1./elifetime<<std::endl;

  return;
}
