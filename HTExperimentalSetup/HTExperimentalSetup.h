#ifndef HTEXPERIMENTALSETUP_H
#define HTEXPERIMENTALSETUP_H

#include <HTDAQStackInfo.h>
#include <HTDetector.h>
#include <HTDetectorFactory.h>
#include <HTDetectorMap.h>
#include <HTExperimentInfo.h>
#include <HTForwardArray.h>
#include <HTForwardArrayMap.h>
#include <HTHiRA.h>
#include <HTHiRAMap.h>
#include <HTIonChamber.h>
#include <HTMicroball.h>
#include <HTMicroballMap.h>
#include <HTModuleInfo.h>
#include <HTNeutronWall.h>
#include <HTNeutronWallMap.h>
#include <HTRootCAEN1x90.h>
#include <HTRootCAEN7xx.h>
#include <HTRootElectronics.h>
#include <HTRootHINP.h>
#include <HTRootSisTimestamp.h>
#include <HTRootTimestamp.h>
#include <HTRunInfo.h>
#include <HTSisTimestamp.h>
#include <HTSisTimestampMap.h>
#include <HTTDCSpare.h>
#include <HTTDCSpareMap.h>
#include <HTVetoWall.h>
#include <HTVetoWallMap.h>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

class HTExperimentalSetup {
public:
   static HTExperimentalSetup *Instance(); // Getter for Singleton

   int BuildElectronicModules();       //! Called by HTMapper::BuildExperimentalSetup()
   int BuildDetectors();               //! Called by HTMapper::BuildExperimentalSetup()
   void BuildDetectorMaps();           //! Called by HTMapper::BuildExperimentalSetup()
   void InitDetectorBranches(TTree *); //! Called by HTMapper::InitRootOutput()

   // Parse a define line in calibration file. Throws an error if the detector type
   // is one that doesn't support calibration.
   int ParseDefineCalibrationLine(const std::string &);

   //! Parse a define line in .map file. Returns 1 if a detector is add, otherwise 0.
   int ParseDefineMappingLine(const char *);
   //! Parse a assign line in .map file. Returns the number of module assigned.
   int ParseAssignMappingLine(const char *);

   //! Get a std::map<std::string, HTRootElectronics *> pointer to the defined modules
   std::map<std::string, HTRootElectronics *> *GetModules() const;
   HTRootElectronics *GetModule(std::string) const;  //! Get a module by name.
   HTRootElectronics *GetModule(const char *) const; //! Get a module by name.

   //! Get a std::map<std::string, HTDetector *> pointer to the defined modules
   std::map<std::string, HTDetector *> *GetDetectors() const;
   HTDetector *GetDetector(std::string) const;  //! Get a detector by name
   HTDetector *GetDetector(const char *) const; //! Get a detector by name

   //! Get the number of defined detectors
   int GetNDetectors() const;

protected:
   HTExperimentalSetup();  //! Constructor
   ~HTExperimentalSetup(); //! Destructor

private:
   static HTExperimentalSetup *_instance;

   // Maps of module and detector names to classes
   std::map<std::string, HTRootElectronics *> *fModules;
   std::map<std::string, HTDetector *> *fDetectors;
   std::vector<std::string> *fCalibratableDetectors;
};

#endif
