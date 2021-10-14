            // Surface force
            // Cpc should be 0.5 for dynamic problems, > 0.9 for static problems
            scalar Cpc (readScalar      (     alpha1.mesh().solutionDict().subDict("PIMPLE").lookup("Cpc")        )      );

            // Sharpen interface function
            volScalarField alpha_pc = (1.0/(1.0-Cpc))*(min( max(alpha1,Cpc/2.0), (1.0 -Cpc/2.0) ) - Cpc/2.0);
            surfaceScalarField deltasf = fvc::snGrad(alpha_pc);

            surfaceScalarField fcf = mixture.sigmaKSSF()*deltasf;

           //Produce fc on cell centers
           volVectorField fc = fvc::average(fcf*mesh.Sf()/mesh.magSf()); 

