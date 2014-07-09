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


void analysis(int radius= 3, int energy = 2760){

	TStopwatch timer;
	timer.Start();

	TDatime date;

	gStyle->SetOptStat(0);

	TH1::SetDefaultSumw2();
	TH2::SetDefaultSumw2();

	cout<<"Starting the calculation of the NP correction facrors"<<endl;
	cout<<"Running for Radius = "<<radius<<" and Energy = "<<energy<<endl;

	
	TFile *fin_LO = TFile::Open(Form("rootfiles/GenJet_LO_R23457_%dGeV_July8_Z2Combined.root",energy));
	TFile *fin_HAD = TFile::Open(Form("rootfiles/GenJet_HAD_R23457_%dGeV_July8_Z2Combined.root",energy));

	//get the histograms required. there are a lot here: 

	const int dir = 50;

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

    char etaWidth[dir][256] = {"-1.0<#eta<1.0","-2.0<#eta<2.0","-2.5<#eta<2.0","-2.0<#eta<-1.5",
	"-1.5<#eta<1.0","-1.0<#eta<-0.5","-0.5<eta<0.5","0.5<#eta<1.0",
	"1.0<#eta<1.5","1.5<#eta<2.0",
	"-1.0<#eta<1.0","-2.0<#eta<2.0","-2.5<#eta<2.0","-2.0<#eta<-1.5",
	"-1.5<#eta<1.0","-1.0<#eta<-0.5","-0.5<eta<0.5","0.5<#eta<1.0",
	"1.0<#eta<1.5","1.5<#eta<2.0",
	"-1.0<#eta<1.0","-2.0<#eta<2.0","-2.5<#eta<2.0","-2.0<#eta<-1.5",
	"-1.5<#eta<1.0","-1.0<#eta<-0.5","-0.5<eta<0.5","0.5<#eta<1.0",
	"1.0<#eta<1.5","1.5<#eta<2.0",
	"-1.0<#eta<1.0","-2.0<#eta<2.0","-2.5<#eta<2.0","-2.0<#eta<-1.5",
	"-1.5<#eta<1.0","-1.0<#eta<-0.5","-0.5<eta<0.5","0.5<#eta<1.0",
	"1.0<#eta<1.5","1.5<#eta<2.0",
	"-1.0<#eta<1.0","-2.0<#eta<2.0","-2.5<#eta<2.0","-2.0<#eta<-1.5",
	"-1.5<#eta<1.0","-1.0<#eta<-0.5","-0.5<eta<0.5","0.5<#eta<1.0",
	"1.0<#eta<1.5","1.5<#eta<2.0"};


	// R=0.3 is from dirName 0-9
	// R=0.2 is from dirName 10-19
	// R=0.4 is from dirName 20-29
	// R=0.5 is from dirName 30-39
	// R=0.7 is from dirName 40-49

    TH1F *LO_spectra[dir];
    TH1F *LO_spectraFine[dir]
    TH1F *HAD_spectra[dir];
    TH1F *HAD_spectraFine[dir];

    for(int i = 0;i<dir;i++){

    	LO_spectra[i] = (TH1F*)fin_LO->Get(Form("%s/JetSpectrum",dirName[i]));
    	LO_spectraFine[i] = (TH1F*)fin_LO->Get(Form("%s/JetSpectrum_Fine",dirName[i]));
    	HAD_Spectra[i] = (TH1F*)fin_HAD->Get(Form("%s/JetSpectrum",dirName[i]));
    	HAD_SpectraFine[i] = (TH1F*)fin_HAD->Get(Form("%s/JetSpectrum_Fine",dirName[i]));

    }

    // lets first plot the spectra in a power law fit and see how it looks. 

    //Get the NP factors which are per bin. and then throw them into the text files. 




}
































