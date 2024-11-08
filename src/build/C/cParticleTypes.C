#ifdef __CLING__
#pragma cling optimize(0)
#endif
void cParticleTypes()
{
//=========Macro generated from canvas: cParticleTypes/Particle types
//=========  (Fri Nov  8 15:43:53 2024) by ROOT version 6.28/06
   TCanvas *cParticleTypes = new TCanvas("cParticleTypes", "Particle types",0,0,800,600);
   gStyle->SetOptFit(1);
   cParticleTypes->Range(-0.8750001,-524978.5,7.875,4724806);
   cParticleTypes->SetFillColor(0);
   cParticleTypes->SetBorderMode(0);
   cParticleTypes->SetBorderSize(2);
   cParticleTypes->SetFrameBorderMode(0);
   cParticleTypes->SetFrameBorderMode(0);
   
   TH1I *hParticleTypes__1 = new TH1I("hParticleTypes__1","Particle types",7,0,7);
   hParticleTypes__1->SetBinContent(1,3999425);
   hParticleTypes__1->SetBinContent(2,3999836);
   hParticleTypes__1->SetBinContent(3,498035);
   hParticleTypes__1->SetBinContent(4,499703);
   hParticleTypes__1->SetBinContent(5,451188);
   hParticleTypes__1->SetBinContent(6,451095);
   hParticleTypes__1->SetBinContent(7,100718);
   hParticleTypes__1->SetEntries(1e+07);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.755,0.98,0.995,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   TText *ptstats_LaTex = ptstats->AddText("hParticleTypes");
   ptstats_LaTex->SetTextSize(0.0552);
   ptstats_LaTex = ptstats->AddText("Entries =          1e+07");
   ptstats_LaTex = ptstats->AddText("Mean  =  1.116");
   ptstats_LaTex = ptstats->AddText("Std Dev   =   1.42");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(111);
   ptstats->Draw();
   hParticleTypes__1->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(hParticleTypes__1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hParticleTypes__1->SetLineColor(ci);
   hParticleTypes__1->GetXaxis()->SetBinLabel(1,"pi+");
   hParticleTypes__1->GetXaxis()->SetBinLabel(2,"pi-");
   hParticleTypes__1->GetXaxis()->SetBinLabel(3,"K+");
   hParticleTypes__1->GetXaxis()->SetBinLabel(4,"K-");
   hParticleTypes__1->GetXaxis()->SetBinLabel(5,"p+");
   hParticleTypes__1->GetXaxis()->SetBinLabel(6,"p-");
   hParticleTypes__1->GetXaxis()->SetBinLabel(7,"K*");
   hParticleTypes__1->GetXaxis()->SetLabelFont(42);
   hParticleTypes__1->GetXaxis()->SetTitleOffset(1);
   hParticleTypes__1->GetXaxis()->SetTitleFont(42);
   hParticleTypes__1->GetYaxis()->SetTitle("Entries");
   hParticleTypes__1->GetYaxis()->SetLabelFont(42);
   hParticleTypes__1->GetYaxis()->SetTitleFont(42);
   hParticleTypes__1->GetZaxis()->SetLabelFont(42);
   hParticleTypes__1->GetZaxis()->SetTitleOffset(1);
   hParticleTypes__1->GetZaxis()->SetTitleFont(42);
   hParticleTypes__1->Draw("");
   
   TPaveText *pt = new TPaveText(0.01,0.9404546,0.2498492,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(1);
   pt->SetFillColor(0);
   TText *pt_LaTex = pt->AddText("Particle types");
   pt->Draw();
   cParticleTypes->Modified();
   cParticleTypes->cd();
   cParticleTypes->SetSelected(cParticleTypes);
}
