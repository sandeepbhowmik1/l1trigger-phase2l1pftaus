#ifndef L1Trigger_TallinnL1PFTaus_TallinnL1PFTauQualityCut_h
#define L1Trigger_TallinnL1PFTaus_TallinnL1PFTauQualityCut_h

#include "FWCore/ParameterSet/interface/ParameterSet.h"             // edm::ParameterSet
#include "DataFormats/Phase2L1ParticleFlow/interface/PFCandidate.h" // l1t::PFCandidate
#include "DataFormats/VertexReco/interface/Vertex.h"                // reco::Vertex

#include <string>                                                   // std::string
#include <vector>                                                   // std::vector

class TallinnL1PFTauQualityCut 
{
 public:
  /// constructor
  TallinnL1PFTauQualityCut(const edm::ParameterSet& cfg);

  /// destructor
  ~TallinnL1PFTauQualityCut();
    
  /// returns true (false) if PFCandidate passes (fails) quality cuts
  bool operator()(const l1t::PFCandidate& pfCand, const reco::Vertex* primaryVertex) const;

 private:
  l1t::PFCandidate::Kind pfCandType_;

  float_t min_pt_;
  float_t max_dz_;
};

std::vector<TallinnL1PFTauQualityCut> readL1PFTauQualityCuts(const edm::ParameterSet& cfg);

bool isSelected(const std::vector<TallinnL1PFTauQualityCut>& qualityCuts, const l1t::PFCandidate& pfCand, const reco::Vertex* primaryVertex);

#endif