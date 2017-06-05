//example of a simple ROOT macro that uses an input parameter
void FitELifetime(const char *fname){
  TChain *events = new TChain("events");
  events->Add(fname);
  events->Draw("pulse_area_phe:z_drift_samples*0.01>>dt(100,0,350, 200,2e3,2e4)", "golden==1 && pulse_classification==2 ", "colz");
  dt->ProfileX();
  dt_pfx->Draw("same");
  TF1 *fexp = new TF1("fexp", "expo", 10, 320);
  dt_pfx->Fit(fexp, "R");
  return;
}
