#ifndef HTIONCHAMBERROOTEVENT_H
#define HTIONCHAMBERROOTEVENT_H


#include <TROOT.h>
#include <TString.h>

#include <stdexcept>

#define MAXNUMDET 10

class HTIonChamberData
{
public:
  Int_t     fMulti;
  Int_t    *fDetNum; //[fMulti]
  Short_t  *fE;      //[fMulti]
  Double_t *fTime;   //[fMulti]

  HTIonChamberData(int numDet = MAXNUMDET);
  virtual ~HTIonChamberData();

  ClassDef(HTIonChamberData,1);
};

class HTIonChamberRootEvent
{

 public:
 HTIonChamberData fIonChamber;

 HTIonChamberRootEvent(int);
 virtual ~HTIonChamberRootEvent();

 ClassDef(HTIonChamberRootEvent,1);
};

#endif
