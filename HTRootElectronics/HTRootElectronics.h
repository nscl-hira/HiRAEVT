#ifndef HTROOTELECTRONICS_H
#define HTROOTELECTRONICS_H

#include <TTree.h>
#include <TTreeReader.h>
#include <TTreeReaderArray.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

class HTRootElectronics {
public:
   HTRootElectronics(const char *); //! Constructor
   HTRootElectronics();             //! Constructor without arguments
   virtual ~HTRootElectronics();    //! Destructor

   const char *GetName() const;                      //! Returns module name
   virtual void InitTreeOutputBranch(TTree *) const; //! Initialize branch in the output tree
   virtual void InitTreeInputBranch(TTreeReader &);  //! Initialize TTreeReaderArray or TTreeReaderValue in the input
                                                     //! tree

protected:
   std::string fName;
};

#endif
