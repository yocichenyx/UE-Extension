// Fill out your copyright notice in the Description page of Project Settings.

#include "TextFileActions.h"
#include "TextFile.h"
#include "Styling/SlateTypes.h"

FTextFileActions::FTextFileActions()
{
}

// FTextFileActions::FTextFileActions(const TSharedRef<ISlateStyle>& InStyle)
// 	: Style(InStyle)
// {
// }

uint32 FTextFileActions::GetCategories()
{
	return EAssetTypeCategories::Misc;
}

FText FTextFileActions::GetName() const
{
	return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_TextFile", "Yoci\nText File");
}

UClass* FTextFileActions::GetSupportedClass() const
{
	return UTextFile::StaticClass();
}

FColor FTextFileActions::GetTypeColor() const
{
	return FColor::Magenta;
}

bool FTextFileActions::HasActions(const TArray<UObject*>& InObjects) const
{
	return true;
}

void FTextFileActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	FAssetTypeActions_Base::OpenAssetEditor(InObjects, EditWithinLevelEditor);
}
