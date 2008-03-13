/* ****************************************************************** **
**    OpenSees - Open System for Earthquake Engineering Simulation    **
**          Pacific Earthquake Engineering Research Center            **
**                                                                    **
**                                                                    **
** (C) Copyright 2001, The Regents of the University of California    **
** All Rights Reserved.                                               **
**                                                                    **
** Commercial use of this program without express permission of the   **
** University of California, Berkeley, is strictly prohibited.  See   **
** file 'COPYRIGHT'  in main directory for information on usage and   **
** redistribution,  and for a DISCLAIMER OF ALL WARRANTIES.           **
**                                                                    **
** Developed by:                                                      **
**   Frank McKenna (fmckenna@ce.berkeley.edu)                         **
**   Gregory L. Fenves (fenves@ce.berkeley.edu)                       **
**   Filip C. Filippou (filippou@ce.berkeley.edu)                     **
**                                                                    **
** Reliability module developed by:                                   **
**   Terje Haukaas (haukaas@ce.berkeley.edu)                          **
**   Armen Der Kiureghian (adk@ce.berkeley.edu)                       **
**                                                                    **
** ****************************************************************** */
                                                                        
// $Revision: 1.1 $
// $Date: 2008-03-13 22:22:25 $
// $Source: /usr/local/cvs/OpenSees/SRC/reliability/analysis/analysis/ImportanceSamplingAnalysis.h,v $

//
// Written by Terje Haukaas (haukaas@ce.berkeley.edu)
//

#ifndef ImportanceSamplingAnalysis_h
#define ImportanceSamplingAnalysis_h

#include <ReliabilityAnalysis.h>
#include <ReliabilityDomain.h>
#include <ProbabilityTransformation.h>
#include <RandomNumberGenerator.h>
#include <GFunEvaluator.h>

#include <fstream>
#include <tcl.h>
using std::ofstream;

class ImportanceSamplingAnalysis : public ReliabilityAnalysis
{

public:
	ImportanceSamplingAnalysis(ReliabilityDomain *passedReliabilityDomain,
				   ProbabilityTransformation *passedProbabilityTransformation,
				   GFunEvaluator *passedGFunEvaluator,
				   RandomNumberGenerator *passedRandomNumberGenerator,
				   Tcl_Interp *passedInterp,
				   int passedNumberOfSimulations,
				   double passedTargetCOV,
				   double samplingStdv,
				   int printFlag,
				   TCL_Char *fileName,
				   Vector *startPoint,
				   int analysisTypeTag);
	
	~ImportanceSamplingAnalysis();
	
	int analyze(void);

protected:
	
private:
	ReliabilityDomain *theReliabilityDomain;
	ProbabilityTransformation *theProbabilityTransformation;
	GFunEvaluator *theGFunEvaluator;
	RandomNumberGenerator *theRandomNumberGenerator;
	Tcl_Interp *interp;
	int numberOfSimulations;
	double targetCOV;
	double samplingStdv;
	int printFlag;
	char fileName[256];
	Vector *startPoint;
	int analysisTypeTag;
};

#endif
