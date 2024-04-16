// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaTransporte.h"

ANaveEnemigaTransporte::ANaveEnemigaTransporte()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
    VelocidadMovimientoTransporte = FVector(100.0f, 50.0f, 0.0f);
}

void ANaveEnemigaTransporte::Mover(float DeltaTime)
{
	/*velocidad = -250;
	ubicacionActual = GetActorLocation();
	float NuevaX = velocidad * DeltaTime + ubicacionActual.X;
	FVector NuevaPosicion = FVector(NuevaX, ubicacionActual.Y-5, ubicacionActual.Z);
	SetActorLocation(NuevaPosicion);*/
	

}

void ANaveEnemigaTransporte::Disparar()
{
}

void ANaveEnemigaTransporte::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);

    FVector DesplazamientoCaza = VelocidadMovimientoTransporte * DeltaTime;//dwsplaza la nave de manera horizontal porque se le asigna el valor de la velocidad en x
    FVector NuevaUbicacion = GetActorLocation() + DesplazamientoCaza;//representa la distancia que se desplaza la nave enemiga
    AddActorWorldOffset(DesplazamientoCaza);//

    if (NuevaUbicacion.X >= LimiteDerecho)
    {
        NuevaUbicacion.X = LimiteDerecho;
        VelocidadMovimientoTransporte.X = -VelocidadMovimientoTransporte.X; // Invierte la dirección horizontal
    }
    else if (NuevaUbicacion.X <= LimiteIzquierdo)
    {
        NuevaUbicacion.X = LimiteIzquierdo;
        VelocidadMovimientoTransporte.X = -VelocidadMovimientoTransporte.X; // Invierte la dirección horizontal
    }

    if (NuevaUbicacion.Y >= LimiteSuperior)
    {
        NuevaUbicacion.Y = LimiteSuperior;
        VelocidadMovimientoTransporte.Y = -VelocidadMovimientoTransporte.Y; // Invierte la dirección vertical
    }
    else if (NuevaUbicacion.Y <= Limiteinferior)
    {
        NuevaUbicacion.Y = Limiteinferior;
        VelocidadMovimientoTransporte.Y = -VelocidadMovimientoTransporte.Y; // Invierte la dirección vertical
    }

    SetActorLocation(NuevaUbicacion);

}
