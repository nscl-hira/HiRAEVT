#ifndef HTMCPMAP_H
#define HTMCPMAP_H

#include <HTDetectorMap.h>
#include <TString.h>

class HTMcpMap : public HTDetectorMap {
public:
   HTMcpMap(const std::string &, int);
   ~HTMcpMap();

   int ParseMapLine(const char *) override;
   void Clear() override;

   int GetEnergyModule(bool anode, int num_det) const { return fEnergyModule[anode][num_det]; }

   int GetEnergyChannel(bool anode, int num_det) const { return fEnergyChannel[anode][num_det]; }

   int GetTimeModule(bool anode, int num_det) const { return fTimeModule[anode][num_det]; }

   int GetTimeChannel(bool anode, int num_det) const { return fTimeChannel[anode][num_det]; }

private:
   int fNumDetectors;
   //[anode][detNum]
   int **fEnergyModule;
   int **fEnergyChannel;
   int **fTimeModule;
   int **fTimeChannel;
};

#endif