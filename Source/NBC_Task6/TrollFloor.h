#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "TrollFloor.generated.h"

UCLASS()
class NBC_TASK6_API ATrollFloor : public AActor
{
	GENERATED_BODY()
	
public:
	ATrollFloor();

protected:
	virtual void BeginPlay() override;

	virtual void PostInitializeComponents() override;

private:
	//발판을 숨기는 함수
	UFUNCTION()
	void HideFloor(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int otherBodyIndex, bool fromSweep, const FHitResult& sweepResult);
	
	//true일경우 플레이어 감시지 스태틱 메시가 사라짐
	UPROPERTY(EditAnywhere, Category = "Trolling Setting", meta = (AllowPrivateAccess = true))
	bool trolling;

	//플레이어를 감지할 박스 컴포넌트
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = true))
	UBoxComponent* playerDetector;

	//이 액터의 스태틱 메시
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* staticMesh;
};
