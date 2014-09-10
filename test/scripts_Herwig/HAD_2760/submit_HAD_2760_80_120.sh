cd /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src
#cmsenv
eval `scramv1 runtime -sh`

cd /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts_Herwig/HAD_2760/

cmsRun anaGenJet_HAD_Herwig_cfg.py maxEvents="100000" ptHatLow="80" ptHatHigh="120" &> run_HAD_Herwig2760_80_120.log
