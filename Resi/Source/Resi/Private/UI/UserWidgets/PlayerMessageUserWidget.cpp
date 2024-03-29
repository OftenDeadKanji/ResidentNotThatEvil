// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.


#include "UI/UserWidgets/PlayerMessageWidget.h"
#include "Components/TextBlock.h"

void UPlayerMessageWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SetVisibility(ESlateVisibility::Collapsed);
	bShowMessage = false;
}

void UPlayerMessageWidget::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	Super::NativeTick(MyGeometry, DeltaTime);

	if (!bShowMessage)
	{
		return;
	}

	// do the thing
	if (CurrentTime >= AppearTime + DisplayTime + DisappearTime)
	{
		SetVisibility(ESlateVisibility::Collapsed);
		bShowMessage = false;

		return;
	}

	if (CurrentTime < AppearTime)
	{
		float T = CurrentTime / AppearTime;
		float Opacity = FMath::Lerp(0.0f, 1.0f, T);

		Message->SetRenderOpacity(Opacity);
	}
	else if (CurrentTime > AppearTime + DisplayTime)
	{
		float T = (CurrentTime - (AppearTime + DisplayTime)) / DisappearTime;
		float Opacity = FMath::Lerp(1.0f, 0.0f, T);

		Message->SetRenderOpacity(Opacity);
	}

	// add time
	CurrentTime += DeltaTime;
}

void UPlayerMessageWidget::ShowMessage(const FText& MessageText, float _DisplayTime, float _AppearTime, float _DisappearTime)
{
	if (bShowMessage)
	{
		return;
	}

	bShowMessage = true;

	CurrentTime = 0.0f;
	DisplayTime = _DisplayTime;
	AppearTime = _AppearTime;
	DisappearTime = _DisappearTime;

	Message->SetText(MessageText);
	SetVisibility(ESlateVisibility::Visible);
}
