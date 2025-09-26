#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SimpleRotatingFloor.generated.h"

UCLASS()
class NBC_TASK6_API ASimpleRotatingFloor : public AActor
{
	GENERATED_BODY()
	
public:	
	ASimpleRotatingFloor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	//true일 경우 반시계 방향으로 회전
	UPROPERTY(EditAnywhere, Category = "Rotating Setting", meta = (AllowPrivateAccess = true))
	bool antiClockDirection;

	//회전 속도
	UPROPERTY(EditAnywhere, Category = "Rotating Setting", meta = (AllowPrivateAccess = true))
	float rotatingSpeed;

	//이 액터의 스태틱 메시
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* staticMesh;

	//처음 위치
	FVector firstPosition = FVector::ZeroVector;
};
