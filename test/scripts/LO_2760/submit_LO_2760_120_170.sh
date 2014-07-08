cd /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src
#cmsenv
eval `scramv1 runtime -sh`

cd /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/LO_2760/

cmsRun anaGenJet_LO_cfg.py output="GenJet_LO_R23457_2760_July8_Z2pt120to170.root" maxEvents="100000" processType="NSD" ptHatLow="120" ptHatHigh="170" sqrtS="2760" &> run_LO_2760_120_170.log
