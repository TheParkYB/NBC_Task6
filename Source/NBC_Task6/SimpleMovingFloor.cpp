#include "SimpleMovingFloor.h"

ASimpleMovingFloor::ASimpleMovingFloor()
{
	PrimaryActorTick.bCanEverTick = true;
	negativeDirectionStart = false;
	movingSpeed = 0;
	moveRange = 0;

	//스태틱 메시 컴포넌트
	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	staticMesh->SetupAttachment(GetRootComponent());
}

void ASimpleMovingFloor::BeginPlay()
{
	Super::BeginPlay();

	//시작시 초기화할 값
	negativeDirection = negativeDirectionStart;
	distanceFromStart = 0;
	firstPosition = GetActorLocation();
}

void ASimpleMovingFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//좌우로 이동하기 위해 위치값 갱신
	if (negativeDirection)
	{
		distanceFromStart -= movingSpeed * DeltaTime;
		
		//반대로 이동하기
		if (distanceFromStart < -moveRange)
			negativeDirection = false;
	}
	else
	{
		distanceFromStart += movingSpeed * DeltaTime;
		
		//반대로 이동하기
		if (distanceFromStart > moveRange)
			negativeDirection = true;
	}

	//위치 변경
	SetActorLocation(firstPosition + FVector(0, distanceFromStart, 0));
}

