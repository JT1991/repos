// Josh Thorn 2017

#include "Building_Escape.h"
#include "Grabber.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber(){
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UGrabber::BeginPlay(){
	Super::BeginPlay();
	FindPhysicsHandleComponent();
	SetupInputComponent();
}

///find attached physics handle
void UGrabber::FindPhysicsHandleComponent() {
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("Error, physics handle not found on %s"), *GetOwner()->GetName())
	}
}

///Look for attached input component
void UGrabber::SetupInputComponent()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent) {
		//bind input action
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Error! Input component not found on %s"), *GetOwner()->GetName())
	}
}


// Called every frame
void UGrabber::TickComponent( 
	float DeltaTime,
	ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	GetReachLineEnd();
	if (!PhysicsHandle) { return; }
	//if physics handle attached
	if (PhysicsHandle->GrabbedComponent) {
		//move object we're holding
		PhysicsHandle->SetTargetLocation(GetReachLineEnd());
	};
}

void UGrabber::Grab() {
	//LINE TRACE and see if we reach actors with physics body collison channel set
	auto HitResult = GetFirstPhysicsBodyInReach();
	auto ComponentToGrab = HitResult.GetComponent(); //gets the mesh
	auto ActorHit = HitResult.GetActor();

	///If we hit, attach physics handle
	if (ActorHit) {
		if (!PhysicsHandle) { return; }
		PhysicsHandle->GrabComponent(
			ComponentToGrab,
			NAME_None, //no bones
			ComponentToGrab->GetOwner()->GetActorLocation(),
			true //allow rotation
		);
	}
}

void UGrabber::Release() {
	if (!PhysicsHandle) { return; }
	PhysicsHandle->ReleaseComponent();
}

const FHitResult UGrabber::GetFirstPhysicsBodyInReach()
{
	///draw a red trace in world to visualise
	/*
	DrawDebugLine(
	GetWorld(),
	PlayerViewPointLocation,
	LineTraceEnd,
	FColor(255, 0, 0),
	false,
	0.f,
	0.f,
	10.f);
	*/
	///Line-trace (ray-cast) out to reach-distance
	FHitResult HitResult;
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());
	GetWorld()->LineTraceSingleByObjectType(
		OUT HitResult,
		GetReachLineStart(),
		GetReachLineEnd(),
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters
	);
	return HitResult;
}

FVector UGrabber::GetReachLineStart() {
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPoiuntRotator;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPoiuntRotator
	);
	return PlayerViewPointLocation;
}

FVector UGrabber::GetReachLineEnd() {
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPoiuntRotator;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPoiuntRotator
	);
	return PlayerViewPointLocation + PlayerViewPoiuntRotator.Vector() * Reach;
}