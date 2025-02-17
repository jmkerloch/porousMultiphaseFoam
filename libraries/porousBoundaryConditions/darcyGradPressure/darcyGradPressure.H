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

Class
    Foam::darcyGradPressure

Description
    Set the pressure gradient boundary condition for a given Darcy total velocity
    Permeability is isotropic (K volScalarField)

SourceFiles
    darcyGradPressure.C

\*---------------------------------------------------------------------------*/

#ifndef darcyGradPressure_H
#define darcyGradPressure_H

#include "fixedGradientFvPatchFields.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
    Class darcyGradPressureFvPatch Declaration
    \*---------------------------------------------------------------------------*/

class darcyGradPressure
:
    public fixedGradientFvPatchScalarField
{
    // Private data

    //- Name of the velocity and permeability fields used to calculate the wall BC in darcy's law
    word MfName_;
    word phiName_;
    word phiGfName_;		
    word phiPcName_;
  
public:

    //- Runtime type information
    TypeName("darcyGradPressure");


    // Constructors

    //- Construct from patch and internal field
    darcyGradPressure
    (
        const fvPatch&,
        const DimensionedField<scalar, volMesh>&
    );

    //- Construct from patch, internal field and dictionary
    darcyGradPressure
    (
        const fvPatch&,
        const DimensionedField<scalar, volMesh>&,
        const dictionary&
    );

    //- Construct by mapping given
    //  darcyGradPressure onto a new patch
    darcyGradPressure
    (
        const darcyGradPressure&,
        const fvPatch&,
        const DimensionedField<scalar, volMesh>&,
        const fvPatchFieldMapper&
    );

    //- Disallow copy without setting internal field reference
    darcyGradPressure
    (
        const darcyGradPressure&
    ) = delete;

    //- Construct as copy setting internal field reference
    darcyGradPressure
    (
        const darcyGradPressure&,
        const DimensionedField<scalar, volMesh>&
    );

    //- Construct and return a clone setting internal field reference
    virtual tmp<fvPatchScalarField> clone
    (
        const DimensionedField<scalar, volMesh>& iF
    ) const
        {
            return tmp<fvPatchScalarField>
                (
                    new darcyGradPressure(*this, iF)
                );
        }

    // Member functions

    //- Update the coefficients associated with the patch field
    virtual void updateCoeffs();

    //- Write
    virtual void write(Ostream&) const;
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
