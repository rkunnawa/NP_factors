{

  char energy[256] = "5020";
  char order[256] = "HAD";
  //const int MAXDIR = 61;
  const int MAXDIR = 50;

  // cross sections from the Pythia simulations:

  // Z2 cross sections

  // for 2.76 TeV
  //double xsec[10] = {6.198e+01, 5.135e-02, 9.742e-03, 9.250e-04,
  //                   8.812e-05, 9.771e-06, 1.256e-06, 1.795e-07,
  //                   2.708e-08, 4.735e-09};
  //2.76 these below are the exact values for the different pthats mentioned below. have to subtract them to get what we want. 
  //double xsec[10] = {2.034e-01,1.075e-02,1.025e-03,9.865e-05,1.465e-06,2.837e-07,5.323e-08,5.934e-09,8.125e-10,1.467e-10};
  // following is correct
  //double xsec[12] = {0.7966,0.19265,0.009725,0.00092635,8.736e-05,9.825e-06,1.1813e-06,2.3047e-07,4.7296e-08,5.1215e-09,6.658e-10,1.467e-10};
  // following is added to check for the initial pthat process 
  //double xsec[12] = {2.034e-01,0.19265,0.009725,0.00092635,8.736e-05,9.825e-06,1.1813e-06,2.3047e-07,4.7296e-08,5.1215e-09,6.658e-10,1.467e-10};
  //double xsec[12] = {61.77,0.19265,0.009725,0.00092635,8.736e-05,9.825e-06,1.1813e-06,2.3047e-07,4.7296e-08,5.1215e-09,6.658e-10,1.467e-10};

  //getting it from the log files 
  //double xsec[12] = {6.198e01,1.921e-01,9.771e-03,9.253e-04,8.793e-05,9.766e-06,1.185e-06,2.310e-07,4.721e-08,5.128e-09,6.647e-10,1.483e-10};

  // for 5.02 TeV
  //double xsec[10] = {6.782e+01, 1.405e-01, 2.995e-02, 3.334e-03,
  //                  3.800e-04, 5.138e-05, 8.251e-06, 1.525e-06,
  //                   3.141e-07, 9.160e-08};
  //5.02 new, the last value here is wrong. make sure of that. and this doesnt have pthat value 540. remove that when running this for 5.02TeV  
  // double xsec[10] = {5.335e-01,3.378E-02,3.778E-03,4.412E-04,6.147E-05,1.018E-05,2.477E-06,6.160E-07,1.088E-07,2.527E-08,1.467E-10};
  // double xsec[11] = {1.8695,0.49972,0.030002,0.0033368,0.00037973,5.129e-05,7.703e-06,1.861e-06,5.072e-07,8.353e-08,2.527e-08};
  // getting the cross section from the log files 
  double xsec[12] = {6.782e01,4.988e-01,2.988e-02,3.329e-03,3.801e-04,5.183e-05,7.695e-06,1.863e-06,5.051e-07,8.381e-08,1.727e-08,7.847e-09};



  // for 7 TeV
  //double xsec[10] = {7.131e+01, 2.359e-01, 5.307e-02, 6.354e-03,
  //                   7.837e-04, 1.152e-04, 2.015e-05, 4.094e-06,
  //                   9.351e-07, 3.221e-07};
  
  //the ones here were the old values. adding the new values 

  // need to fix first entry given as 0-inf. Subtract all 
  // other xsecs to get 0-20
  double xsec15toinf = 0.0;
  double totalxsec = xsec[0];
  for( int i=1;i<12;i++) xsec15toinf += xsec[i];
  xsec[0] = xsec[0] - xsec15toinf;

  // open files and get spectra and event counts 
  TFile * f[12];
  char rpthats[12][256] = {"0to15","15to30","30to50","50to80","80to120","120to170","170to220","220to280","280to370","370to460","460to540","540to5000"};
  //char rpthats[12][256] = {"0to15","15to30","30to50","50to80","80to120","120to170","170to220","220to280","280to370","370to460","460to540","540to5000"};

  char dirname[MAXDIR][256] = {
    "ak3GenJetSpectrum_n10_p10","ak3GenJetSpectrum_n20_p20","ak3GenJetSpectrum_n25_n20","ak3GenJetSpectrum_n20_n15",
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
    "ak7GenJetSpectrum_p10_p15","ak7GenJetSpectrum_p15_p20"
    };

  double etaWid[MAXDIR] = { 2.0,4.0,0.5,0.5,0.5,0.5,1.0,0.5,0.5,0.5,
                            2.0,4.0,0.5,0.5,0.5,0.5,1.0,0.5,0.5,0.5,
                            2.0,4.0,0.5,0.5,0.5,0.5,1.0,0.5,0.5,0.5,
                            2.0,4.0,0.5,0.5,0.5,0.5,1.0,0.5,0.5,0.5,
                            2.0,4.0,0.5,0.5,0.5,0.5,1.0,0.5,0.5,0.5
  };

  // retrieve and normalize spectra
  TH1F * spectrum[12][MAXDIR];
  TH1F * spectrumf[12][MAXDIR];
  TH1F * events[12][MAXDIR];
  double nevt[12][MAXDIR]; 
  for( int i=0; i<12;i++)
  {
    //do it once for HAD and once for LO
    f[i] = new TFile(Form("rootfiles/GenJet_%s_R23457_%s_July8_Z2pt%s_numEvent100000.root",order,energy,rpthats[i]));
    for( int j=0; j<MAXDIR; j++)
    {
      events[i][j] = (TH1F *) f[i]->Get(Form("%s/events",dirname[j]));
      events[i][j]->SetName(Form("events_%d_%d",i,j));
      nevt[i][j] = events[i][j]->GetBinContent(1);
      spectrum[i][j] = (TH1F *) f[i]->Get(Form("%s/%s",dirname[j],"spectrum"));
      spectrum[i][j]->SetName(Form("spectrum_%d_%d",i,j));
      spectrum[i][j]->Sumw2();
      spectrumf[i][j] = (TH1F *) f[i]->Get(Form("%s/%s",dirname[j],"spectrum_fine"));
      spectrumf[i][j]->SetName(Form("spectrum_fine_%d_%d",i,j));
      spectrumf[i][j]->Sumw2();
      for( int bin = 1; bin <= spectrum[i][j]->GetNbinsX(); bin++)
      {
        double ptWid = spectrum[i][j]->GetBinWidth(bin);
        spectrum[i][j]->SetBinContent(bin,
                       spectrum[i][j]->GetBinContent(bin) 
                       / ptWid / etaWid[j] * xsec[i] / nevt[i][j] ); 
        spectrum[i][j]->SetBinError(bin,
                       spectrum[i][j]->GetBinError(bin) 
                       / ptWid / etaWid[j] * xsec[i] / nevt[i][j]  ); 
      }
      for( int bin = 1; bin <= spectrumf[i][j]->GetNbinsX(); bin++)
      {
        double ptWid = spectrumf[i][j]->GetBinWidth(bin);
        spectrumf[i][j]->SetBinContent(bin,
                       spectrumf[i][j]->GetBinContent(bin)
                       / ptWid / etaWid[j] * xsec[i] / nevt[i][j] );
        spectrumf[i][j]->SetBinError(bin,
                       spectrumf[i][j]->GetBinError(bin)
                       / ptWid / etaWid[j] * xsec[i] / nevt[i][j]  );
      }
    }
  }

  // add spectra
  TH1F * spectrum_out[MAXDIR];
  TH1F * spectrumf_out[MAXDIR];

  TFile * f_out = new TFile(Form("rootfiles/GenJet_%s_R23457_%sGeV_July9_Z2Combined.root",order,energy),"RECREATE");

  for( int j=0;j<MAXDIR;j++)
  {
    TDirectory * tdir = f_out->mkdir(dirname[j]);
    for( int i=1;i<12;i++) spectrum[0][j]->Add(spectrum[i][j],1.0);
    for( int i=1;i<12;i++) spectrumf[0][j]->Add(spectrumf[i][j],1.0);
    spectrum_out[j] =  (TH1F *) spectrum[0][j]->Clone(Form("JetSpectrum"));
    spectrum_out[j]->SetDirectory(tdir);
    spectrumf_out[j] = (TH1F *) spectrumf[0][j]->Clone(Form("JetSpectrum_Fine"));
    spectrumf_out[j]->SetDirectory(tdir);
  }

  f_out->Write();

}
