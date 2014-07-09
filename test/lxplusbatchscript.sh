#!/bin/bash
cd /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src
#cmsenv
eval `scramv1 runtime -sh`

cd /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/

bsub -R "pool>5000" -M 3000000 -q 1nd -J job1 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/LO_2760/submit_LO_2760_0_15.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job2 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/LO_2760/submit_LO_2760_15_30.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job3 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/LO_2760/submit_LO_2760_30_50.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job4 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/LO_2760/submit_LO_2760_50_80.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job5 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/LO_2760/submit_LO_2760_80_120.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job6 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/LO_2760/submit_LO_2760_120_170.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job7 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/LO_2760/submit_LO_2760_170_220.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job8 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/LO_2760/submit_LO_2760_220_280.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job9 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/LO_2760/submit_LO_2760_280_370.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job10 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/LO_2760/submit_LO_2760_370_460.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job11 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/LO_2760/submit_LO_2760_460_540.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job12 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/LO_2760/submit_LO_2760_540_5000.sh

bsub -R "pool>5000" -M 3000000 -q 1nd -J job13 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/LO_5020/submit_LO_5020_0_15.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job14 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/LO_5020/submit_LO_5020_15_30.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job15 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/LO_5020/submit_LO_5020_30_50.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job16 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/LO_5020/submit_LO_5020_50_80.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job17 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/LO_5020/submit_LO_5020_80_120.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job18 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/LO_5020/submit_LO_5020_120_170.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job19 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/LO_5020/submit_LO_5020_170_220.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job20 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/LO_5020/submit_LO_5020_220_280.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job21 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/LO_5020/submit_LO_5020_280_370.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job22 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/LO_5020/submit_LO_5020_370_460.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job23 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/LO_5020/submit_LO_5020_460_540.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job24 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/LO_5020/submit_LO_5020_540_5000.sh

bsub -R "pool>5000" -M 3000000 -q 1nd -J job25 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/HAD_2760/submit_HAD_2760_0_15.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job26 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/HAD_2760/submit_HAD_2760_15_30.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job27 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/HAD_2760/submit_HAD_2760_30_50.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job28 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/HAD_2760/submit_HAD_2760_50_80.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job29 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/HAD_2760/submit_HAD_2760_80_120.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job30 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/HAD_2760/submit_HAD_2760_120_170.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job31 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/HAD_2760/submit_HAD_2760_170_220.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job32 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/HAD_2760/submit_HAD_2760_220_280.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job33 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/HAD_2760/submit_HAD_2760_280_370.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job34 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/HAD_2760/submit_HAD_2760_370_460.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job35 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/HAD_2760/submit_HAD_2760_460_540.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job36 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/HAD_2760/submit_HAD_2760_540_5000.sh

bsub -R "pool>5000" -M 3000000 -q 1nd -J job37 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/HAD_5020/submit_HAD_5020_0_15.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job38 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/HAD_5020/submit_HAD_5020_15_30.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job39 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/HAD_5020/submit_HAD_5020_30_50.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job40 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/HAD_5020/submit_HAD_5020_50_80.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job41 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/HAD_5020/submit_HAD_5020_80_120.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job42 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/HAD_5020/submit_HAD_5020_120_170.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job43 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/HAD_5020/submit_HAD_5020_170_220.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job44 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/HAD_5020/submit_HAD_5020_220_280.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job45 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/HAD_5020/submit_HAD_5020_280_370.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job46 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/HAD_5020/submit_HAD_5020_370_460.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job47 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/HAD_5020/submit_HAD_5020_460_540.sh
bsub -R "pool>5000" -M 3000000 -q 1nd -J job48 < /afs/cern.ch/work/r/rkunnawa/WORK/RAA/pp_genjets_pythia_NPC/CMSSW_5_3_8_HI_patch2/src/Appeltel/GenJetCrossCheckAnalyzer/test/scripts/HAD_5020/submit_HAD_5020_540_5000.sh

echo "submitted all jobs!"
