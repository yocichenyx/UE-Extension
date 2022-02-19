// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "TextFileFactory.generated.h"

/**
 * 用于Import txt文件进来创建TextFile资产
 * @yoci: [创建编辑器新Asset] 2. 实现创建资产的工厂类(import文件进来)，继承自UFactory(要使用这个类，要先在*Build.cs中的DependencyModuleNames中加上UnrealEd模块)
 */
UCLASS()
class MYFIRST_API UTextFileFactory
	: public UFactory
{
	GENERATED_BODY()

public:
	UTextFileFactory(const FObjectInitializer& ObjectInitializer) ;

	virtual UObject* FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled) override;
};
