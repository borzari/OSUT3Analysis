#ifndef ANALYSIS_TYPES
#define ANALYSIS_TYPES

#include <vector>
#include <map>

#include "boost/variant.hpp"

#include "DataFormats/Common/interface/Handle.h"

#include "OSUT3Analysis/AnaTools/interface/DataFormat.h"

class ValueLookupTree;

typedef boost::variant<double, string> Leaf;

typedef vector<map<string, vector<pair<bool, bool> > > > FlagMap;

struct Cut
{
  ValueLookupTree  *valueLookupTree;
  bool             isVeto;
  int              numberRequired;
  string           cutString;
  string           eventComparativeOperator;
  string           inputLabel;
  string           name;
  vector<string>   inputCollections;
};

typedef vector<Cut> Cuts;

struct CutCalculatorPayload
{
  FlagMap         cumulativeObjectFlags;
  FlagMap         objectFlags;
  bool            cutDecision;
  bool            eventDecision;
  bool            isValid;
  bool            triggerDecision;
  Cuts            cuts;
  vector<bool>    eventFlags;
  vector<bool>    triggerFlags;
  vector<bool>    vetoTriggerFlags;
  vector<string>  triggers;
  vector<string>  triggersToVeto;
};

struct HistoDef {
  vector<string> inputCollections;
  string inputLabel;
  string directory;
  string name;
  string title; // contains axis labels
  vector<double> binsX;
  vector<double> binsY;
  bool hasVariableBinsX;
  bool hasVariableBinsY;
  vector<string> inputVariables;
  vector<ValueLookupTree *> valueLookupTrees;
  int dimensions;
};

struct Node
{
  Node            *parent;
  string          value;
  vector<Node *>  branches;
};

// UserVar type:
//   vector<int> - hashes of all objects used
//   double - value of the calculated variable
typedef pair<vector<int>, double> UserVar;

// VariableProducerPayload type:
//   string - user-defined name of variable
//   vector - one UserVar per combination of input objects
typedef map<string, vector<UserVar> > VariableProducerPayload;

struct Collections
{
  edm::Handle<vector<TYPE(bxlumis)> >         bxlumis;
  edm::Handle<vector<TYPE(electrons)> >       electrons;
  edm::Handle<vector<TYPE(events)> >          events;
  edm::Handle<vector<TYPE(genjets)> >         genjets;
  edm::Handle<vector<TYPE(jets)> >            jets;
  edm::Handle<vector<TYPE(mcparticles)> >     mcparticles;
  edm::Handle<vector<TYPE(mets)> >            mets;
  edm::Handle<vector<TYPE(muons)> >           muons;
  edm::Handle<vector<TYPE(photons)> >         photons;
  edm::Handle<vector<TYPE(primaryvertexs)> >  primaryvertexs;
  edm::Handle<vector<TYPE(superclusters)> >   superclusters;
  edm::Handle<vector<TYPE(taus)> >            taus;
  edm::Handle<vector<TYPE(tracks)> >          tracks;
  edm::Handle<vector<TYPE(trigobjs)> >        trigobjs;
  vector<edm::Handle<TYPE(userVariables)> >   userVariables;

  edm::Handle<TYPE(triggers)>                 triggers;
};

struct ValueToPrint
{
  ValueLookupTree  *valueLookupTree;
  string           inputLabel;
  string           valueToPrint;
  vector<string>   inputCollections;
};

typedef vector<ValueToPrint> ValuesToPrint;

#endif
