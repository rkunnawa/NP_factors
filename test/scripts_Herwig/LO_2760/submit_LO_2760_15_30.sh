cd /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src
#cmsenv
eval `scramv1 runtime -sh`

cd /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts_Herwig/LO_2760/

cmsRun anaGenJet_LO_Herwig_cfg.py maxEvents="100000" ptHatLow="15" ptHatHigh="30" &> run_LO_Herwig2760_15_30.log
