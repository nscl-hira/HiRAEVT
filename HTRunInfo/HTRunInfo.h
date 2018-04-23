#ifndef HTRUNINFO_H
#define HTRUNINFO_H

#include <fstream>
#include <sstream>

#include <HTDAQStackInfo.h>
#include <RBHINPUnpacker.h>
#include <RBPh7xxUnpacker.h>
#include <RBCAEN7xxUnpacker.h>
#include <RBCAEN1x90Unpacker.h>
#include <RBSisTimestampUnpacker.h>

class HTRunInfo
{
public:
  HTRunInfo(int run_number, const char * run_title="");                             //! Constructor
  ~HTRunInfo();                                          //! Destructor

  int LoadDAQSettings(const char *);                     //! Read DAQ settings from file
  int LoadPedestals(const char *);                       //! Read Pedetal settings from file
  int LoadMapping(const char *);                         //! Read channel Mapping from file

  const char * GetTitle() const;                         //! Returns run title
  int GetRunNumber() const;                              //! Returns run number
  const char * GetEvtFilePath() const;                   //! Returns path containing evt files for the run
  int GetNStacks() const;                                //! Returns number of stacks
  HTDAQStackInfo * GetStackInfo(int) const;              //! Returns a HTDAQStackInfo object

  void SetEvtFilePath(const char *);                     //! Set path for evt files of the run
  void SetRunTitle(const char *);                        //! Set run title

  void AddModuleToStackInfo(RBElectronics *);            //! Add a module to the HTDAQStackInfo object

private:
  std::string fRunTitle;                                 //!
  int fRunNumber;                                        //!
  std::string fEvtFilePath;                              //!
  int fNStacks;
  bool fDAQLoaded;                                       //!
  bool fPedestalsLoaded;                                 //!
  bool fMappingLoaded;                                   //!

  std::vector <HTDAQStackInfo *> fStackInfo;             //!

  void ParseDefineDAQLine(const char *);
  void ParseAddDAQLine(const char *);

};

#endif