// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaCaza.h"

ANaveEnemigaCaza::ANaveEnemigaCaza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_TriPyramid.Shape_TriPyramid'"));
	//// Create the mesh component
	//mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
	VelocidadMovimiento = FVector(-100.0f, -50.0f, 0.0f);
	
}

/*void ANaveEnemigaCaza::Mover(float DeltaTime)
{
	velocidad = 250;
	ubicacionActual = GetActorLocation();
	float NuevaX = velocidad * DeltaTime + ubicacionActual.X;
	FVector NuevaPosicion = FVector(NuevaX, ubicacionActual.Y, ubicacionActual.Z);
	SetActorLocation(NuevaPosicion);
}*/




void ANaveEnemigaCaza::Mover(float DeltaTime)
{
}

void ANaveEnemigaCaza::Disparar()
{
}

void ANaveEnemigaCaza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);

	FVector DesplazamientoCaza= VelocidadMovimiento * DeltaTime;//aqui se desplaza la nave de manera
    FVector NuevaUbicacion = GetActorLocation() + DesplazamientoCaza;
	AddActorWorldOffset(DesplazamientoCaza);//

    if (NuevaUbicacion.X >= LimiteDerecho)
    {
        NuevaUbicacion.X = LimiteDerecho;//si la nave llega al limite derecho se le asigna la posicion del limite derecho
        VelocidadMovimiento.X = -VelocidadMovimiento.X; // Invierte la dirección horizontal
    }
    else if (NuevaUbicacion.X <= LimiteIzquierdo)
    {
        NuevaUbicacion.X = LimiteIzquierdo;//si la nave llega al limite izquierdo se le asigna la posicion del limite izquierdo
        VelocidadMovimiento.X = -VelocidadMovimiento.X; // Invierte la dirección horizontal
    }

    if (NuevaUbicacion.Y >= LimiteSuperior)
    {
        NuevaUbicacion.Y = LimiteSuperior;
        VelocidadMovimiento.Y = -VelocidadMovimiento.Y; // Invierte la dirección vertical
    }
    else if (NuevaUbicacion.Y <= Limiteinferior)
    {
        NuevaUbicacion.Y = Limiteinferior;
        VelocidadMovimiento.Y = -VelocidadMovimiento.Y; // Invierte la dirección vertical
    }

    SetActorLocation(NuevaUbicacion);

}
