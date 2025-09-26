#include "TrollFloor.h"
//#include "Kismet/KismetSystemLibrary.h"

ATrollFloor::ATrollFloor()
{
	PrimaryActorTick.bCanEverTick = false;

	//축이될 컴포넌트를 우선 축사
	USceneComponent* axis = CreateDefaultSubobject< USceneComponent>(TEXT("Axis"));
	axis->SetupAttachment(GetRootComponent());

	//박스 컴포넌트
	playerDetector = CreateDefaultSubobject<UBoxComponent>(TEXT("PlayerDetector"));
	playerDetector->SetupAttachment(axis);

	//스태틱 메시 컴포넌트
	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	staticMesh->SetupAttachment(axis);
}

void ATrollFloor::BeginPlay()
{
	Super::BeginPlay();

	//트롤링을 하는 경우가 아니면 박스 컴포넌트의 이벤트를 무시한다.
	playerDetector->SetGenerateOverlapEvents(trolling);
}

void ATrollFloor::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	//발판 숨김 함수를 박스 컴포넌트의 이벤트로 등록
	playerDetector->OnComponentBeginOverlap.AddDynamic(this, & ATrollFloor::HideFloor);
}

void ATrollFloor::HideFloor(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int otherBodyIndex, bool fromSweep, const FHitResult& sweepResult)
{
	//UKismetSystemLibrary::PrintString(GetWorld(), TEXT("HideFloor"), true, true, FLinearColor::Yellow, 2.0f);
	APawn* pawn = Cast<APawn>(otherActor);
	if (pawn == nullptr)
		return;

	//폰 (여기서는 플레이어 캐릭터)를 감지하면 발판이 사라진다.
	//UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Troll!"), true, true, FLinearColor::Green, 2.0f);
	staticMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	staticMesh->SetVisibility(false);
	staticMesh->SetActive(false);
}

