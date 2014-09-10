cd /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src
#cmsenv
eval `scramv1 runtime -sh`

cd /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts_Herwig/HAD_5020/

cmsRun anaGenJet_HAD_Herwig_cfg.py maxEvents="100000" qLimit="20000" ptHatLow="0" ptHatHigh="15" &> run_HAD_Herwig5020_0_15.log
