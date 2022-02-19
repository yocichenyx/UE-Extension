// Fill out your copyright notice in the Description page of Project Settings.


#include "TextFileFactoryNew.h"
#include "TextFile.h"

UTextFileFactoryNew::UTextFileFactoryNew(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UTextFile::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UTextFileFactoryNew::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
	UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UTextFile>(InParent, InClass, InName, Flags);
}

bool UTextFileFactoryNew::ShouldShowInNewMenu() const
{
	return true;
}
