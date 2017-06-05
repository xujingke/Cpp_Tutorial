//an example of ROOT Macro that is a collection of simple commands
void FitExpGaus(){
  TH1F *h1 = new TH1F("h1","h1",100,0,10);
  TF1 *fexp = new TF1("fexp","expo", 0,10);
  TF1 *fgaus = new TF1("fgaus","gaus", 0,10);
  fexp->SetParameters(1,-0.2);
  fgaus->SetParameters(1,5,0.5);
  h1->FillRandom("fexp",5000);
  h1->FillRandom("fgaus",500);
  TF1 *ffit = new TF1("ffit","expo(0)+gaus(2)", 0, 10);
  ffit->SetParameters(5, -0.5, 100, 4.5, 0.3);
  h1->Fit("ffit", "REM+");
  double p0 = ffit->GetParameter(0);
  ffit->SetParameter(0,-100);
  ffit->SetLineColor(kGreen);
  ffit->DrawCopy("same");
  ffit->SetParameter(0,p0);
  ffit->SetParameter(2,0);
  ffit->SetLineColor(kBlack);
  ffit->DrawCopy("same");
}
