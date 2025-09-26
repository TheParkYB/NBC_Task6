#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SimpleMovingFloor.generated.h"

UCLASS()
class NBC_TASK6_API ASimpleMovingFloor : public AActor
{
	GENERATED_BODY()
	
public:	
	ASimpleMovingFloor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	//처음 움직일 때 음의 방향으로 시작하는가
	UPROPERTY(EditAnywhere, Category = "Moving Setting", meta = (AllowPrivateAccess = true))
	bool negativeDirectionStart;

	//이동 속도
	UPROPERTY(EditAnywhere, Category = "Moving Setting", meta = (AllowPrivateAccess = true))
	float movingSpeed;

	//이동 반경
	UPROPERTY(EditAnywhere, Category = "Moving Setting", meta = (AllowPrivateAccess = true))
	float moveRange;

	//이 액터의 스태틱 메시
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* staticMesh;

	//처음 위치
	FVector firstPosition = FVector::ZeroVector;

	//처음 위치에서 이동한 거리
	float distanceFromStart = 0;
	
	//이동 방향
	bool negativeDirection = false;
};
