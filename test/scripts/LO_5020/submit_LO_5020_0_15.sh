cd /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src
#cmsenv
eval `scramv1 runtime -sh`

cd /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/LO_5020/

cmsRun anaGenJet_LO_cfg.py output="GenJet_LO_R23457_5020_July8_Z2pt0to15.root" maxEvents="100000" processType="MB" ptHatLow="0" ptHatHigh="15" sqrtS="5020" &> run_LO_5020_0_15.log
