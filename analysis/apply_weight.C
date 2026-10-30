


void apply_weight(){

TString rootfile = "/u/group/c-nucr/aabhishe/mc-single-arm/worksim/hmsdis_3pass_phaseII_al.root";
TFile *f = TFile::Open(rootfile,"READ");

TTree *t = (TTree*)f->Get("h10");
double weight, xb;
t->SetBranchAddress("weight",&weight);
t->SetBranchAddress("xb",&xb);


TH1D *h1_xb = new TH1D("h1_xb","h1_xb",100,0.2,0.6);
TH1D *h1_xb_weight = new TH1D("h1_xb_weight","h1_xb_weight",100,0.2,0.6);

for(int i=0; i<t->GetEntries(); i++){
    std::cout << "Processing entry: " << i << std::endl;
    std::cout<< "weight: " << weight << std::endl;
    t->GetEntry(i);
    h1_xb->Fill(xb);
    h1_xb_weight->Fill(xb,weight);
}

TCanvas *c1 = new TCanvas("c1","c1",800,600);
h1_xb->Draw();
h1_xb_weight->SetLineColor(kRed);
h1_xb_weight->Draw("SAME");
c1->SaveAs("/u/group/c-nucr/aabhishe/mc-single-arm/Plots/xb_weight.pdf");
}