/*******************************************************************************
aromFuncCalc.cpp - Align-it
 
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



#include "aromFuncCalc.h"



void
aromFuncCalc(OpenBabel::OBMol* mol, Pharmacophore* pharmacophore)
{
	// Create for every aromatic ring a pharmacophore point
	bool rings(false);
	OpenBabel::OBAtom* atom;
	std::vector<OpenBabel::OBAtom*>::iterator i;
	for (atom = mol->BeginAtom(i); atom; atom = mol->NextAtom(i))
	{
		if (atom->IsInRing() && atom->IsAromatic())
		{
			rings = true;
			break;
		}
	}

	if (rings)
	{
		OpenBabel::vector3 center;
		OpenBabel::vector3 norm1;
      	OpenBabel::vector3 norm2;
      	std::vector<OpenBabel::OBRing*> nrings = mol->GetSSSR();
      	std::vector<OpenBabel::OBRing*>::iterator ri;
      	for (ri = nrings.begin(); ri != nrings.end(); ++ri)
      	{
         	if ((*ri)->IsAromatic() && (*ri)->findCenterAndNormal(center, norm1, norm2))
         	{
            	PharmacophorePoint p;
            	p.func = AROM;
            	p.point.x = center.x();
            	p.point.y = center.y();
            	p.point.z = center.z();
            	p.hasNormal = true;
            
            	p.normal.x = norm1.x() + center.x();
            	p.normal.y = norm1.y() + center.y();
            	p.normal.z = norm1.z() + center.z();
            	p.alpha = funcSigma[AROM];
            	pharmacophore->push_back(p);
         	}
      	}
   	}
}
