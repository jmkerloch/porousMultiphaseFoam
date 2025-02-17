{
    
    h.storePrevIter();

    fvScalarMatrix hEqn
        (
            //- accumulation terms
            (Ss*pcModel->Se() + pcModel->Ch()) * fvm::ddt(h)
            //-mass conservative terms
            + massConservativeTerms * (
                pcModel->Ch()*(h.oldTime()-h.prevIter())
                + ( theta - theta.oldTime()))
            /runTime.deltaT()
            //- transport terms
            - fvm::laplacian(Mf,h)
            + fvc::div(phiG)
            ==
            - sourceTerm
        );

    #include "updateForcing.H"

    hEqn.solve();

    deltah = h-h.prevIter();
    forAll(fixedPotentialIDList,celli) deltah[fixedPotentialIDList[celli]] = 0;
    deltahIter = gMax(mag(deltah.internalField())());

}
