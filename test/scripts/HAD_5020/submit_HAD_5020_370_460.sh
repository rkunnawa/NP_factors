cd /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src
#cmsenv
eval `scramv1 runtime -sh`

cd /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/HAD_5020/

cmsRun anaGenJet_HAD_cfg.py output="GenJet_HAD_R23457_5020_July8_Z2pt370to460.root" maxEvents="100000" processType="NSD" ptHatLow="370" ptHatHigh="460" sqrtS="5020" &> run_HAD_5020_370_460.log
