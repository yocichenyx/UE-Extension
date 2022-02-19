// Fill out your copyright notice in the Description page of Project Settings.


#include "TextFileFactory.h"
#include "TextFile.h"
#include "Misc/FileHelper.h"


UTextFileFactory::UTextFileFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Formats.Add(FString(TEXT("txt;")) + NSLOCTEXT("UTextFileFactory", "FormatTxt", "Text File").ToString());
	SupportedClass = UTextFile::StaticClass();
	bCreateNew = false;
	bEditorImport = true;
}

UObject* UTextFileFactory::FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
                                             const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled)
{
	UTextFile* TextFile = nullptr;
	FString TextString;

	if (FFileHelper::LoadFileToString(TextString, *Filename))
	{
		TextFile = NewObject<UTextFile>(InParent, InClass, InName, Flags);
		TextFile->Text = FText::FromString(TextString);
	}
	bOutOperationCanceled = false;
	return TextFile;
}

