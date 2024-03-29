// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerMessageWidget.generated.h"

class UTextBlock;

UCLASS()
class RESI_API UPlayerMessageWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct();
	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;
	
	void ShowMessage(const FText& MessageText, float DisplayTime, float AppearTime = 1.0f, float DisappearTime = 1.0f);
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* Message;

	bool bShowMessage = false;

	float CurrentTime;
	float AppearTime, DisplayTime, DisappearTime;
};
