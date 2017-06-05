// Josh Thorn 2017

#pragma once

#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDING_ESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	

	
private:
	float Reach = 100.f; // the distance a pawn can "reach" ahead of itself without moving. Think armspan.
	UPhysicsHandleComponent* PhysicsHandle = nullptr; //points to memory address zero.
	UInputComponent * InputComponent = nullptr;
	void Grab(); //ray-cast and grab whats in reach
	void Release();
	void FindPhysicsHandleComponent();
	void SetupInputComponent();
	//return hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();
	FVector GetReachLineStart();
	//returns current end of reach line
	FVector GetReachLineEnd();
};
