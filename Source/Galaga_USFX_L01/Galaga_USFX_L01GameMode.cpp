// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_L01GameMode.h"
#include "Galaga_USFX_L01Pawn.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaTransporte.h"
#include "NaveEnemigaCaza.h"

AGalaga_USFX_L01GameMode::AGalaga_USFX_L01GameMode()
{

	PrimaryActorTick.bCanEverTick = true;
	DefaultPawnClass = AGalaga_USFX_L01Pawn::StaticClass();

	
}

void AGalaga_USFX_L01GameMode::BeginPlay()
{
	Super::BeginPlay();
	
	FVector ubicacionInicioNavesEnemigasCaza = FVector(-500.0f, 500.0f, 250.0f);
	FVector ubicacionInicioNavesEnemigasTransporte = FVector(1800.0f, 1700.0f, 250.0f);

	

	FRotator rotacionNave = FRotator(0.0f, 0.0f, 0.0f);
	// Spawn the NaveEnemiga
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{    //aqui se crean las naves enemigas de tipo caza 
		for (int p = 0; p < 11; p++) {

			FVector PosicionNaveActual = FVector(ubicacionInicioNavesEnemigasCaza.X+p*200, ubicacionInicioNavesEnemigasCaza.Y+300, ubicacionInicioNavesEnemigasTransporte.Z);
			ANaveEnemigaCaza* NaveEnemigaCazaTemporal = World->SpawnActor<ANaveEnemigaCaza>(PosicionNaveActual, rotacionNave);
			TANavesEnemigas.Push(NaveEnemigaCazaTemporal);

		}

		float nuevaposicionX = ubicacionInicioNavesEnemigasTransporte.X;
		float nuevaposicionY = ubicacionInicioNavesEnemigasTransporte.Y - 1600.0f; // Posición Y inicial más alta

		for (int p = 0; p < 11; p++)
		{
			FVector PosicionNaveActual = FVector(nuevaposicionX, nuevaposicionY + p * 100, ubicacionInicioNavesEnemigasTransporte.Z);
			ANaveEnemigaTransporte* NaveEnemigaTransporteTemporal = World->SpawnActor<ANaveEnemigaTransporte>(PosicionNaveActual, rotacionNave);
			TANavesEnemigasTransporte.Add(NaveEnemigaTransporteTemporal);
		}

		

		
	}



}

void AGalaga_USFX_L01GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (ANaveEnemigaCaza* Nave : TANavesEnemigasCaza)
	{
		Nave->Tick(DeltaTime);
	}

	for (ANaveEnemigaTransporte* Nave : TANavesEnemigasTransporte)
	{
		Nave->Tick(DeltaTime);
	}

}