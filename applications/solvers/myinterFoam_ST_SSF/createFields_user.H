// Construct interface from alpha1 distribution
 //   interfaceProperties interface(alpha1, U, twoPhaseProperties);

// old time fields for relaxation (could alternatively work with oldTime() )
   /* surfaceScalarField phi_old = phi;
    surfaceScalarField fcf_old = mixture.sigmaKSSF()*fvc::snGrad(alpha1);
    surfaceScalarField fcf_filter = 0*fcf_old;*/

/*	volScalarField pc
    (
        IOobject
        (
            "pc",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

label pcRefCell = 0;
scalar pcRefValue = 0.0;
setRefCell
(
    pc,
    pimple.dict(),
    pcRefCell,
    pcRefValue
);
*/
    volVectorField fc
    (
        IOobject
        (
            "fc",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
        ),
        mesh,
        dimensionedVector("fc", dimMass/(dimLength*dimLength*dimTime*dimTime), vector(0,0,0))
    );


/*vector vSource( g.value() * rho2.value() );

volVectorField fSourceMom
(
    IOobject
    (
        "fSourceMom",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedVector("fSourceMom", dimMass/(dimLength*dimLength*dimTime*dimTime), vector(0,0,0))
);

forAll(mesh.cells(),cellI)
{
	for(label iDir=0; iDir<3; iDir++) fSourceMom[cellI][iDir] = vSource[iDir];
}

Info << " g * rho2 (liqiud) = " << vSource << endl;

surfaceScalarField fSourceMomf ( fvc::interpolate(fSourceMom) & mesh.Sf() );*/
