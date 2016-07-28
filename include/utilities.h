/*******************************************************************************
utilities.h - Align-it

Copyright 2012-2013 by Silicos-it, a division of Imacosi BVBA
 
This file is part of Align-it.

	Align-it is free software: you can redistribute it and/or modify
	it under the terms of the GNU Lesser General Public License as published 
	by the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Align-it is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License
	along with Align-it.  If not, see <http://www.gnu.org/licenses/>.

Align-it is linked against OpenBabel version 2.

	OpenBabel is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation version 2 of the License.

***********************************************************************/



#ifndef __SILICOSIT_ALIGNIT_UTILITIES_H__
#define __SILICOSIT_ALIGNIT_UTILITIES_H__



// General

// OpenBabel
#include "openbabel/mol.h"

// Align-it
#include "coordinate.h"
#include "pharmacophore.h"
#include "siMath.h"
#include "solutionInfo.h"
#include "defines.h"



Coordinate translate(Coordinate& p, Coordinate& t);
Coordinate rotate(Coordinate& p, SiMath::Matrix& R);
void normalise(Coordinate & p);
double norm(Coordinate & p);
double dotProduct(Coordinate& p1, Coordinate& p2) ;
Coordinate crossProduct(Coordinate& p1, Coordinate& p2);
double cosine(Coordinate& p1, Coordinate& p2);
double distance(Coordinate& p1, Coordinate& p2);
		
void normalise(SiMath::Vector& v);
		
SiMath::Matrix quat2Rotation(SiMath::Vector& Q);
		
void inverseHessian(SiMath::Matrix& H);

double VolumeOverlap(PharmacophorePoint& p1, PharmacophorePoint& p2, bool n);
double VolumeOverlap(PharmacophorePoint* p1, PharmacophorePoint* p2, bool n);
		
void TransformPharmacophore(Pharmacophore& pharm, SiMath::Matrix& U, Coordinate& center1, Coordinate& center2);
void positionPharmacophore(Pharmacophore& pharm, SiMath::Matrix& U, SolutionInfo& s);

void TransformMolecule(OpenBabel::OBMol* m, SiMath::Matrix& U, Coordinate& center1, Coordinate& center2);
void positionMolecule(OpenBabel::OBMol* m, SiMath::Matrix& U, SolutionInfo& s);
		


#endif

