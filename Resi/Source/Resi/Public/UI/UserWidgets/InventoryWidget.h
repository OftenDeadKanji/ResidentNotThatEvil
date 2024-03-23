// Copyright (c) 2024, Mateusz Chłopek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWidget.generated.h"

class UGridPanel;
class UInventoryComponent;

UCLASS()
class RESI_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void NativeConstruct() override;

	void SetColumnsCount(int32 Count);

	void SetInventory(UInventoryComponent* InventoryComponent);

	void Refresh();
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ColumnsCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 RowsMinCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UGridPanel* InventoryPanel{};

	UInventoryComponent* Inventory{};
};
