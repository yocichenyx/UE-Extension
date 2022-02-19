// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "TextFileFactoryNew.generated.h"

/**
 * 用于引擎内创建TextFile资产的工厂
 * @yoci: [创建编辑器新Asset] 2. 实现创建资产的工厂类(引擎内创建)，继承自UFactory(要使用这个类，要先在*Build.cs中的DependencyModuleNames中加上UnrealEd模块)
 */
UCLASS()
class MYFIRST_API UTextFileFactoryNew
	: public UFactory
{
	GENERATED_BODY()
	
public:
	UTextFileFactoryNew(const FObjectInitializer& ObjectInitializer);
	
	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool ShouldShowInNewMenu() const override;
};
