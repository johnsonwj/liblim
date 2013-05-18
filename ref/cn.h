//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Apr 29 14:03:37 2013 by ROOT version 5.34/05
// from TTree tau/NTuple output of AnalysisFramework
// found on file: group.phys-higgs.290557_002277._00020.merge.ntuple.root
//////////////////////////////////////////////////////////

#ifndef cn_h
#define cn_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class cn {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Float_t         evtsel_averageIntPerXing;
   Int_t           evtsel_vertices;
   Int_t           evtsel_vertices_three;
   Float_t         evtsel_weight;
   Float_t         evtsel_weight_PU;
   Float_t         evtsel_weight_lep;
   Float_t         evtsel_weight_lep_reco;
   Float_t         evtsel_weight_lep_id;
   Float_t         evtsel_weight_lep_trigger;
   Float_t         evtsel_weight_lep_iso;
   Float_t         evtsel_weight_tau_el_overlap;
   Float_t         evtsel_weight_tau_id;
   Float_t         evtsel_weight_SLT;
   Float_t         evtsel_weight_LTT;
   Float_t         evtsel_weight_tau_trigger;
   Float_t         evtsel_weight_FF_SLT;
   Float_t         evtsel_weight_FF_LTT;
   Float_t         evtsel_weight_dEta;
   Float_t         evtsel_EmbTightIso_weight;
   Float_t         evtsel_EmbNoIso_weight;
   Float_t         evtsel_Emb_tes_up_weight;
   Float_t         evtsel_Emb_tes_dn_weight;
   Float_t         evtsel_Emb_tes_ot_up_weight;
   Float_t         evtsel_Emb_tes_ot_dn_weight;
   Float_t         evtsel_weight_EmbdEta;
   Int_t           evtsel_run_number;
   Int_t           evtsel_randomRunNumber;
   Float_t         evtsel_tau_x1;
   Float_t         evtsel_lep_x2;
   Float_t         evtsel_ditau_MMC;
   Float_t         evtsel_ditau_visibleMass;
   Float_t         evtsel_ditau_collinearMass;
   Float_t         evtsel_ditau_cosAngle;
   Float_t         evtsel_ditau_cosDPhi;
   Float_t         evtsel_higgs_pt;
   Float_t         evtsel_higgs_vispt;
   Float_t         evtsel_higgs_pt_mmc;
   Float_t         evtsel_transverseMass;
   Float_t         evtsel_dPhiSum;
   Float_t         evtsel_ddR;
   Float_t         evtsel_dRTauLep;
   Float_t         evtsel_mttj;
   Float_t         evtsel_bisector_p;
   Float_t         evtsel_bisector_pvis;
   Float_t         evtsel_MET;
   Float_t         evtsel_MET_phi;
   Float_t         evtsel_met_etx;
   Float_t         evtsel_met_ety;
   Float_t         evtsel_met_phi;
   Float_t         evtsel_met_sumet;
   Float_t         evtsel_met_forward;
   Float_t         evtsel_met_mu_et;
   Float_t         evtsel_met_el_et;
   Float_t         evtsel_met_tau_et;
   Float_t         evtsel_met_jet_et;
   Float_t         evtsel_met_jet_etx;
   Float_t         evtsel_met_jet_ety;
   Float_t         evtsel_met_truth_etx;
   Float_t         evtsel_met_truth_ety;
   Float_t         evtsel_met_truth_et;
   Float_t         evtsel_pTtot;
   Float_t         evtsel_pTratio;
   Float_t         evtsel_LepEtaCentrality;
   Float_t         evtsel_sumPt;
   Float_t         evtsel_jets_sumPt;
   Float_t         evtsel_met_phi_centrality;
   Int_t           evtsel_jets_num;
   Int_t           evtsel_jets_loose;
   Float_t         evtsel_jet_leading_pt;
   Float_t         evtsel_jet_leading_eta;
   Float_t         evtsel_jet_leading_phi;
   Float_t         evtsel_jet_leading_m;
   Float_t         evtsel_jet_subleading_pt;
   Float_t         evtsel_jet_subleading_eta;
   Float_t         evtsel_jet_subleading_phi;
   Float_t         evtsel_jet_subleading_m;
   Float_t         evtsel_jet_third_pt;
   Float_t         evtsel_jet_third_eta;
   Float_t         evtsel_jet_third_phi;
   Float_t         evtsel_jet_third_m;
   Float_t         evtsel_jetEta1_jetEta2;
   Bool_t          evtsel_jet_failJVF;
   Bool_t          evtsel_is_jet_opposite;
   Bool_t          evtsel_is_jet_centrality;
   Float_t         evtsel_jets_deltaEta;
   Float_t         evtsel_dijet_central_jet_pt;
   Float_t         evtsel_dijet_centralJVF_jet_pt;
   Float_t         evtsel_jet_minEta;
   Float_t         evtsel_jet_maxEta;
   Float_t         evtsel_dijet_mass;
   Float_t         evtsel_ddR_vbf;
   Float_t         evtsel_ddR_boost;
   Float_t         evtsel_ddR_1Jet;
   Float_t         evtsel_ddR_0Jet;
   Bool_t          evtsel_Zll_fail;
   Bool_t          evtsel_tau_eVetoTight;
   Float_t         evtsel_tau_et;
   Float_t         evtsel_tau_phi;
   Float_t         evtsel_tau_eta;
   Int_t           evtsel_tau_numTrack;
   Bool_t          evtsel_tau_is_el;
   Bool_t          evtsel_tau_is_mu;
   Bool_t          evtsel_tau_is_had;
   Bool_t          evtsel_tau_is_real;
   Bool_t          evtsel_tau_is_jet;
   Bool_t          evtsel_tau_is_glujet;
   Bool_t          evtsel_tau_is_bjet;
   Bool_t          evtsel_tau_is_cjet;
   Bool_t          evtsel_tau_is_lightjet;
   Bool_t          evtsel_tau_is_Medium;
   Bool_t          evtsel_tau_is_Tight;
   Bool_t          evtsel_tau_is_Llh_Medium;
   Bool_t          evtsel_tau_is_Llh_Tight;
   Float_t         evtsel_tau_vtx_distance;
   Float_t         evtsel_tau_JetBDTScore;
   Float_t         evtsel_tau_jet_emfrac;
   Float_t         evtsel_tau_FTrk;
   Float_t         evtsel_tau_EMFrac;
   Float_t         evtsel_tau_CentFrac;
   Float_t         evtsel_tau_charge;
   Float_t         evtsel_lep_pt;
   Float_t         evtsel_lep_eta;
   Float_t         evtsel_lep_phi;
   Float_t         evtsel_lep_d0;
   Float_t         evtsel_lep_d0sig;
   Float_t         evtsel_lep_z0;
   Float_t         evtsel_lep_z0sig;
   Float_t         evtsel_lep_charge;
   Float_t         evtsel_lep_etcone20;
   Float_t         evtsel_lep_etcone30;
   Float_t         evtsel_lep_etcone40;
   Float_t         evtsel_lep_topoEtcone20;
   Float_t         evtsel_lep_topoEtcone30;
   Float_t         evtsel_lep_topoEtcone40;
   Float_t         evtsel_lep_ptcone20;
   Float_t         evtsel_lep_ptcone30;
   Float_t         evtsel_lep_ptcone40;
   Bool_t          evtsel_is_el;
   Bool_t          evtsel_is_mu;
   Bool_t          evtsel_is_eltau;
   Bool_t          evtsel_is_mutau;
   Bool_t          evtsel_is_oppositeSign;
   Bool_t          evtsel_is_VBF;
   Bool_t          evtsel_is_boosted;
   Bool_t          evtsel_is_oneJet;
   Bool_t          evtsel_is_noJet;
   Bool_t          evtsel_is_MVA_VBF_test;
   Bool_t          evtsel_is_MVA_VBF_train;
   Bool_t          evtsel_is_MVA_boosted;
   Bool_t          evtsel_is_MVA_oneJet;
   Bool_t          evtsel_is_MVA_noJet;
   Bool_t          evtsel_is_isoLep;
   Bool_t          evtsel_is_tau;
   Bool_t          evtsel_is_dilepCR;
   Bool_t          evtsel_is_dilepVeto;
   Float_t         evtsel_dilep_m;
   Float_t         evtsel_weight_emb_sys_up;
   Float_t         evtsel_weight_emb_sys_dn;
   Float_t         evtsel_sys_sf_el_trig_up;
   Float_t         evtsel_sys_sf_el_trig_down;
   Float_t         evtsel_sys_sf_el_id_up;
   Float_t         evtsel_sys_sf_el_id_down;
   Float_t         evtsel_sys_sf_el_iso_up;
   Float_t         evtsel_sys_sf_el_iso_down;
   Float_t         evtsel_sys_sf_mu_trig_up;
   Float_t         evtsel_sys_sf_mu_trig_down;
   Float_t         evtsel_sys_sf_mu_id_up;
   Float_t         evtsel_sys_sf_mu_id_down;
   Float_t         evtsel_sys_sf_mu_iso_up;
   Float_t         evtsel_sys_sf_mu_iso_down;
   Float_t         evtsel_sys_sf_tau_el_up;
   Float_t         evtsel_sys_sf_tau_el_down;
   Float_t         evtsel_sys_sf_tau_id_up;
   Float_t         evtsel_sys_sf_tau_id_down;
   Float_t         evtsel_sys_sf_tau_fake_up;
   Float_t         evtsel_sys_sf_tau_fake_down;
   Float_t         evtsel_sys_sf_tau_trig_up;
   Float_t         evtsel_sys_sf_tau_trig_down;
   Float_t         evtsel_sys_PU_rescaling_up;
   Float_t         evtsel_sys_PU_rescaling_down;
   Bool_t          evtsel_MV1;
   Float_t         evtsel_scalar_sum_pt;
   Float_t         evtsel_bjet_weight;
   Float_t         evtsel_bjet_sys_b_up;
   Float_t         evtsel_bjet_sys_c_up;
   Float_t         evtsel_bjet_sys_m_up;
   Float_t         evtsel_bjet_sys_b_down;
   Float_t         evtsel_bjet_sys_c_down;
   Float_t         evtsel_bjet_sys_m_down;
   Float_t         evtsel_Herwig_MET;
   Float_t         evtsel_Herwig_MaxTDist;
   Float_t         evtsel_Herwig_MaxDist;
   Float_t         evtsel_Herwig_PtMax;
   Float_t         evtsel_Herwig_SumPt;
   Int_t           evtsel_Herwig_nKaon;
   Int_t           evtsel_Herwig_nSigma;
   Int_t           evtsel_Herwig_nOmega;
   Int_t           evtsel_Herwig_nXi;
   Int_t           evtsel_Herwig_nLambda;
   Bool_t          evtsel_EF_VBF;
   Bool_t          evtsel_L2_VBF;
   Float_t         evtsel_truethad_pt;
   Float_t         evtsel_truethad_eta;
   Float_t         evtsel_truethad_phi;
   vector<float>   *evtsel_truethad_dau_pt;
   vector<float>   *evtsel_truethad_dau_eta;
   vector<float>   *evtsel_truethad_dau_phi;
   vector<int>     *evtsel_truethad_dau_pdgId;
   Float_t         evtsel_truetlep_pt;
   Float_t         evtsel_truetlep_eta;
   Float_t         evtsel_truetlep_phi;
   vector<float>   *evtsel_truetlep_dau_pt;
   vector<float>   *evtsel_truetlep_dau_eta;
   vector<float>   *evtsel_truetlep_dau_phi;
   vector<int>     *evtsel_truetlep_dau_pdgId;
   Float_t         emb_82_px;
   Float_t         emb_82_py;
   Float_t         emb_82_pz;
   vector<int>     *dummy_variable;
   Float_t         mcevt_weight00;
   Float_t         evtsel_MET_RefEle_etx;
   Float_t         evtsel_MET_RefEle_ety;
   Float_t         evtsel_MET_RefEle_sumet;
   Float_t         evtsel_MET_RefTau_etx;
   Float_t         evtsel_MET_RefTau_ety;
   Float_t         evtsel_MET_RefTau_sumet;
   Float_t         evtsel_MET_RefGamma_etx;
   Float_t         evtsel_MET_RefGamma_ety;
   Float_t         evtsel_MET_RefGamma_sumet;
   Float_t         evtsel_MET_RefJet_JVFCut_etx;
   Float_t         evtsel_MET_RefJet_JVFCut_ety;
   Float_t         evtsel_MET_RefJet_JVFCut_sumet;
   Float_t         evtsel_MET_CellOut_Eflow_STVF_etx;
   Float_t         evtsel_MET_CellOut_Eflow_STVF_ety;
   Float_t         evtsel_MET_CellOut_Eflow_STVF_sumet;
   Float_t         evtsel_MET_MuonBoy_etx;
   Float_t         evtsel_MET_MuonBoy_ety;
   Float_t         evtsel_MET_MuonBoy_sumet;
   Float_t         evtsel_MET_CellOut_Eflow_JetArea_etx;
   Float_t         evtsel_MET_CellOut_Eflow_JetArea_ety;
   Float_t         evtsel_MET_CellOut_Eflow_JetArea_sumet;
   Float_t         evtsel_MET_CellOut_Eflow_JetAreaJVF_etx;
   Float_t         evtsel_MET_CellOut_Eflow_JetAreaJVF_ety;
   Float_t         evtsel_MET_CellOut_Eflow_JetAreaJVF_sumet;
   Float_t         evtsel_MET_CellOut_Eflow_JetAreaRhoEta5JVF_etx;
   Float_t         evtsel_MET_CellOut_Eflow_JetAreaRhoEta5JVF_ety;
   Float_t         evtsel_MET_CellOut_Eflow_JetAreaRhoEta5JVF_sumet;
   Float_t         evtsel_MET_RefFinal_AntiKt4LCTopo_tightpp_et;
   Float_t         evtsel_MET_RefFinal_AntiKt4LCTopo_tightpp_phi;
   Float_t         evtsel_MET_RefFinal_AntiKt4LCTopo_tightpp_sumet;
   UInt_t          RunNumber;
   UInt_t          EventNumber;
   UInt_t          mc_channel_number;
   UInt_t          lbn;
   Float_t         actualIntPerXing;
   Float_t         averageIntPerXing;
   UInt_t          larError;
   UInt_t          tileError;
   UInt_t          coreFlags;
   Int_t           top_hfor_type;
   Int_t           jet_n;
   vector<float>   *jet_E;
   vector<float>   *jet_pt;
   vector<float>   *jet_m;
   vector<float>   *jet_eta;
   vector<float>   *jet_phi;
   vector<float>   *jet_jvtxf;
   vector<float>   *jet_flavor_weight_MV1;
   vector<int>     *jet_flavor_truth_label;
   vector<float>   *jet_L2_VBF_weight;
   vector<int>     *jet_EF_jet_match;
   vector<int>     *jet_L2_jet_match;
   Int_t           mc_n;
   vector<float>   *mc_pt;
   vector<float>   *mc_eta;
   vector<float>   *mc_phi;
   vector<float>   *mc_m;
   vector<int>     *mc_status;
   vector<float>   *mc_charge;
   vector<int>     *mc_barcode;
   vector<vector<int> > *mc_parents;
   vector<vector<int> > *mc_children;
   vector<int>     *mc_pdgId;
   Bool_t          EF_e20_medium;
   Bool_t          EF_e22_medium;
   Bool_t          EF_e22_medium1;
   Bool_t          EF_e22vh_medium1;
   Bool_t          EF_mu18;
   Bool_t          EF_mu18_MG;
   Bool_t          EF_mu18_MG_medium;
   Bool_t          L1_MU11;
   Bool_t          EF_e60_medium1;
   Bool_t          EF_e24vhi_medium1;
   Bool_t          EF_mu24i_tight;
   Bool_t          EF_tau20Ti_medium1_e18vh_medium1;
   Bool_t          EF_tau20_medium1_mu15;
   Bool_t          EF_tau20_medium_mu15;
   Bool_t          EF_tau16_loose_e15_medium;
   Bool_t          EF_tau20_medium_e15_medium;
   Bool_t          EF_tau20_medium_e15vh_medium;
   Bool_t          EF_tau16_loose_mu15;
   Bool_t          L1_TAU8_MU10;
   Bool_t          L2_mu15;
   Bool_t          EF_mu15;
   Bool_t          L1_2TAU11I_EM14VH;
   Bool_t          L2_e18vh_medium1;
   Bool_t          EF_e18vh_medium1;
   Bool_t          EF_e18vh_medium1_vbf_2L1TAU11I_EM14VH;
   Int_t           jet_antikt4truth_n;
   vector<float>   *jet_antikt4truth_pt;
   vector<float>   *jet_antikt4truth_m;
   vector<float>   *jet_antikt4truth_eta;
   vector<float>   *jet_antikt4truth_phi;
   vector<int>     *vxp_nTracks;

   // List of branches
   TBranch        *b_evtsel_averageIntPerXing;   //!
   TBranch        *b_evtsel_vertices;   //!
   TBranch        *b_evtsel_vertices_three;   //!
   TBranch        *b_evtsel_weight;   //!
   TBranch        *b_evtsel_weight_PU;   //!
   TBranch        *b_evtsel_weight_lep;   //!
   TBranch        *b_evtsel_weight_lep_reco;   //!
   TBranch        *b_evtsel_weight_lep_id;   //!
   TBranch        *b_evtsel_weight_lep_trigger;   //!
   TBranch        *b_evtsel_weight_lep_iso;   //!
   TBranch        *b_evtsel_weight_tau_el_overlap;   //!
   TBranch        *b_evtsel_weight_tau_id;   //!
   TBranch        *b_evtsel_weight_SLT;   //!
   TBranch        *b_evtsel_weight_LTT;   //!
   TBranch        *b_evtsel_weight_tau_trigger;   //!
   TBranch        *b_evtsel_weight_FF_SLT;   //!
   TBranch        *b_evtsel_weight_FF_LTT;   //!
   TBranch        *b_evtsel_weight_dEta;   //!
   TBranch        *b_evtsel_EmbTightIso_weight;   //!
   TBranch        *b_evtsel_EmbNoIso_weight;   //!
   TBranch        *b_evtsel_Emb_tes_up_weight;   //!
   TBranch        *b_evtsel_Emb_tes_dn_weight;   //!
   TBranch        *b_evtsel_Emb_tes_ot_up_weight;   //!
   TBranch        *b_evtsel_Emb_tes_ot_dn_weight;   //!
   TBranch        *b_evtsel_weight_EmbdEta;   //!
   TBranch        *b_evtsel_run_number;   //!
   TBranch        *b_evtsel_randomRunNumber;   //!
   TBranch        *b_evtsel_tau_x1;   //!
   TBranch        *b_evtsel_lep_x2;   //!
   TBranch        *b_evtsel_ditau_MMC;   //!
   TBranch        *b_evtsel_ditau_visibleMass;   //!
   TBranch        *b_evtsel_ditau_collinearMass;   //!
   TBranch        *b_evtsel_ditau_cosAngle;   //!
   TBranch        *b_evtsel_ditau_cosDPhi;   //!
   TBranch        *b_evtsel_higgs_pt;   //!
   TBranch        *b_evtsel_higgs_vispt;   //!
   TBranch        *b_evtsel_higgs_pt_mmc;   //!
   TBranch        *b_evtsel_transverseMass;   //!
   TBranch        *b_evtsel_dPhiSum;   //!
   TBranch        *b_evtsel_ddR;   //!
   TBranch        *b_evtsel_dRTauLep;   //!
   TBranch        *b_evtsel_mttj;   //!
   TBranch        *b_evtsel_bisector_p;   //!
   TBranch        *b_evtsel_bisector_pvis;   //!
   TBranch        *b_evtsel_MET;   //!
   TBranch        *b_evtsel_MET_phi;   //!
   TBranch        *b_evtsel_met_etx;   //!
   TBranch        *b_evtsel_met_ety;   //!
   TBranch        *b_evtsel_met_phi;   //!
   TBranch        *b_evtsel_met_sumet;   //!
   TBranch        *b_evtsel_met_forward;   //!
   TBranch        *b_evtsel_met_mu_et;   //!
   TBranch        *b_evtsel_met_el_et;   //!
   TBranch        *b_evtsel_met_tau_et;   //!
   TBranch        *b_evtsel_met_jet_et;   //!
   TBranch        *b_evtsel_met_jet_etx;   //!
   TBranch        *b_evtsel_met_jet_ety;   //!
   TBranch        *b_evtsel_met_truth_etx;   //!
   TBranch        *b_evtsel_met_truth_ety;   //!
   TBranch        *b_evtsel_met_truth_et;   //!
   TBranch        *b_evtsel_pTtot;   //!
   TBranch        *b_evtsel_pTratio;   //!
   TBranch        *b_evtsel_LepEtaCentrality;   //!
   TBranch        *b_evtsel_sumPt;   //!
   TBranch        *b_evtsel_jets_sumPt;   //!
   TBranch        *b_evtsel_met_phi_centrality;   //!
   TBranch        *b_evtsel_jets_num;   //!
   TBranch        *b_evtsel_jets_loose;   //!
   TBranch        *b_evtsel_jet_leading_pt;   //!
   TBranch        *b_evtsel_jet_leading_eta;   //!
   TBranch        *b_evtsel_jet_leading_phi;   //!
   TBranch        *b_evtsel_jet_leading_m;   //!
   TBranch        *b_evtsel_jet_subleading_pt;   //!
   TBranch        *b_evtsel_jet_subleading_eta;   //!
   TBranch        *b_evtsel_jet_subleading_phi;   //!
   TBranch        *b_evtsel_jet_subleading_m;   //!
   TBranch        *b_evtsel_jet_third_pt;   //!
   TBranch        *b_evtsel_jet_third_eta;   //!
   TBranch        *b_evtsel_jet_third_phi;   //!
   TBranch        *b_evtsel_jet_third_m;   //!
   TBranch        *b_evtsel_jetEta1_jetEta2;   //!
   TBranch        *b_evtsel_jet_failJVF;   //!
   TBranch        *b_evtsel_is_jet_opposite;   //!
   TBranch        *b_evtsel_is_jet_centrality;   //!
   TBranch        *b_evtsel_jets_deltaEta;   //!
   TBranch        *b_evtsel_dijet_central_jet_pt;   //!
   TBranch        *b_evtsel_dijet_centralJVF_jet_pt;   //!
   TBranch        *b_evtsel_jet_minEta;   //!
   TBranch        *b_evtsel_jet_maxEta;   //!
   TBranch        *b_evtsel_dijet_mass;   //!
   TBranch        *b_evtsel_ddR_vbf;   //!
   TBranch        *b_evtsel_ddR_boost;   //!
   TBranch        *b_evtsel_ddR_1Jet;   //!
   TBranch        *b_evtsel_ddR_0Jet;   //!
   TBranch        *b_evtsel_Zll_fail;   //!
   TBranch        *b_evtsel_tau_eVetoTight;   //!
   TBranch        *b_evtsel_tau_et;   //!
   TBranch        *b_evtsel_tau_phi;   //!
   TBranch        *b_evtsel_tau_eta;   //!
   TBranch        *b_evtsel_tau_numTrack;   //!
   TBranch        *b_evtsel_tau_is_el;   //!
   TBranch        *b_evtsel_tau_is_mu;   //!
   TBranch        *b_evtsel_tau_is_had;   //!
   TBranch        *b_evtsel_tau_is_real;   //!
   TBranch        *b_evtsel_tau_is_jet;   //!
   TBranch        *b_evtsel_tau_is_glujet;   //!
   TBranch        *b_evtsel_tau_is_bjet;   //!
   TBranch        *b_evtsel_tau_is_cjet;   //!
   TBranch        *b_evtsel_tau_is_lightjet;   //!
   TBranch        *b_evtsel_tau_is_Medium;   //!
   TBranch        *b_evtsel_tau_is_Tight;   //!
   TBranch        *b_evtsel_tau_is_Llh_Medium;   //!
   TBranch        *b_evtsel_tau_is_Llh_Tight;   //!
   TBranch        *b_evtsel_tau_vtx_distance;   //!
   TBranch        *b_evtsel_tau_JetBDTScore;   //!
   TBranch        *b_evtsel_tau_jet_emfrac;   //!
   TBranch        *b_evtsel_tau_FTrk;   //!
   TBranch        *b_evtsel_tau_EMFrac;   //!
   TBranch        *b_evtsel_tau_CentFrac;   //!
   TBranch        *b_evtsel_tau_charge;   //!
   TBranch        *b_evtsel_lep_pt;   //!
   TBranch        *b_evtsel_lep_eta;   //!
   TBranch        *b_evtsel_lep_phi;   //!
   TBranch        *b_evtsel_lep_d0;   //!
   TBranch        *b_evtsel_lep_d0sig;   //!
   TBranch        *b_evtsel_lep_z0;   //!
   TBranch        *b_evtsel_lep_z0sig;   //!
   TBranch        *b_evtsel_lep_charge;   //!
   TBranch        *b_evtsel_lep_etcone20;   //!
   TBranch        *b_evtsel_lep_etcone30;   //!
   TBranch        *b_evtsel_lep_etcone40;   //!
   TBranch        *b_evtsel_lep_topoEtcone20;   //!
   TBranch        *b_evtsel_lep_topoEtcone30;   //!
   TBranch        *b_evtsel_lep_topoEtcone40;   //!
   TBranch        *b_evtsel_lep_ptcone20;   //!
   TBranch        *b_evtsel_lep_ptcone30;   //!
   TBranch        *b_evtsel_lep_ptcone40;   //!
   TBranch        *b_evtsel_is_el;   //!
   TBranch        *b_evtsel_is_mu;   //!
   TBranch        *b_evtsel_is_eltau;   //!
   TBranch        *b_evtsel_is_mutau;   //!
   TBranch        *b_evtsel_is_oppositeSign;   //!
   TBranch        *b_evtsel_is_VBF;   //!
   TBranch        *b_evtsel_is_boosted;   //!
   TBranch        *b_evtsel_is_oneJet;   //!
   TBranch        *b_evtsel_is_noJet;   //!
   TBranch        *b_evtsel_is_MVA_VBF_test;   //!
   TBranch        *b_evtsel_is_MVA_VBF_train;   //!
   TBranch        *b_evtsel_is_MVA_boosted;   //!
   TBranch        *b_evtsel_is_MVA_oneJet;   //!
   TBranch        *b_evtsel_is_MVA_noJet;   //!
   TBranch        *b_evtsel_is_isoLep;   //!
   TBranch        *b_evtsel_is_tau;   //!
   TBranch        *b_evtsel_is_dilepCR;   //!
   TBranch        *b_evtsel_is_dilepVeto;   //!
   TBranch        *b_evtsel_dilep_m;   //!
   TBranch        *b_evtsel_weight_emb_sys_up;   //!
   TBranch        *b_evtsel_weight_emb_sys_dn;   //!
   TBranch        *b_evtsel_sys_sf_el_trig_up;   //!
   TBranch        *b_evtsel_sys_sf_el_trig_down;   //!
   TBranch        *b_evtsel_sys_sf_el_id_up;   //!
   TBranch        *b_evtsel_sys_sf_el_id_down;   //!
   TBranch        *b_evtsel_sys_sf_el_iso_up;   //!
   TBranch        *b_evtsel_sys_sf_el_iso_down;   //!
   TBranch        *b_evtsel_sys_sf_mu_trig_up;   //!
   TBranch        *b_evtsel_sys_sf_mu_trig_down;   //!
   TBranch        *b_evtsel_sys_sf_mu_id_up;   //!
   TBranch        *b_evtsel_sys_sf_mu_id_down;   //!
   TBranch        *b_evtsel_sys_sf_mu_iso_up;   //!
   TBranch        *b_evtsel_sys_sf_mu_iso_down;   //!
   TBranch        *b_evtsel_sys_sf_tau_el_up;   //!
   TBranch        *b_evtsel_sys_sf_tau_el_down;   //!
   TBranch        *b_evtsel_sys_sf_tau_id_up;   //!
   TBranch        *b_evtsel_sys_sf_tau_id_down;   //!
   TBranch        *b_evtsel_sys_sf_tau_fake_up;   //!
   TBranch        *b_evtsel_sys_sf_tau_fake_down;   //!
   TBranch        *b_evtsel_sys_sf_tau_trig_up;   //!
   TBranch        *b_evtsel_sys_sf_tau_trig_down;   //!
   TBranch        *b_evtsel_sys_PU_rescaling_up;   //!
   TBranch        *b_evtsel_sys_PU_rescaling_down;   //!
   TBranch        *b_evtsel_MV1;   //!
   TBranch        *b_evtsel_scalar_sum_pt;   //!
   TBranch        *b_evtsel_bjet_weight;   //!
   TBranch        *b_evtsel_bjet_sys_b_up;   //!
   TBranch        *b_evtsel_bjet_sys_c_up;   //!
   TBranch        *b_evtsel_bjet_sys_m_up;   //!
   TBranch        *b_evtsel_bjet_sys_b_down;   //!
   TBranch        *b_evtsel_bjet_sys_c_down;   //!
   TBranch        *b_evtsel_bjet_sys_m_down;   //!
   TBranch        *b_evtsel_Herwig_MET;   //!
   TBranch        *b_evtsel_Herwig_MaxTDist;   //!
   TBranch        *b_evtsel_Herwig_MaxDist;   //!
   TBranch        *b_evtsel_Herwig_PtMax;   //!
   TBranch        *b_evtsel_Herwig_SumPt;   //!
   TBranch        *b_evtsel_Herwig_nKaon;   //!
   TBranch        *b_evtsel_Herwig_nSigma;   //!
   TBranch        *b_evtsel_Herwig_nOmega;   //!
   TBranch        *b_evtsel_Herwig_nXi;   //!
   TBranch        *b_evtsel_Herwig_nLambda;   //!
   TBranch        *b_evtsel_EF_VBF;   //!
   TBranch        *b_evtsel_L2_VBF;   //!
   TBranch        *b_evtsel_truethad_pt;   //!
   TBranch        *b_evtsel_truethad_eta;   //!
   TBranch        *b_evtsel_truethad_phi;   //!
   TBranch        *b_evtsel_truethad_dau_pt;   //!
   TBranch        *b_evtsel_truethad_dau_eta;   //!
   TBranch        *b_evtsel_truethad_dau_phi;   //!
   TBranch        *b_evtsel_truethad_dau_pdgId;   //!
   TBranch        *b_evtsel_truetlep_pt;   //!
   TBranch        *b_evtsel_truetlep_eta;   //!
   TBranch        *b_evtsel_truetlep_phi;   //!
   TBranch        *b_evtsel_truetlep_dau_pt;   //!
   TBranch        *b_evtsel_truetlep_dau_eta;   //!
   TBranch        *b_evtsel_truetlep_dau_phi;   //!
   TBranch        *b_evtsel_truetlep_dau_pdgId;   //!
   TBranch        *b_emb_82_px;   //!
   TBranch        *b_emb_82_py;   //!
   TBranch        *b_emb_82_pz;   //!
   TBranch        *b_dummy_variable;   //!
   TBranch        *b_mcevt_weight00;   //!
   TBranch        *b_evtsel_MET_RefEle_etx;   //!
   TBranch        *b_evtsel_MET_RefEle_ety;   //!
   TBranch        *b_evtsel_MET_RefEle_sumet;   //!
   TBranch        *b_evtsel_MET_RefTau_etx;   //!
   TBranch        *b_evtsel_MET_RefTau_ety;   //!
   TBranch        *b_evtsel_MET_RefTau_sumet;   //!
   TBranch        *b_evtsel_MET_RefGamma_etx;   //!
   TBranch        *b_evtsel_MET_RefGamma_ety;   //!
   TBranch        *b_evtsel_MET_RefGamma_sumet;   //!
   TBranch        *b_evtsel_MET_RefJet_JVFCut_etx;   //!
   TBranch        *b_evtsel_MET_RefJet_JVFCut_ety;   //!
   TBranch        *b_evtsel_MET_RefJet_JVFCut_sumet;   //!
   TBranch        *b_evtsel_MET_CellOut_Eflow_STVF_etx;   //!
   TBranch        *b_evtsel_MET_CellOut_Eflow_STVF_ety;   //!
   TBranch        *b_evtsel_MET_CellOut_Eflow_STVF_sumet;   //!
   TBranch        *b_evtsel_MET_MuonBoy_etx;   //!
   TBranch        *b_evtsel_MET_MuonBoy_ety;   //!
   TBranch        *b_evtsel_MET_MuonBoy_sumet;   //!
   TBranch        *b_evtsel_MET_CellOut_Eflow_JetArea_etx;   //!
   TBranch        *b_evtsel_MET_CellOut_Eflow_JetArea_ety;   //!
   TBranch        *b_evtsel_MET_CellOut_Eflow_JetArea_sumet;   //!
   TBranch        *b_evtsel_MET_CellOut_Eflow_JetAreaJVF_etx;   //!
   TBranch        *b_evtsel_MET_CellOut_Eflow_JetAreaJVF_ety;   //!
   TBranch        *b_evtsel_MET_CellOut_Eflow_JetAreaJVF_sumet;   //!
   TBranch        *b_evtsel_MET_CellOut_Eflow_JetAreaRhoEta5JVF_etx;   //!
   TBranch        *b_evtsel_MET_CellOut_Eflow_JetAreaRhoEta5JVF_ety;   //!
   TBranch        *b_evtsel_MET_CellOut_Eflow_JetAreaRhoEta5JVF_sumet;   //!
   TBranch        *b_evtsel_MET_RefFinal_AntiKt4LCTopo_tightpp_et;   //!
   TBranch        *b_evtsel_MET_RefFinal_AntiKt4LCTopo_tightpp_phi;   //!
   TBranch        *b_evtsel_MET_RefFinal_AntiKt4LCTopo_tightpp_sumet;   //!
   TBranch        *b_RunNumber;   //!
   TBranch        *b_EventNumber;   //!
   TBranch        *b_mc_channel_number;   //!
   TBranch        *b_lbn;   //!
   TBranch        *b_actualIntPerXing;   //!
   TBranch        *b_averageIntPerXing;   //!
   TBranch        *b_larError;   //!
   TBranch        *b_tileError;   //!
   TBranch        *b_coreFlags;   //!
   TBranch        *b_top_hfor_type;   //!
   TBranch        *b_jet_n;   //!
   TBranch        *b_jet_E;   //!
   TBranch        *b_jet_pt;   //!
   TBranch        *b_jet_m;   //!
   TBranch        *b_jet_eta;   //!
   TBranch        *b_jet_phi;   //!
   TBranch        *b_jet_jvtxf;   //!
   TBranch        *b_jet_flavor_weight_MV1;   //!
   TBranch        *b_jet_flavor_truth_label;   //!
   TBranch        *b_jet_L2_VBF_weight;   //!
   TBranch        *b_jet_EF_jet_match;   //!
   TBranch        *b_jet_L2_jet_match;   //!
   TBranch        *b_mc_n;   //!
   TBranch        *b_mc_pt;   //!
   TBranch        *b_mc_eta;   //!
   TBranch        *b_mc_phi;   //!
   TBranch        *b_mc_m;   //!
   TBranch        *b_mc_status;   //!
   TBranch        *b_mc_charge;   //!
   TBranch        *b_mc_barcode;   //!
   TBranch        *b_mc_parents;   //!
   TBranch        *b_mc_children;   //!
   TBranch        *b_mc_pdgId;   //!
   TBranch        *b_EF_e20_medium;   //!
   TBranch        *b_EF_e22_medium;   //!
   TBranch        *b_EF_e22_medium1;   //!
   TBranch        *b_EF_e22vh_medium1;   //!
   TBranch        *b_EF_mu18;   //!
   TBranch        *b_EF_mu18_MG;   //!
   TBranch        *b_EF_mu18_MG_medium;   //!
   TBranch        *b_L1_MU11;   //!
   TBranch        *b_EF_e60_medium1;   //!
   TBranch        *b_EF_e24vhi_medium1;   //!
   TBranch        *b_EF_mu24i_tight;   //!
   TBranch        *b_EF_tau20Ti_medium1_e18vh_medium1;   //!
   TBranch        *b_EF_tau20_medium1_mu15;   //!
   TBranch        *b_EF_tau20_medium_mu15;   //!
   TBranch        *b_EF_tau16_loose_e15_medium;   //!
   TBranch        *b_EF_tau20_medium_e15_medium;   //!
   TBranch        *b_EF_tau20_medium_e15vh_medium;   //!
   TBranch        *b_EF_tau16_loose_mu15;   //!
   TBranch        *b_L1_TAU8_MU10;   //!
   TBranch        *b_L2_mu15;   //!
   TBranch        *b_EF_mu15;   //!
   TBranch        *b_L1_2TAU11I_EM14VH;   //!
   TBranch        *b_L2_e18vh_medium1;   //!
   TBranch        *b_EF_e18vh_medium1;   //!
   TBranch        *b_EF_e18vh_medium1_vbf_2L1TAU11I_EM14VH;   //!
   TBranch        *b_jet_antikt4truth_n;   //!
   TBranch        *b_jet_antikt4truth_pt;   //!
   TBranch        *b_jet_antikt4truth_m;   //!
   TBranch        *b_jet_antikt4truth_eta;   //!
   TBranch        *b_jet_antikt4truth_phi;   //!
   TBranch        *b_vxp_nTracks;   //!

   cn(TTree *tree=0);
   virtual ~cn();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef cn_cxx
cn::cn(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("group.phys-higgs.290557_002277._00020.merge.ntuple.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("group.phys-higgs.290557_002277._00020.merge.ntuple.root");
      }
      f->GetObject("tau",tree);

   }
   Init(tree);
}

cn::~cn()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t cn::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t cn::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void cn::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   evtsel_truethad_dau_pt = 0;
   evtsel_truethad_dau_eta = 0;
   evtsel_truethad_dau_phi = 0;
   evtsel_truethad_dau_pdgId = 0;
   evtsel_truetlep_dau_pt = 0;
   evtsel_truetlep_dau_eta = 0;
   evtsel_truetlep_dau_phi = 0;
   evtsel_truetlep_dau_pdgId = 0;
   dummy_variable = 0;
   jet_E = 0;
   jet_pt = 0;
   jet_m = 0;
   jet_eta = 0;
   jet_phi = 0;
   jet_jvtxf = 0;
   jet_flavor_weight_MV1 = 0;
   jet_flavor_truth_label = 0;
   jet_L2_VBF_weight = 0;
   jet_EF_jet_match = 0;
   jet_L2_jet_match = 0;
   mc_pt = 0;
   mc_eta = 0;
   mc_phi = 0;
   mc_m = 0;
   mc_status = 0;
   mc_charge = 0;
   mc_barcode = 0;
   mc_parents = 0;
   mc_children = 0;
   mc_pdgId = 0;
   jet_antikt4truth_pt = 0;
   jet_antikt4truth_m = 0;
   jet_antikt4truth_eta = 0;
   jet_antikt4truth_phi = 0;
   vxp_nTracks = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("evtsel_averageIntPerXing", &evtsel_averageIntPerXing, &b_evtsel_averageIntPerXing);
   fChain->SetBranchAddress("evtsel_vertices", &evtsel_vertices, &b_evtsel_vertices);
   fChain->SetBranchAddress("evtsel_vertices_three", &evtsel_vertices_three, &b_evtsel_vertices_three);
   fChain->SetBranchAddress("evtsel_weight", &evtsel_weight, &b_evtsel_weight);
   fChain->SetBranchAddress("evtsel_weight_PU", &evtsel_weight_PU, &b_evtsel_weight_PU);
   fChain->SetBranchAddress("evtsel_weight_lep", &evtsel_weight_lep, &b_evtsel_weight_lep);
   fChain->SetBranchAddress("evtsel_weight_lep_reco", &evtsel_weight_lep_reco, &b_evtsel_weight_lep_reco);
   fChain->SetBranchAddress("evtsel_weight_lep_id", &evtsel_weight_lep_id, &b_evtsel_weight_lep_id);
   fChain->SetBranchAddress("evtsel_weight_lep_trigger", &evtsel_weight_lep_trigger, &b_evtsel_weight_lep_trigger);
   fChain->SetBranchAddress("evtsel_weight_lep_iso", &evtsel_weight_lep_iso, &b_evtsel_weight_lep_iso);
   fChain->SetBranchAddress("evtsel_weight_tau_el_overlap", &evtsel_weight_tau_el_overlap, &b_evtsel_weight_tau_el_overlap);
   fChain->SetBranchAddress("evtsel_weight_tau_id", &evtsel_weight_tau_id, &b_evtsel_weight_tau_id);
   fChain->SetBranchAddress("evtsel_weight_SLT", &evtsel_weight_SLT, &b_evtsel_weight_SLT);
   fChain->SetBranchAddress("evtsel_weight_LTT", &evtsel_weight_LTT, &b_evtsel_weight_LTT);
   fChain->SetBranchAddress("evtsel_weight_tau_trigger", &evtsel_weight_tau_trigger, &b_evtsel_weight_tau_trigger);
   fChain->SetBranchAddress("evtsel_weight_FF_SLT", &evtsel_weight_FF_SLT, &b_evtsel_weight_FF_SLT);
   fChain->SetBranchAddress("evtsel_weight_FF_LTT", &evtsel_weight_FF_LTT, &b_evtsel_weight_FF_LTT);
   fChain->SetBranchAddress("evtsel_weight_dEta", &evtsel_weight_dEta, &b_evtsel_weight_dEta);
   fChain->SetBranchAddress("evtsel_EmbTightIso_weight", &evtsel_EmbTightIso_weight, &b_evtsel_EmbTightIso_weight);
   fChain->SetBranchAddress("evtsel_EmbNoIso_weight", &evtsel_EmbNoIso_weight, &b_evtsel_EmbNoIso_weight);
   fChain->SetBranchAddress("evtsel_Emb_tes_up_weight", &evtsel_Emb_tes_up_weight, &b_evtsel_Emb_tes_up_weight);
   fChain->SetBranchAddress("evtsel_Emb_tes_dn_weight", &evtsel_Emb_tes_dn_weight, &b_evtsel_Emb_tes_dn_weight);
   fChain->SetBranchAddress("evtsel_Emb_tes_ot_up_weight", &evtsel_Emb_tes_ot_up_weight, &b_evtsel_Emb_tes_ot_up_weight);
   fChain->SetBranchAddress("evtsel_Emb_tes_ot_dn_weight", &evtsel_Emb_tes_ot_dn_weight, &b_evtsel_Emb_tes_ot_dn_weight);
   fChain->SetBranchAddress("evtsel_weight_EmbdEta", &evtsel_weight_EmbdEta, &b_evtsel_weight_EmbdEta);
   fChain->SetBranchAddress("evtsel_run_number", &evtsel_run_number, &b_evtsel_run_number);
   fChain->SetBranchAddress("evtsel_randomRunNumber", &evtsel_randomRunNumber, &b_evtsel_randomRunNumber);
   fChain->SetBranchAddress("evtsel_tau_x1", &evtsel_tau_x1, &b_evtsel_tau_x1);
   fChain->SetBranchAddress("evtsel_lep_x2", &evtsel_lep_x2, &b_evtsel_lep_x2);
   fChain->SetBranchAddress("evtsel_ditau_MMC", &evtsel_ditau_MMC, &b_evtsel_ditau_MMC);
   fChain->SetBranchAddress("evtsel_ditau_visibleMass", &evtsel_ditau_visibleMass, &b_evtsel_ditau_visibleMass);
   fChain->SetBranchAddress("evtsel_ditau_collinearMass", &evtsel_ditau_collinearMass, &b_evtsel_ditau_collinearMass);
   fChain->SetBranchAddress("evtsel_ditau_cosAngle", &evtsel_ditau_cosAngle, &b_evtsel_ditau_cosAngle);
   fChain->SetBranchAddress("evtsel_ditau_cosDPhi", &evtsel_ditau_cosDPhi, &b_evtsel_ditau_cosDPhi);
   fChain->SetBranchAddress("evtsel_higgs_pt", &evtsel_higgs_pt, &b_evtsel_higgs_pt);
   fChain->SetBranchAddress("evtsel_higgs_vispt", &evtsel_higgs_vispt, &b_evtsel_higgs_vispt);
   fChain->SetBranchAddress("evtsel_higgs_pt_mmc", &evtsel_higgs_pt_mmc, &b_evtsel_higgs_pt_mmc);
   fChain->SetBranchAddress("evtsel_transverseMass", &evtsel_transverseMass, &b_evtsel_transverseMass);
   fChain->SetBranchAddress("evtsel_dPhiSum", &evtsel_dPhiSum, &b_evtsel_dPhiSum);
   fChain->SetBranchAddress("evtsel_ddR", &evtsel_ddR, &b_evtsel_ddR);
   fChain->SetBranchAddress("evtsel_dRTauLep", &evtsel_dRTauLep, &b_evtsel_dRTauLep);
   fChain->SetBranchAddress("evtsel_mttj", &evtsel_mttj, &b_evtsel_mttj);
   fChain->SetBranchAddress("evtsel_bisector_p", &evtsel_bisector_p, &b_evtsel_bisector_p);
   fChain->SetBranchAddress("evtsel_bisector_pvis", &evtsel_bisector_pvis, &b_evtsel_bisector_pvis);
   fChain->SetBranchAddress("evtsel_MET", &evtsel_MET, &b_evtsel_MET);
   fChain->SetBranchAddress("evtsel_MET_phi", &evtsel_MET_phi, &b_evtsel_MET_phi);
   fChain->SetBranchAddress("evtsel_met_etx", &evtsel_met_etx, &b_evtsel_met_etx);
   fChain->SetBranchAddress("evtsel_met_ety", &evtsel_met_ety, &b_evtsel_met_ety);
   fChain->SetBranchAddress("evtsel_met_phi", &evtsel_met_phi, &b_evtsel_met_phi);
   fChain->SetBranchAddress("evtsel_met_sumet", &evtsel_met_sumet, &b_evtsel_met_sumet);
   fChain->SetBranchAddress("evtsel_met_forward", &evtsel_met_forward, &b_evtsel_met_forward);
   fChain->SetBranchAddress("evtsel_met_mu_et", &evtsel_met_mu_et, &b_evtsel_met_mu_et);
   fChain->SetBranchAddress("evtsel_met_el_et", &evtsel_met_el_et, &b_evtsel_met_el_et);
   fChain->SetBranchAddress("evtsel_met_tau_et", &evtsel_met_tau_et, &b_evtsel_met_tau_et);
   fChain->SetBranchAddress("evtsel_met_jet_et", &evtsel_met_jet_et, &b_evtsel_met_jet_et);
   fChain->SetBranchAddress("evtsel_met_jet_etx", &evtsel_met_jet_etx, &b_evtsel_met_jet_etx);
   fChain->SetBranchAddress("evtsel_met_jet_ety", &evtsel_met_jet_ety, &b_evtsel_met_jet_ety);
   fChain->SetBranchAddress("evtsel_met_truth_etx", &evtsel_met_truth_etx, &b_evtsel_met_truth_etx);
   fChain->SetBranchAddress("evtsel_met_truth_ety", &evtsel_met_truth_ety, &b_evtsel_met_truth_ety);
   fChain->SetBranchAddress("evtsel_met_truth_et", &evtsel_met_truth_et, &b_evtsel_met_truth_et);
   fChain->SetBranchAddress("evtsel_pTtot", &evtsel_pTtot, &b_evtsel_pTtot);
   fChain->SetBranchAddress("evtsel_pTratio", &evtsel_pTratio, &b_evtsel_pTratio);
   fChain->SetBranchAddress("evtsel_LepEtaCentrality", &evtsel_LepEtaCentrality, &b_evtsel_LepEtaCentrality);
   fChain->SetBranchAddress("evtsel_sumPt", &evtsel_sumPt, &b_evtsel_sumPt);
   fChain->SetBranchAddress("evtsel_jets_sumPt", &evtsel_jets_sumPt, &b_evtsel_jets_sumPt);
   fChain->SetBranchAddress("evtsel_met_phi_centrality", &evtsel_met_phi_centrality, &b_evtsel_met_phi_centrality);
   fChain->SetBranchAddress("evtsel_jets_num", &evtsel_jets_num, &b_evtsel_jets_num);
   fChain->SetBranchAddress("evtsel_jets_loose", &evtsel_jets_loose, &b_evtsel_jets_loose);
   fChain->SetBranchAddress("evtsel_jet_leading_pt", &evtsel_jet_leading_pt, &b_evtsel_jet_leading_pt);
   fChain->SetBranchAddress("evtsel_jet_leading_eta", &evtsel_jet_leading_eta, &b_evtsel_jet_leading_eta);
   fChain->SetBranchAddress("evtsel_jet_leading_phi", &evtsel_jet_leading_phi, &b_evtsel_jet_leading_phi);
   fChain->SetBranchAddress("evtsel_jet_leading_m", &evtsel_jet_leading_m, &b_evtsel_jet_leading_m);
   fChain->SetBranchAddress("evtsel_jet_subleading_pt", &evtsel_jet_subleading_pt, &b_evtsel_jet_subleading_pt);
   fChain->SetBranchAddress("evtsel_jet_subleading_eta", &evtsel_jet_subleading_eta, &b_evtsel_jet_subleading_eta);
   fChain->SetBranchAddress("evtsel_jet_subleading_phi", &evtsel_jet_subleading_phi, &b_evtsel_jet_subleading_phi);
   fChain->SetBranchAddress("evtsel_jet_subleading_m", &evtsel_jet_subleading_m, &b_evtsel_jet_subleading_m);
   fChain->SetBranchAddress("evtsel_jet_third_pt", &evtsel_jet_third_pt, &b_evtsel_jet_third_pt);
   fChain->SetBranchAddress("evtsel_jet_third_eta", &evtsel_jet_third_eta, &b_evtsel_jet_third_eta);
   fChain->SetBranchAddress("evtsel_jet_third_phi", &evtsel_jet_third_phi, &b_evtsel_jet_third_phi);
   fChain->SetBranchAddress("evtsel_jet_third_m", &evtsel_jet_third_m, &b_evtsel_jet_third_m);
   fChain->SetBranchAddress("evtsel_jetEta1_jetEta2", &evtsel_jetEta1_jetEta2, &b_evtsel_jetEta1_jetEta2);
   fChain->SetBranchAddress("evtsel_jet_failJVF", &evtsel_jet_failJVF, &b_evtsel_jet_failJVF);
   fChain->SetBranchAddress("evtsel_is_jet_opposite", &evtsel_is_jet_opposite, &b_evtsel_is_jet_opposite);
   fChain->SetBranchAddress("evtsel_is_jet_centrality", &evtsel_is_jet_centrality, &b_evtsel_is_jet_centrality);
   fChain->SetBranchAddress("evtsel_jets_deltaEta", &evtsel_jets_deltaEta, &b_evtsel_jets_deltaEta);
   fChain->SetBranchAddress("evtsel_dijet_central_jet_pt", &evtsel_dijet_central_jet_pt, &b_evtsel_dijet_central_jet_pt);
   fChain->SetBranchAddress("evtsel_dijet_centralJVF_jet_pt", &evtsel_dijet_centralJVF_jet_pt, &b_evtsel_dijet_centralJVF_jet_pt);
   fChain->SetBranchAddress("evtsel_jet_minEta", &evtsel_jet_minEta, &b_evtsel_jet_minEta);
   fChain->SetBranchAddress("evtsel_jet_maxEta", &evtsel_jet_maxEta, &b_evtsel_jet_maxEta);
   fChain->SetBranchAddress("evtsel_dijet_mass", &evtsel_dijet_mass, &b_evtsel_dijet_mass);
   fChain->SetBranchAddress("evtsel_ddR_vbf", &evtsel_ddR_vbf, &b_evtsel_ddR_vbf);
   fChain->SetBranchAddress("evtsel_ddR_boost", &evtsel_ddR_boost, &b_evtsel_ddR_boost);
   fChain->SetBranchAddress("evtsel_ddR_1Jet", &evtsel_ddR_1Jet, &b_evtsel_ddR_1Jet);
   fChain->SetBranchAddress("evtsel_ddR_0Jet", &evtsel_ddR_0Jet, &b_evtsel_ddR_0Jet);
   fChain->SetBranchAddress("evtsel_Zll_fail", &evtsel_Zll_fail, &b_evtsel_Zll_fail);
   fChain->SetBranchAddress("evtsel_tau_eVetoTight", &evtsel_tau_eVetoTight, &b_evtsel_tau_eVetoTight);
   fChain->SetBranchAddress("evtsel_tau_et", &evtsel_tau_et, &b_evtsel_tau_et);
   fChain->SetBranchAddress("evtsel_tau_phi", &evtsel_tau_phi, &b_evtsel_tau_phi);
   fChain->SetBranchAddress("evtsel_tau_eta", &evtsel_tau_eta, &b_evtsel_tau_eta);
   fChain->SetBranchAddress("evtsel_tau_numTrack", &evtsel_tau_numTrack, &b_evtsel_tau_numTrack);
   fChain->SetBranchAddress("evtsel_tau_is_el", &evtsel_tau_is_el, &b_evtsel_tau_is_el);
   fChain->SetBranchAddress("evtsel_tau_is_mu", &evtsel_tau_is_mu, &b_evtsel_tau_is_mu);
   fChain->SetBranchAddress("evtsel_tau_is_had", &evtsel_tau_is_had, &b_evtsel_tau_is_had);
   fChain->SetBranchAddress("evtsel_tau_is_real", &evtsel_tau_is_real, &b_evtsel_tau_is_real);
   fChain->SetBranchAddress("evtsel_tau_is_jet", &evtsel_tau_is_jet, &b_evtsel_tau_is_jet);
   fChain->SetBranchAddress("evtsel_tau_is_glujet", &evtsel_tau_is_glujet, &b_evtsel_tau_is_glujet);
   fChain->SetBranchAddress("evtsel_tau_is_bjet", &evtsel_tau_is_bjet, &b_evtsel_tau_is_bjet);
   fChain->SetBranchAddress("evtsel_tau_is_cjet", &evtsel_tau_is_cjet, &b_evtsel_tau_is_cjet);
   fChain->SetBranchAddress("evtsel_tau_is_lightjet", &evtsel_tau_is_lightjet, &b_evtsel_tau_is_lightjet);
   fChain->SetBranchAddress("evtsel_tau_is_Medium", &evtsel_tau_is_Medium, &b_evtsel_tau_is_Medium);
   fChain->SetBranchAddress("evtsel_tau_is_Tight", &evtsel_tau_is_Tight, &b_evtsel_tau_is_Tight);
   fChain->SetBranchAddress("evtsel_tau_is_Llh_Medium", &evtsel_tau_is_Llh_Medium, &b_evtsel_tau_is_Llh_Medium);
   fChain->SetBranchAddress("evtsel_tau_is_Llh_Tight", &evtsel_tau_is_Llh_Tight, &b_evtsel_tau_is_Llh_Tight);
   fChain->SetBranchAddress("evtsel_tau_vtx_distance", &evtsel_tau_vtx_distance, &b_evtsel_tau_vtx_distance);
   fChain->SetBranchAddress("evtsel_tau_JetBDTScore", &evtsel_tau_JetBDTScore, &b_evtsel_tau_JetBDTScore);
   fChain->SetBranchAddress("evtsel_tau_jet_emfrac", &evtsel_tau_jet_emfrac, &b_evtsel_tau_jet_emfrac);
   fChain->SetBranchAddress("evtsel_tau_FTrk", &evtsel_tau_FTrk, &b_evtsel_tau_FTrk);
   fChain->SetBranchAddress("evtsel_tau_EMFrac", &evtsel_tau_EMFrac, &b_evtsel_tau_EMFrac);
   fChain->SetBranchAddress("evtsel_tau_CentFrac", &evtsel_tau_CentFrac, &b_evtsel_tau_CentFrac);
   fChain->SetBranchAddress("evtsel_tau_charge", &evtsel_tau_charge, &b_evtsel_tau_charge);
   fChain->SetBranchAddress("evtsel_lep_pt", &evtsel_lep_pt, &b_evtsel_lep_pt);
   fChain->SetBranchAddress("evtsel_lep_eta", &evtsel_lep_eta, &b_evtsel_lep_eta);
   fChain->SetBranchAddress("evtsel_lep_phi", &evtsel_lep_phi, &b_evtsel_lep_phi);
   fChain->SetBranchAddress("evtsel_lep_d0", &evtsel_lep_d0, &b_evtsel_lep_d0);
   fChain->SetBranchAddress("evtsel_lep_d0sig", &evtsel_lep_d0sig, &b_evtsel_lep_d0sig);
   fChain->SetBranchAddress("evtsel_lep_z0", &evtsel_lep_z0, &b_evtsel_lep_z0);
   fChain->SetBranchAddress("evtsel_lep_z0sig", &evtsel_lep_z0sig, &b_evtsel_lep_z0sig);
   fChain->SetBranchAddress("evtsel_lep_charge", &evtsel_lep_charge, &b_evtsel_lep_charge);
   fChain->SetBranchAddress("evtsel_lep_etcone20", &evtsel_lep_etcone20, &b_evtsel_lep_etcone20);
   fChain->SetBranchAddress("evtsel_lep_etcone30", &evtsel_lep_etcone30, &b_evtsel_lep_etcone30);
   fChain->SetBranchAddress("evtsel_lep_etcone40", &evtsel_lep_etcone40, &b_evtsel_lep_etcone40);
   fChain->SetBranchAddress("evtsel_lep_topoEtcone20", &evtsel_lep_topoEtcone20, &b_evtsel_lep_topoEtcone20);
   fChain->SetBranchAddress("evtsel_lep_topoEtcone30", &evtsel_lep_topoEtcone30, &b_evtsel_lep_topoEtcone30);
   fChain->SetBranchAddress("evtsel_lep_topoEtcone40", &evtsel_lep_topoEtcone40, &b_evtsel_lep_topoEtcone40);
   fChain->SetBranchAddress("evtsel_lep_ptcone20", &evtsel_lep_ptcone20, &b_evtsel_lep_ptcone20);
   fChain->SetBranchAddress("evtsel_lep_ptcone30", &evtsel_lep_ptcone30, &b_evtsel_lep_ptcone30);
   fChain->SetBranchAddress("evtsel_lep_ptcone40", &evtsel_lep_ptcone40, &b_evtsel_lep_ptcone40);
   fChain->SetBranchAddress("evtsel_is_el", &evtsel_is_el, &b_evtsel_is_el);
   fChain->SetBranchAddress("evtsel_is_mu", &evtsel_is_mu, &b_evtsel_is_mu);
   fChain->SetBranchAddress("evtsel_is_eltau", &evtsel_is_eltau, &b_evtsel_is_eltau);
   fChain->SetBranchAddress("evtsel_is_mutau", &evtsel_is_mutau, &b_evtsel_is_mutau);
   fChain->SetBranchAddress("evtsel_is_oppositeSign", &evtsel_is_oppositeSign, &b_evtsel_is_oppositeSign);
   fChain->SetBranchAddress("evtsel_is_VBF", &evtsel_is_VBF, &b_evtsel_is_VBF);
   fChain->SetBranchAddress("evtsel_is_boosted", &evtsel_is_boosted, &b_evtsel_is_boosted);
   fChain->SetBranchAddress("evtsel_is_oneJet", &evtsel_is_oneJet, &b_evtsel_is_oneJet);
   fChain->SetBranchAddress("evtsel_is_noJet", &evtsel_is_noJet, &b_evtsel_is_noJet);
   fChain->SetBranchAddress("evtsel_is_MVA_VBF_test", &evtsel_is_MVA_VBF_test, &b_evtsel_is_MVA_VBF_test);
   fChain->SetBranchAddress("evtsel_is_MVA_VBF_train", &evtsel_is_MVA_VBF_train, &b_evtsel_is_MVA_VBF_train);
   fChain->SetBranchAddress("evtsel_is_MVA_boosted", &evtsel_is_MVA_boosted, &b_evtsel_is_MVA_boosted);
   fChain->SetBranchAddress("evtsel_is_MVA_oneJet", &evtsel_is_MVA_oneJet, &b_evtsel_is_MVA_oneJet);
   fChain->SetBranchAddress("evtsel_is_MVA_noJet", &evtsel_is_MVA_noJet, &b_evtsel_is_MVA_noJet);
   fChain->SetBranchAddress("evtsel_is_isoLep", &evtsel_is_isoLep, &b_evtsel_is_isoLep);
   fChain->SetBranchAddress("evtsel_is_tau", &evtsel_is_tau, &b_evtsel_is_tau);
   fChain->SetBranchAddress("evtsel_is_dilepCR", &evtsel_is_dilepCR, &b_evtsel_is_dilepCR);
   fChain->SetBranchAddress("evtsel_is_dilepVeto", &evtsel_is_dilepVeto, &b_evtsel_is_dilepVeto);
   fChain->SetBranchAddress("evtsel_dilep_m", &evtsel_dilep_m, &b_evtsel_dilep_m);
   fChain->SetBranchAddress("evtsel_weight_emb_sys_up", &evtsel_weight_emb_sys_up, &b_evtsel_weight_emb_sys_up);
   fChain->SetBranchAddress("evtsel_weight_emb_sys_dn", &evtsel_weight_emb_sys_dn, &b_evtsel_weight_emb_sys_dn);
   fChain->SetBranchAddress("evtsel_sys_sf_el_trig_up", &evtsel_sys_sf_el_trig_up, &b_evtsel_sys_sf_el_trig_up);
   fChain->SetBranchAddress("evtsel_sys_sf_el_trig_down", &evtsel_sys_sf_el_trig_down, &b_evtsel_sys_sf_el_trig_down);
   fChain->SetBranchAddress("evtsel_sys_sf_el_id_up", &evtsel_sys_sf_el_id_up, &b_evtsel_sys_sf_el_id_up);
   fChain->SetBranchAddress("evtsel_sys_sf_el_id_down", &evtsel_sys_sf_el_id_down, &b_evtsel_sys_sf_el_id_down);
   fChain->SetBranchAddress("evtsel_sys_sf_el_iso_up", &evtsel_sys_sf_el_iso_up, &b_evtsel_sys_sf_el_iso_up);
   fChain->SetBranchAddress("evtsel_sys_sf_el_iso_down", &evtsel_sys_sf_el_iso_down, &b_evtsel_sys_sf_el_iso_down);
   fChain->SetBranchAddress("evtsel_sys_sf_mu_trig_up", &evtsel_sys_sf_mu_trig_up, &b_evtsel_sys_sf_mu_trig_up);
   fChain->SetBranchAddress("evtsel_sys_sf_mu_trig_down", &evtsel_sys_sf_mu_trig_down, &b_evtsel_sys_sf_mu_trig_down);
   fChain->SetBranchAddress("evtsel_sys_sf_mu_id_up", &evtsel_sys_sf_mu_id_up, &b_evtsel_sys_sf_mu_id_up);
   fChain->SetBranchAddress("evtsel_sys_sf_mu_id_down", &evtsel_sys_sf_mu_id_down, &b_evtsel_sys_sf_mu_id_down);
   fChain->SetBranchAddress("evtsel_sys_sf_mu_iso_up", &evtsel_sys_sf_mu_iso_up, &b_evtsel_sys_sf_mu_iso_up);
   fChain->SetBranchAddress("evtsel_sys_sf_mu_iso_down", &evtsel_sys_sf_mu_iso_down, &b_evtsel_sys_sf_mu_iso_down);
   fChain->SetBranchAddress("evtsel_sys_sf_tau_el_up", &evtsel_sys_sf_tau_el_up, &b_evtsel_sys_sf_tau_el_up);
   fChain->SetBranchAddress("evtsel_sys_sf_tau_el_down", &evtsel_sys_sf_tau_el_down, &b_evtsel_sys_sf_tau_el_down);
   fChain->SetBranchAddress("evtsel_sys_sf_tau_id_up", &evtsel_sys_sf_tau_id_up, &b_evtsel_sys_sf_tau_id_up);
   fChain->SetBranchAddress("evtsel_sys_sf_tau_id_down", &evtsel_sys_sf_tau_id_down, &b_evtsel_sys_sf_tau_id_down);
   fChain->SetBranchAddress("evtsel_sys_sf_tau_fake_up", &evtsel_sys_sf_tau_fake_up, &b_evtsel_sys_sf_tau_fake_up);
   fChain->SetBranchAddress("evtsel_sys_sf_tau_fake_down", &evtsel_sys_sf_tau_fake_down, &b_evtsel_sys_sf_tau_fake_down);
   fChain->SetBranchAddress("evtsel_sys_sf_tau_trig_up", &evtsel_sys_sf_tau_trig_up, &b_evtsel_sys_sf_tau_trig_up);
   fChain->SetBranchAddress("evtsel_sys_sf_tau_trig_down", &evtsel_sys_sf_tau_trig_down, &b_evtsel_sys_sf_tau_trig_down);
   fChain->SetBranchAddress("evtsel_sys_PU_rescaling_up", &evtsel_sys_PU_rescaling_up, &b_evtsel_sys_PU_rescaling_up);
   fChain->SetBranchAddress("evtsel_sys_PU_rescaling_down", &evtsel_sys_PU_rescaling_down, &b_evtsel_sys_PU_rescaling_down);
   fChain->SetBranchAddress("evtsel_MV1", &evtsel_MV1, &b_evtsel_MV1);
   fChain->SetBranchAddress("evtsel_scalar_sum_pt", &evtsel_scalar_sum_pt, &b_evtsel_scalar_sum_pt);
   fChain->SetBranchAddress("evtsel_bjet_weight", &evtsel_bjet_weight, &b_evtsel_bjet_weight);
   fChain->SetBranchAddress("evtsel_bjet_sys_b_up", &evtsel_bjet_sys_b_up, &b_evtsel_bjet_sys_b_up);
   fChain->SetBranchAddress("evtsel_bjet_sys_c_up", &evtsel_bjet_sys_c_up, &b_evtsel_bjet_sys_c_up);
   fChain->SetBranchAddress("evtsel_bjet_sys_m_up", &evtsel_bjet_sys_m_up, &b_evtsel_bjet_sys_m_up);
   fChain->SetBranchAddress("evtsel_bjet_sys_b_down", &evtsel_bjet_sys_b_down, &b_evtsel_bjet_sys_b_down);
   fChain->SetBranchAddress("evtsel_bjet_sys_c_down", &evtsel_bjet_sys_c_down, &b_evtsel_bjet_sys_c_down);
   fChain->SetBranchAddress("evtsel_bjet_sys_m_down", &evtsel_bjet_sys_m_down, &b_evtsel_bjet_sys_m_down);
   fChain->SetBranchAddress("evtsel_Herwig_MET", &evtsel_Herwig_MET, &b_evtsel_Herwig_MET);
   fChain->SetBranchAddress("evtsel_Herwig_MaxTDist", &evtsel_Herwig_MaxTDist, &b_evtsel_Herwig_MaxTDist);
   fChain->SetBranchAddress("evtsel_Herwig_MaxDist", &evtsel_Herwig_MaxDist, &b_evtsel_Herwig_MaxDist);
   fChain->SetBranchAddress("evtsel_Herwig_PtMax", &evtsel_Herwig_PtMax, &b_evtsel_Herwig_PtMax);
   fChain->SetBranchAddress("evtsel_Herwig_SumPt", &evtsel_Herwig_SumPt, &b_evtsel_Herwig_SumPt);
   fChain->SetBranchAddress("evtsel_Herwig_nKaon", &evtsel_Herwig_nKaon, &b_evtsel_Herwig_nKaon);
   fChain->SetBranchAddress("evtsel_Herwig_nSigma", &evtsel_Herwig_nSigma, &b_evtsel_Herwig_nSigma);
   fChain->SetBranchAddress("evtsel_Herwig_nOmega", &evtsel_Herwig_nOmega, &b_evtsel_Herwig_nOmega);
   fChain->SetBranchAddress("evtsel_Herwig_nXi", &evtsel_Herwig_nXi, &b_evtsel_Herwig_nXi);
   fChain->SetBranchAddress("evtsel_Herwig_nLambda", &evtsel_Herwig_nLambda, &b_evtsel_Herwig_nLambda);
   fChain->SetBranchAddress("evtsel_EF_VBF", &evtsel_EF_VBF, &b_evtsel_EF_VBF);
   fChain->SetBranchAddress("evtsel_L2_VBF", &evtsel_L2_VBF, &b_evtsel_L2_VBF);
   fChain->SetBranchAddress("evtsel_truethad_pt", &evtsel_truethad_pt, &b_evtsel_truethad_pt);
   fChain->SetBranchAddress("evtsel_truethad_eta", &evtsel_truethad_eta, &b_evtsel_truethad_eta);
   fChain->SetBranchAddress("evtsel_truethad_phi", &evtsel_truethad_phi, &b_evtsel_truethad_phi);
   fChain->SetBranchAddress("evtsel_truethad_dau_pt", &evtsel_truethad_dau_pt, &b_evtsel_truethad_dau_pt);
   fChain->SetBranchAddress("evtsel_truethad_dau_eta", &evtsel_truethad_dau_eta, &b_evtsel_truethad_dau_eta);
   fChain->SetBranchAddress("evtsel_truethad_dau_phi", &evtsel_truethad_dau_phi, &b_evtsel_truethad_dau_phi);
   fChain->SetBranchAddress("evtsel_truethad_dau_pdgId", &evtsel_truethad_dau_pdgId, &b_evtsel_truethad_dau_pdgId);
   fChain->SetBranchAddress("evtsel_truetlep_pt", &evtsel_truetlep_pt, &b_evtsel_truetlep_pt);
   fChain->SetBranchAddress("evtsel_truetlep_eta", &evtsel_truetlep_eta, &b_evtsel_truetlep_eta);
   fChain->SetBranchAddress("evtsel_truetlep_phi", &evtsel_truetlep_phi, &b_evtsel_truetlep_phi);
   fChain->SetBranchAddress("evtsel_truetlep_dau_pt", &evtsel_truetlep_dau_pt, &b_evtsel_truetlep_dau_pt);
   fChain->SetBranchAddress("evtsel_truetlep_dau_eta", &evtsel_truetlep_dau_eta, &b_evtsel_truetlep_dau_eta);
   fChain->SetBranchAddress("evtsel_truetlep_dau_phi", &evtsel_truetlep_dau_phi, &b_evtsel_truetlep_dau_phi);
   fChain->SetBranchAddress("evtsel_truetlep_dau_pdgId", &evtsel_truetlep_dau_pdgId, &b_evtsel_truetlep_dau_pdgId);
   fChain->SetBranchAddress("emb_82_px", &emb_82_px, &b_emb_82_px);
   fChain->SetBranchAddress("emb_82_py", &emb_82_py, &b_emb_82_py);
   fChain->SetBranchAddress("emb_82_pz", &emb_82_pz, &b_emb_82_pz);
   fChain->SetBranchAddress("dummy_variable", &dummy_variable, &b_dummy_variable);
   fChain->SetBranchAddress("mcevt_weight00", &mcevt_weight00, &b_mcevt_weight00);
   fChain->SetBranchAddress("evtsel_MET_RefEle_etx", &evtsel_MET_RefEle_etx, &b_evtsel_MET_RefEle_etx);
   fChain->SetBranchAddress("evtsel_MET_RefEle_ety", &evtsel_MET_RefEle_ety, &b_evtsel_MET_RefEle_ety);
   fChain->SetBranchAddress("evtsel_MET_RefEle_sumet", &evtsel_MET_RefEle_sumet, &b_evtsel_MET_RefEle_sumet);
   fChain->SetBranchAddress("evtsel_MET_RefTau_etx", &evtsel_MET_RefTau_etx, &b_evtsel_MET_RefTau_etx);
   fChain->SetBranchAddress("evtsel_MET_RefTau_ety", &evtsel_MET_RefTau_ety, &b_evtsel_MET_RefTau_ety);
   fChain->SetBranchAddress("evtsel_MET_RefTau_sumet", &evtsel_MET_RefTau_sumet, &b_evtsel_MET_RefTau_sumet);
   fChain->SetBranchAddress("evtsel_MET_RefGamma_etx", &evtsel_MET_RefGamma_etx, &b_evtsel_MET_RefGamma_etx);
   fChain->SetBranchAddress("evtsel_MET_RefGamma_ety", &evtsel_MET_RefGamma_ety, &b_evtsel_MET_RefGamma_ety);
   fChain->SetBranchAddress("evtsel_MET_RefGamma_sumet", &evtsel_MET_RefGamma_sumet, &b_evtsel_MET_RefGamma_sumet);
   fChain->SetBranchAddress("evtsel_MET_RefJet_JVFCut_etx", &evtsel_MET_RefJet_JVFCut_etx, &b_evtsel_MET_RefJet_JVFCut_etx);
   fChain->SetBranchAddress("evtsel_MET_RefJet_JVFCut_ety", &evtsel_MET_RefJet_JVFCut_ety, &b_evtsel_MET_RefJet_JVFCut_ety);
   fChain->SetBranchAddress("evtsel_MET_RefJet_JVFCut_sumet", &evtsel_MET_RefJet_JVFCut_sumet, &b_evtsel_MET_RefJet_JVFCut_sumet);
   fChain->SetBranchAddress("evtsel_MET_CellOut_Eflow_STVF_etx", &evtsel_MET_CellOut_Eflow_STVF_etx, &b_evtsel_MET_CellOut_Eflow_STVF_etx);
   fChain->SetBranchAddress("evtsel_MET_CellOut_Eflow_STVF_ety", &evtsel_MET_CellOut_Eflow_STVF_ety, &b_evtsel_MET_CellOut_Eflow_STVF_ety);
   fChain->SetBranchAddress("evtsel_MET_CellOut_Eflow_STVF_sumet", &evtsel_MET_CellOut_Eflow_STVF_sumet, &b_evtsel_MET_CellOut_Eflow_STVF_sumet);
   fChain->SetBranchAddress("evtsel_MET_MuonBoy_etx", &evtsel_MET_MuonBoy_etx, &b_evtsel_MET_MuonBoy_etx);
   fChain->SetBranchAddress("evtsel_MET_MuonBoy_ety", &evtsel_MET_MuonBoy_ety, &b_evtsel_MET_MuonBoy_ety);
   fChain->SetBranchAddress("evtsel_MET_MuonBoy_sumet", &evtsel_MET_MuonBoy_sumet, &b_evtsel_MET_MuonBoy_sumet);
   fChain->SetBranchAddress("evtsel_MET_CellOut_Eflow_JetArea_etx", &evtsel_MET_CellOut_Eflow_JetArea_etx, &b_evtsel_MET_CellOut_Eflow_JetArea_etx);
   fChain->SetBranchAddress("evtsel_MET_CellOut_Eflow_JetArea_ety", &evtsel_MET_CellOut_Eflow_JetArea_ety, &b_evtsel_MET_CellOut_Eflow_JetArea_ety);
   fChain->SetBranchAddress("evtsel_MET_CellOut_Eflow_JetArea_sumet", &evtsel_MET_CellOut_Eflow_JetArea_sumet, &b_evtsel_MET_CellOut_Eflow_JetArea_sumet);
   fChain->SetBranchAddress("evtsel_MET_CellOut_Eflow_JetAreaJVF_etx", &evtsel_MET_CellOut_Eflow_JetAreaJVF_etx, &b_evtsel_MET_CellOut_Eflow_JetAreaJVF_etx);
   fChain->SetBranchAddress("evtsel_MET_CellOut_Eflow_JetAreaJVF_ety", &evtsel_MET_CellOut_Eflow_JetAreaJVF_ety, &b_evtsel_MET_CellOut_Eflow_JetAreaJVF_ety);
   fChain->SetBranchAddress("evtsel_MET_CellOut_Eflow_JetAreaJVF_sumet", &evtsel_MET_CellOut_Eflow_JetAreaJVF_sumet, &b_evtsel_MET_CellOut_Eflow_JetAreaJVF_sumet);
   fChain->SetBranchAddress("evtsel_MET_CellOut_Eflow_JetAreaRhoEta5JVF_etx", &evtsel_MET_CellOut_Eflow_JetAreaRhoEta5JVF_etx, &b_evtsel_MET_CellOut_Eflow_JetAreaRhoEta5JVF_etx);
   fChain->SetBranchAddress("evtsel_MET_CellOut_Eflow_JetAreaRhoEta5JVF_ety", &evtsel_MET_CellOut_Eflow_JetAreaRhoEta5JVF_ety, &b_evtsel_MET_CellOut_Eflow_JetAreaRhoEta5JVF_ety);
   fChain->SetBranchAddress("evtsel_MET_CellOut_Eflow_JetAreaRhoEta5JVF_sumet", &evtsel_MET_CellOut_Eflow_JetAreaRhoEta5JVF_sumet, &b_evtsel_MET_CellOut_Eflow_JetAreaRhoEta5JVF_sumet);
   fChain->SetBranchAddress("evtsel_MET_RefFinal_AntiKt4LCTopo_tightpp_et", &evtsel_MET_RefFinal_AntiKt4LCTopo_tightpp_et, &b_evtsel_MET_RefFinal_AntiKt4LCTopo_tightpp_et);
   fChain->SetBranchAddress("evtsel_MET_RefFinal_AntiKt4LCTopo_tightpp_phi", &evtsel_MET_RefFinal_AntiKt4LCTopo_tightpp_phi, &b_evtsel_MET_RefFinal_AntiKt4LCTopo_tightpp_phi);
   fChain->SetBranchAddress("evtsel_MET_RefFinal_AntiKt4LCTopo_tightpp_sumet", &evtsel_MET_RefFinal_AntiKt4LCTopo_tightpp_sumet, &b_evtsel_MET_RefFinal_AntiKt4LCTopo_tightpp_sumet);
   fChain->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
   fChain->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
   fChain->SetBranchAddress("mc_channel_number", &mc_channel_number, &b_mc_channel_number);
   fChain->SetBranchAddress("lbn", &lbn, &b_lbn);
   fChain->SetBranchAddress("actualIntPerXing", &actualIntPerXing, &b_actualIntPerXing);
   fChain->SetBranchAddress("averageIntPerXing", &averageIntPerXing, &b_averageIntPerXing);
   fChain->SetBranchAddress("larError", &larError, &b_larError);
   fChain->SetBranchAddress("tileError", &tileError, &b_tileError);
   fChain->SetBranchAddress("coreFlags", &coreFlags, &b_coreFlags);
   fChain->SetBranchAddress("top_hfor_type", &top_hfor_type, &b_top_hfor_type);
   fChain->SetBranchAddress("jet_n", &jet_n, &b_jet_n);
   fChain->SetBranchAddress("jet_E", &jet_E, &b_jet_E);
   fChain->SetBranchAddress("jet_pt", &jet_pt, &b_jet_pt);
   fChain->SetBranchAddress("jet_m", &jet_m, &b_jet_m);
   fChain->SetBranchAddress("jet_eta", &jet_eta, &b_jet_eta);
   fChain->SetBranchAddress("jet_phi", &jet_phi, &b_jet_phi);
   fChain->SetBranchAddress("jet_jvtxf", &jet_jvtxf, &b_jet_jvtxf);
   fChain->SetBranchAddress("jet_flavor_weight_MV1", &jet_flavor_weight_MV1, &b_jet_flavor_weight_MV1);
   fChain->SetBranchAddress("jet_flavor_truth_label", &jet_flavor_truth_label, &b_jet_flavor_truth_label);
   fChain->SetBranchAddress("jet_L2_VBF_weight", &jet_L2_VBF_weight, &b_jet_L2_VBF_weight);
   fChain->SetBranchAddress("jet_EF_jet_match", &jet_EF_jet_match, &b_jet_EF_jet_match);
   fChain->SetBranchAddress("jet_L2_jet_match", &jet_L2_jet_match, &b_jet_L2_jet_match);
   fChain->SetBranchAddress("mc_n", &mc_n, &b_mc_n);
   fChain->SetBranchAddress("mc_pt", &mc_pt, &b_mc_pt);
   fChain->SetBranchAddress("mc_eta", &mc_eta, &b_mc_eta);
   fChain->SetBranchAddress("mc_phi", &mc_phi, &b_mc_phi);
   fChain->SetBranchAddress("mc_m", &mc_m, &b_mc_m);
   fChain->SetBranchAddress("mc_status", &mc_status, &b_mc_status);
   fChain->SetBranchAddress("mc_charge", &mc_charge, &b_mc_charge);
   fChain->SetBranchAddress("mc_barcode", &mc_barcode, &b_mc_barcode);
   fChain->SetBranchAddress("mc_parents", &mc_parents, &b_mc_parents);
   fChain->SetBranchAddress("mc_children", &mc_children, &b_mc_children);
   fChain->SetBranchAddress("mc_pdgId", &mc_pdgId, &b_mc_pdgId);
   fChain->SetBranchAddress("EF_e20_medium", &EF_e20_medium, &b_EF_e20_medium);
   fChain->SetBranchAddress("EF_e22_medium", &EF_e22_medium, &b_EF_e22_medium);
   fChain->SetBranchAddress("EF_e22_medium1", &EF_e22_medium1, &b_EF_e22_medium1);
   fChain->SetBranchAddress("EF_e22vh_medium1", &EF_e22vh_medium1, &b_EF_e22vh_medium1);
   fChain->SetBranchAddress("EF_mu18", &EF_mu18, &b_EF_mu18);
   fChain->SetBranchAddress("EF_mu18_MG", &EF_mu18_MG, &b_EF_mu18_MG);
   fChain->SetBranchAddress("EF_mu18_MG_medium", &EF_mu18_MG_medium, &b_EF_mu18_MG_medium);
   fChain->SetBranchAddress("L1_MU11", &L1_MU11, &b_L1_MU11);
   fChain->SetBranchAddress("EF_e60_medium1", &EF_e60_medium1, &b_EF_e60_medium1);
   fChain->SetBranchAddress("EF_e24vhi_medium1", &EF_e24vhi_medium1, &b_EF_e24vhi_medium1);
   fChain->SetBranchAddress("EF_mu24i_tight", &EF_mu24i_tight, &b_EF_mu24i_tight);
   fChain->SetBranchAddress("EF_tau20Ti_medium1_e18vh_medium1", &EF_tau20Ti_medium1_e18vh_medium1, &b_EF_tau20Ti_medium1_e18vh_medium1);
   fChain->SetBranchAddress("EF_tau20_medium1_mu15", &EF_tau20_medium1_mu15, &b_EF_tau20_medium1_mu15);
   fChain->SetBranchAddress("EF_tau20_medium_mu15", &EF_tau20_medium_mu15, &b_EF_tau20_medium_mu15);
   fChain->SetBranchAddress("EF_tau16_loose_e15_medium", &EF_tau16_loose_e15_medium, &b_EF_tau16_loose_e15_medium);
   fChain->SetBranchAddress("EF_tau20_medium_e15_medium", &EF_tau20_medium_e15_medium, &b_EF_tau20_medium_e15_medium);
   fChain->SetBranchAddress("EF_tau20_medium_e15vh_medium", &EF_tau20_medium_e15vh_medium, &b_EF_tau20_medium_e15vh_medium);
   fChain->SetBranchAddress("EF_tau16_loose_mu15", &EF_tau16_loose_mu15, &b_EF_tau16_loose_mu15);
   fChain->SetBranchAddress("L1_TAU8_MU10", &L1_TAU8_MU10, &b_L1_TAU8_MU10);
   fChain->SetBranchAddress("L2_mu15", &L2_mu15, &b_L2_mu15);
   fChain->SetBranchAddress("EF_mu15", &EF_mu15, &b_EF_mu15);
   fChain->SetBranchAddress("L1_2TAU11I_EM14VH", &L1_2TAU11I_EM14VH, &b_L1_2TAU11I_EM14VH);
   fChain->SetBranchAddress("L2_e18vh_medium1", &L2_e18vh_medium1, &b_L2_e18vh_medium1);
   fChain->SetBranchAddress("EF_e18vh_medium1", &EF_e18vh_medium1, &b_EF_e18vh_medium1);
   fChain->SetBranchAddress("EF_e18vh_medium1_vbf_2L1TAU11I_EM14VH", &EF_e18vh_medium1_vbf_2L1TAU11I_EM14VH, &b_EF_e18vh_medium1_vbf_2L1TAU11I_EM14VH);
   fChain->SetBranchAddress("jet_antikt4truth_n", &jet_antikt4truth_n, &b_jet_antikt4truth_n);
   fChain->SetBranchAddress("jet_antikt4truth_pt", &jet_antikt4truth_pt, &b_jet_antikt4truth_pt);
   fChain->SetBranchAddress("jet_antikt4truth_m", &jet_antikt4truth_m, &b_jet_antikt4truth_m);
   fChain->SetBranchAddress("jet_antikt4truth_eta", &jet_antikt4truth_eta, &b_jet_antikt4truth_eta);
   fChain->SetBranchAddress("jet_antikt4truth_phi", &jet_antikt4truth_phi, &b_jet_antikt4truth_phi);
   fChain->SetBranchAddress("vxp_nTracks", &vxp_nTracks, &b_vxp_nTracks);
   Notify();
}

Bool_t cn::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void cn::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t cn::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef cn_cxx
