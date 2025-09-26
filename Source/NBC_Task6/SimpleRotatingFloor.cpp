#include "SimpleRotatingFloor.h"

ASimpleRotatingFloor::ASimpleRotatingFloor()
{
	PrimaryActorTick.bCanEverTick = true;

	antiClockDirection = false;
	rotatingSpeed = 0;

	//축이될 컴포넌트를 우선 추가
	USceneComponent* axis = CreateDefaultSubobject< USceneComponent>(TEXT("Axis"));
	axis->SetupAttachment(GetRootComponent());

	//스태틱 메시 컴포넌트
	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	staticMesh->SetupAttachment(axis);
}

void ASimpleRotatingFloor::BeginPlay()
{
	Super::BeginPlay();

	//시작시 초기화할 값
	firstPosition = GetActorLocation();
}

void ASimpleRotatingFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//돌리기
	float rotateValue = rotatingSpeed * DeltaTime;
	AddActorWorldRotation(FRotator(0, antiClockDirection ? -rotateValue : rotateValue, 0));
}

