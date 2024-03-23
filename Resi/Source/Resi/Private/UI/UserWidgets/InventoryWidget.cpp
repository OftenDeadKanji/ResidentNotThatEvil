// Copyright (c) 2024, Mateusz Chłopek. All rights reserved.


#include "UI/UserWidgets/InventoryWidget.h"
#include "Components/GridPanel.h"
#include "Inventory/InventoryComponent.h"
#include "Inventory/Items/InventoryItem.h"
#include "Components/Image.h"

void UInventoryWidget::NativeConstruct()
{
	InventoryPanel->SetColumnFill(ColumnsCount, 1.0f / ColumnsCount);
	InventoryPanel->SetRowFill(RowsMinCount, 1.0f / RowsMinCount);
}

void UInventoryWidget::SetColumnsCount(int32 Count)
{
	ColumnsCount = Count;
}

void UInventoryWidget::SetInventory(UInventoryComponent* InventoryComponent)
{
	Inventory = InventoryComponent;
}

void UInventoryWidget::Refresh()
{
	TArray<UInventoryItem*> Items = Inventory->GetAllItems();
	int32 ItemsCount = Items.Num();

	int32 RowsCount = FMath::Max(RowsMinCount, ItemsCount / ColumnsCount + 1);

	InventoryPanel->ClearChildren();
	InventoryPanel->SetColumnFill(ColumnsCount, 1.0f / ColumnsCount);
	InventoryPanel->SetRowFill(RowsCount, 1.0f / RowsCount);

	for (int i = 0; i < ColumnsCount; i++)
	{
		for (int j = 0; j < RowsCount; j++)
		{
			UImage* ItemImage = NewObject<UImage>(this);

			int Index = j * ColumnsCount + i;
			if (Index < ItemsCount)
			{
				UInventoryItem* Item = Items[Index];
				ItemImage->SetBrushFromTexture(Item->GetIcon());
			}
			else
			{
				ItemImage->SetColorAndOpacity(FLinearColor(0.0f, 0.0f, 0.0f, 0.0f));
			}

			InventoryPanel->AddChildToGrid(ItemImage, j, i);
		}
	}
}
