cd /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src
#cmsenv
eval `scramv1 runtime -sh`

cd /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/HAD_2760/

cmsRun anaGenJet_HAD_cfg.py output="GenJet_HAD_R23457_2760_July8_Z2pt50to80.root" maxEvents="100000" processType="NSD" ptHatLow="50" ptHatHigh="80" sqrtS="2760" &> run_HAD_2760_50_80.log
