// Raghav Kunnawalkam Elayavalli
// July 8th 2014
// CERN

//
// Macro to read in the differnet Gen spectra files for 2.76 and 5.02 TeV and LO and HAD to get the inclusive
// jet cross sections. The ratio of HAD/LO will be the non perturbative correction factors. 

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <fstream>
#include <TH1F.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TFile.h>
#include <TTree.h>
#include <TF1.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TFile.h>
#include <TStyle.h>
#include <TStopwatch.h>
#include <TRandom3.h>
#include <TChain.h>
#include <TProfile.h>
#include <TStopwatch.h>
#include <TCut.h>
#include <cstdlib>
#include <cmath>
#include "TLegend.h"
#include "TLatex.h"
#include "TMath.h"
#include "TLine.h"


#include "plot.h"

using namespace std;


static const int dir = 50;


void analysis(int energy = 2760){

	TStopwatch timer;
	timer.Start();

	TDatime date;

	gStyle->SetOptStat(0);

	TH1::SetDefaultSumw2();
	TH2::SetDefaultSumw2();

	cout<<"Starting the calculation of the NP correction facrors"<<endl;
	cout<<"Running for Energy = "<<energy<<endl;
	
	TFile *fin_LO = TFile::Open(Form("GenJet_LO_R23475_%d_Herwig_analyzer_20000_qLimit_15_pthat_1000_20140910.root",energy));
	TFile *fin_HAD = TFile::Open(Form("GenJet_HAD_R23475_%d_Herwig_analyzer_20000_qLimit_15_pthat_1000_20140910.root",energy));

	//get the histograms required. there are a lot here: 


	char dirName[dir][256] = {"ak3GenJetSpectrum_n10_p10","ak3GenJetSpectrum_n20_p20","ak3GenJetSpectrum_n25_n20","ak3GenJetSpectrum_n20_n15",
    "ak3GenJetSpectrum_n15_n10","ak3GenJetSpectrum_n10_n05","ak3GenJetSpectrum_n05_p05","ak3GenJetSpectrum_p05_p10",
    "ak3GenJetSpectrum_p10_p15","ak3GenJetSpectrum_p15_p20",
    "ak2GenJetSpectrum_n10_p10","ak2GenJetSpectrum_n20_p20","ak2GenJetSpectrum_n25_n20","ak2GenJetSpectrum_n20_n15",
    "ak2GenJetSpectrum_n15_n10","ak2GenJetSpectrum_n10_n05","ak2GenJetSpectrum_n05_p05","ak2GenJetSpectrum_p05_p10",
    "ak2GenJetSpectrum_p10_p15","ak2GenJetSpectrum_p15_p20",
    "ak4GenJetSpectrum_n10_p10","ak4GenJetSpectrum_n20_p20","ak4GenJetSpectrum_n25_n20","ak4GenJetSpectrum_n20_n15",
    "ak4GenJetSpectrum_n15_n10","ak4GenJetSpectrum_n10_n05","ak4GenJetSpectrum_n05_p05","ak4GenJetSpectrum_p05_p10",
    "ak4GenJetSpectrum_p10_p15","ak4GenJetSpectrum_p15_p20",
    "ak5GenJetSpectrum_n10_p10","ak5GenJetSpectrum_n20_p20","ak5GenJetSpectrum_n25_n20","ak5GenJetSpectrum_n20_n15",
    "ak5GenJetSpectrum_n15_n10","ak5GenJetSpectrum_n10_n05","ak5GenJetSpectrum_n05_p05","ak5GenJetSpectrum_p05_p10",
    "ak5GenJetSpectrum_p10_p15","ak5GenJetSpectrum_p15_p20",
    "ak7GenJetSpectrum_n10_p10","ak7GenJetSpectrum_n20_p20","ak7GenJetSpectrum_n25_n20","ak7GenJetSpectrum_n20_n15",
    "ak7GenJetSpectrum_n15_n10","ak7GenJetSpectrum_n10_n05","ak7GenJetSpectrum_n05_p05","ak7GenJetSpectrum_p05_p10",
    "ak7GenJetSpectrum_p10_p15","ak7GenJetSpectrum_p15_p20"};

    char etaWidth[dir][256] = {"n10_eta_p10","n20_eta_p20","n25_eta_n20","n20_eta_n15",
	"n15_eta_n10","n10_eta_n05","n05_eta_p05","p05_eta_p10",
	"p10_eta_p15","p15_eta_p20",
	"n10_eta_p10","n20_eta_p20","n25_eta_n20","n20_eta_n15",
	"n15_eta_n10","n10_eta_n05","n05_eta_p05","p05_eta_p10",
	"p10_eta_p15","p15_eta_p20",
	"n10_eta_p10","n20_eta_p20","n25_eta_n20","n20_eta_n15",
	"n15_eta_n10","n10_eta_n05","n05_eta_p05","p05_eta_p10",
	"p10_eta_p15","p15_eta_p20",
	"n10_eta_p10","n20_eta_p20","n25_eta_n20","n20_eta_n15",
	"n15_eta_n10","n10_eta_n05","n05_eta_p05","p05_eta_p10",
	"p10_eta_p15","p15_eta_p20",
	"n10_eta_p10","n20_eta_p20","n25_eta_n20","n20_eta_n15",
	"n15_eta_n10","n10_eta_n05","n05_eta_p05","p05_eta_p10",
	"p10_eta_p15","p15_eta_p20"
	};

	char radius_lable[dir][256] = {"R3","R3","R3","R3","R3","R3","R3","R3","R3","R3",
	"R2","R2","R2","R2","R2","R2","R2","R2","R2","R2",
	"R4","R4","R4","R4","R4","R4","R4","R4","R4","R4",
	"R5","R5","R5","R5","R5","R5","R5","R5","R5","R5",
	"R7","R7","R7","R7","R7","R7","R7","R7","R7","R7"};

	// R=0.3 is from dirName 0-9
	// R=0.2 is from dirName 10-19
	// R=0.4 is from dirName 20-29
	// R=0.5 is from dirName 30-39
	// R=0.7 is from dirName 40-49

    TH1F *LO_spectra[dir];
    TH1F *LO_spectraFine[dir];
    TH1F *HAD_spectra[dir];
    TH1F *HAD_spectraFine[dir];

    TH1F *NPC[dir];
    TH1F *NPC_fine[dir];

    for(int i = 0;i<dir;i++){

    	LO_spectra[i] = (TH1F*)fin_LO->Get(Form("%s/spectrum",dirName[i]));
    	LO_spectraFine[i] = (TH1F*)fin_LO->Get(Form("%s/spectrum_Fine",dirName[i]));
    	HAD_spectra[i] = (TH1F*)fin_HAD->Get(Form("%s/spectrum",dirName[i]));
    	HAD_spectraFine[i] = (TH1F*)fin_HAD->Get(Form("%s/spectrum_Fine",dirName[i]));

    	NPC[i] = (TH1F*)HAD_spectra[i]->Clone(Form("NPC_%s",dirName[i]));
    	NPC[i]->Divide(LO_spectra[i]);
    }

    char radius_title[5][256] = {"R3","R2","R4","R5","R7"};

    TLine *line = new TLine(50,1,300,1);
    line->SetLineStyle(2);
    line->SetLineWidth(2);
/*
    // one for each radius
    TCanvas *cSpectraCheck[5];

    for(int i = 1;i<=5;i++){

    	cSpectraCheck[i] = new TCanvas(Form("cSpectraCheck_%d",i),Form("NP correction factors for ak %s GenJet with energy %d",radius_title[i-1],energy),1200,800);
    	cSpectraCheck[i]->Divide(5,2);
        //cSpectraCheck[i]->SetLogx();

    	for(int j = 1;j<=10;j++){

    		cSpectraCheck[i]->cd(j);
            cSpectraCheck[i]->cd(j)->SetLogx();

    		drawText(Form("%s_%s",etaWidth[(i-1)*10+j-1],radius_title[i]),0.1,0.9,20);
    		line->Draw();
    		NPC[(i-1)*10+j-1]->SetMarkerStyle(33);
    		NPC[(i-1)*10+j-1]->SetMarkerColor(kBlack);
    		NPC[(i-1)*10+j-1]->SetTitle(Form("%s %s",etaWidth[(i-1)*10+j-1],radius_title[i-1]));
    		NPC[(i-1)*10+j-1]->SetXTitle("Jet p_{T} (GeV/c)");
    		NPC[(i-1)*10+j-1]->SetYTitle("correction factor");
            TF1 *f1 = new TF1("f1","[0]+[1]*x+[2]*x*x+[3]*x*x*x+[4]*x*x*x*x");
            NPC[(i-1)*10+j-1]->Fit("f1","","",30,500);
            NPC[(i-1)*10+j-1]->Fit("f1","","",30,500);
            NPC[(i-1)*10+j-1]->Fit("f1","","",30,500);
            NPC[(i-1)*10+j-1]->Fit("f1","","",30,500);
            NPC[(i-1)*10+j-1]->SetAxisRange(20,600,"X");
    		NPC[(i-1)*10+j-1]->Draw();
    	}

    	cSpectraCheck[i]->SaveAs(Form("/afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/plots/NPC_factors_ak_%s_energy_%d.pdf",radius_title[i-1],energy),"RECREATE");

    }
*/
    TH1F *NPC_abs_eta[5][4]; 
    for(int i = 0;i<5;i++){
        NPC_abs_eta[i][0] = (TH1F*)NPC[i*10+6]->Clone(Form("NPC_%s_abs_eta_0_05",radius_title[i]));
        NPC_abs_eta[i][1] = (TH1F*)NPC[i*10+5]->Clone(Form("NPC_%s_abs_eta_05_10",radius_title[i]));
        NPC_abs_eta[i][1]->Scale(1./2);
        NPC[i*10+7]->Scale(1./2);
        NPC_abs_eta[i][1]->Add(NPC[i*10+7]);
        NPC_abs_eta[i][2] = (TH1F*)NPC[i*10+4]->Clone(Form("NPC_%s_abs_eta_10_15",radius_title[i]));
        NPC_abs_eta[i][2]->Scale(1./2);
        NPC[i*10+8]->Scale(1./2);
        NPC_abs_eta[i][2]->Add(NPC[i*10+8]);
        NPC_abs_eta[i][3] = (TH1F*)NPC[i*10+3]->Clone(Form("NPC_%s_abs_eta_15_20",radius_title[i]));
        NPC_abs_eta[i][3]->Scale(1./2);
        NPC[i*10+9]->Scale(1./2);
        NPC_abs_eta[i][3]->Add(NPC[i*10+9]);
    }
    char absEta[4][256] = {"0.0<|#eta|<0.5","0.5<|#eta|<1.0","1.0<|#eta|<1.5","1.5<|#eta|<2.0"};

    TCanvas *cNPC_Abs[5];

    for(int i = 0;i<5;i++){

        cNPC_Abs[i] = new TCanvas(Form("cNPC_Abs_%d",i),Form("NP correction factors from Herwig++ for %s GenJet with energy %d",radius_title[i],energy),1200,800);
        cNPC_Abs[i]->Divide(3,2);
        for(int j = 0;j<4;j++){

            cNPC_Abs[i]->cd(j+1);
            cNPC_Abs[i]->cd(j+1)->SetLogx();

            drawText(Form("%s_%s",absEta[j],radius_title[i]),0.1,0.9,20);
            line->Draw();
            NPC_abs_eta[i][j]->SetMarkerStyle(33);
            NPC_abs_eta[i][j]->SetMarkerColor(kBlack);
            NPC_abs_eta[i][j]->SetTitle(Form("%s_%s",absEta[j],radius_title[i]));
            NPC_abs_eta[i][j]->SetXTitle("Jet p_{T} (GeV/c)");
            NPC_abs_eta[i][j]->SetYTitle("correction factor");
            //NPC_abs_eta[i][j]->Scale(1./2);
            //TF1 *f2 = new TF1("f2","[0]+[1]*x+[2]*x*x+[3]*x*x*x+[4]*x*x*x*x");
            TF1 *f2 = new TF1("f2","1-[0]/pow(x,[1])");
            NPC_abs_eta[i][j]->Fit("f2","","",30,500);
            NPC_abs_eta[i][j]->Fit("f2","","",30,500);
            NPC_abs_eta[i][j]->Fit("f2","","",30,500);
            NPC_abs_eta[i][j]->Fit("f2","","",30,500);
            NPC_abs_eta[i][j]->SetAxisRange(20,600,"X");
            NPC_abs_eta[i][j]->Draw();
        }
        cNPC_Abs[i]->SaveAs(Form("/afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/plots/NPC_factors_Herwigpp_absEta_ak_%s_energy_%d.pdf",radius_title[i],energy));
    }
    
    
    //create the text files. 
    ofstream NPC_txt[dir];
    for(int i = 0;i<dir;i++){
    	NPC_txt[i].open(Form("txtfiles/NPC_Herwig_ak_%s_%s_energy%d.txt",radius_lable[i],etaWidth[i],energy));

    	for(int j = 0;j<NPC[0]->GetNbinsX();j++){
    		float bincenter = NPC[i]->GetBinCenter(j);
    		NPC_txt[i]<<bincenter<<" "<<NPC[i]->GetBinContent(j)<<endl;
    	}

    	//NPC_txt.Close();

    }

    cout<<"finished writing the text files"<<endl;
    


}
































