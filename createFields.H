    Info<< "Reading transportProperties\n" << endl;

    IOdictionary transportProperties
    (
        IOobject
        (
            "transportProperties",
            runTime.constant(),
            mesh,
            IOobject::MUST_READ_IF_MODIFIED,
            IOobject::NO_WRITE
        )
    );

//--------------Added-----------
      
    volScalarField nu1
    ( 
         IOobject 
	 ( 
	  
	     "nu1",
	     runTime.timeName(),
	     mesh,
	     IOobject::MUST_READ,
	     IOobject::NO_WRITE
	 ),
	 mesh
     );
     
     
     
   volScalarField rho
    (IOobject
          (
             "rho",
	     runTime.timeName() ,
	     mesh,
	     IOobject::MUST_READ,
	     IOobject::NO_WRITE
          ),
	  mesh
     ); 
//------------------------------

    dimensionedScalar nu
    (
        transportProperties.lookup("nu")
    );


    Info<< "Reading field p\n" << endl;
    volScalarField p
    (
        IOobject
        (
            "p",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );


    Info<< "Reading field U\n" << endl;
    volVectorField U
    (
        IOobject
        (
            "U",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );


#   include "createPhi.H"


    label pRefCell = 0;
    scalar pRefValue = 0.0;
    setRefCell(p, mesh.solutionDict().subDict("PISO"), pRefCell, pRefValue);
    
    
    
    
    
    //-----------------------Thesis
         //dimensionedScalar nu1
     //(
         //transportProperties.lookup("nu")
     //); 

     ////dimensionedScalar rho1
    ////(
         ////transportProperties.lookup("rho")
    ////);
    
    //volScalarField rho
    //(IOobject
          //(
             //" rho ",
	     //runTime.timeName() ,
	     //mesh,
	     //IOobject::MUST_READ,
	     //IOobject::NO_WRITE
          //),
	  //mesh
     //); 
    
    //volScalarField nu
    //( 
         //IOobject 
	 //( 
	  
	     //" nu ",
	     //runTime.timeName(),
	     //mesh,
	     //IOobject::MUST_READ,
	     //IOobject::NO_WRITE
	 //),
	 //mesh
     //);
     
     //---------------------------
