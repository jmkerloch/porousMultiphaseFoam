---
		 _______  ____    ____  ________  
 		 |_   __ \|_   \  /   _||_   __  | 
   		   | |__) | |   \/   |    | |_ \_| 
   		   |  ___/  | |\  /| |    |  _|    
    		  _| |_    _| |_\/_| |_  _| |_     
   		 |_____|  |_____||_____||_____|    

**** PorousMultiphaseFoam (PMF) for OpenFOAM ****

---

# Branches

## Development branches: dev works with OpenFOAM-v2106

- branch **dev** works with OpenFOAM-v2106 (openfoam.com)
- branch **dev_org** works with OpenFOAM-v9 (openfoam.org)

## The current branches (last version of the toolbox)

- branch **openfoam-v2106** > PMFv2107
- branch **openfoam-v2006** > PMFv2107
- branch **openfoam-v1906** > PMFv2107
- branch **openfoam-v9**    > PMFv2107
- branch **openfoam-v8**    > PMFv2107
- branch **openfoam-v7**    > PMFv2107

## Old branches not updated

- branch **openfoam-v1812**  > PMFv1906
- branch **openfoam-v6**     > PMFv1906
- branch **openfoam-v5**     > PMFv1809
- branch **foam-extend-4.0** > PMFv1809
- branch **openfoam-v1806**  > PMFv1809
- branch **openfoam-v1712**  > PMFv1805

## Older version (no branches)

- OpenFOAM 4.0	PMFv1.4.1
- OpenFOAM 3.0	PMFv1.2

## version not supported:

- OpenFOAM 2.4 and older
- foam-extend 3.2 and older
- OpenFOAM v1706 and older
- OpenFOAM v1812/v1912/v2012

# General Informations

- This toolbox needs only a standard OpenFOAM installation
  (see www.openfoam.org or www.openfoam.com)

- Please cite the related paper in the "doc" folder if you are using this
  toolbox.

- Read the COPYING_OPENFOAM file for information about OpenFOAM and this
  toolbox Copyrights.

# Installation instructions :

- First, source the OpenFOAM configuration file, i.e. (example for ubuntu
  version) :

> source /opt/openfoamv6/etc/bashrc

- then in the "porousMultiphaseFoam" directory, run :

> ./Allwmake -jX

  to install the package (with X the number of processors).

- Dynamic libraries are compiled in the standard OpenFOAM user directory :

> $FOAM_USER_LIBBIN

- The executable solver "impesFoam" is placed in the standard OpenFOAM user
  directory $FOAM_USER_APPBIN.

- Each tutorial directory contains "run" and "clean" files to test installation
  and validate the solver.

- A python script runTutorials.py can be used to test all components.

- To remove compilation and temporary files, run :

> ./Allwclean

- see the ReleaseNotes.txt file for detailed information about the toolbox.

---
