/*---------------------------------------------------------------------------*\
  		  _______  ____    ____  ________  
 		 |_   __ \|_   \  /   _||_   __  | 
   		   | |__) | |   \/   |    | |_ \_| 
   		   |  ___/  | |\  /| |    |  _|    
    		  _| |_    _| |_\/_| |_  _| |_     
   		 |_____|  |_____||_____||_____|    
   	     Copyright (C) Toulouse INP, Pierre Horgue

License
    This file is part of porousMultiphaseFoam, an extension of OpenFOAM
    developed by Pierre Horgue (phorgue@imft.fr) and dedicated to multiphase 
    flows through porous media.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Application
    steadyGroundwaterFoam

Description
    statonary solver for Richards equation..
    Permeability is isotropic (K == volScalarField)

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"
#include "harmonic.H"
#include "incompressiblePhase.H"
#include "capillarityModel.H"
#include "relativePermeabilityModel.H"
#include "sourceEventFile.H"
#include "outputEventFile.H"
#include "patchEventFile.H"
#include "eventInfiltration.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
using namespace Foam;

int main(int argc, char *argv[])
{
    #include "setRootCase.H"
    #include "createTime.H"
    #include "createMesh.H"
    #include "readGravitationalAcceleration.H"
    #include "createFields.H"
    #include "readConvergenceControls.H"
    scalar massConservativeTerms = 1; // useless, just for createthetaFields.H re-use
    #include "createthetaFields.H"
    #include "readEvent.H"
    #include "readForcing.H"


    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

    Info<< "\nStarting time loop\n" << endl;
    scalar hEqnResidual = GREAT;

    while (hEqnResidual > tolerance && runTime.value() < runTime.endTime().value()  )
    {
        runTime++;
        Info << "Time = " << runTime.timeName() << nl << endl;

        #include "computeSourceTerm.H"
        #include "hEqnPicard.H"
        #include "checkResidual.H"

        Info << "Saturation theta:" << " Min(theta) = " << gMin(theta.internalField()) << " Max(theta) = " << gMax(theta.internalField()) << " delta(theta) = " << max(mag(theta.internalField()-theta.oldTime().internalField())()) << endl;
        Info << "Head pressure h:" << " Min(h) = " << gMin(h.internalField()) << " Max(h) = " << gMax(h.internalField()) << " delta(h) = " << gMax(deltah.internalField()) << endl;

        runTime.write();

        Info<< "ExecutionTime = " << runTime.elapsedCpuTime() << " s"
            << "  ClockTime = " << runTime.elapsedClockTime() << " s"
            << nl << endl;
    }

    if (hEqnResidual > tolerance)
    {
        WarningIn("steadyGroundwaterFoam.C") << "Solution not converged, final residual is : "
            << hEqnResidual << " increase the end time for convergence" << nl  << endl;
    }
    runTime.writeNow();

    Info<< "End\n" << endl;

    return 0;
}

// ************************************************************************* //
