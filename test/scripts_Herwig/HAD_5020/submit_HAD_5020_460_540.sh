cd /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src
#cmsenv
eval `scramv1 runtime -sh`

cd /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts_Herwig/HAD_5020/

cmsRun anaGenJet_HAD_Herwig_cfg.py maxEvents="100000" ptHatLow="460" ptHatHigh="540" &> run_HAD_Herwig5020_460_540.log
