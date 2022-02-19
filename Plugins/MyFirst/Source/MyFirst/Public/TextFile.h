// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TextFile.generated.h"

/**
 * 用于编辑文本的一种资产类型
 * @yoci: [创建编辑器新Asset] 1. 先要继承UObject实现一种自定义的资产
 */
UCLASS(BlueprintType)
class MYFIRST_API UTextFile : public UObject
{
	GENERATED_BODY()
public:
	// Functions
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	UFUNCTION(BlueprintCallable, Category="TextFile")
	int32 GetTextLen() { return GetNum(Text.ToString()); };

	UFUNCTION(BlueprintCallable, Category="TextFile")
	void ToLowerOrUpper(bool bToLower = true)
	{
		if (!Text.IsEmpty())
		{
			if (bToLower) Text = Text.ToLower();
			else Text = Text.ToUpper();
		}
	};

public:
	// Variables
	
	// 用于编辑的文本
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="TextFile")
	FText Text;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="AutoGenerate", meta=(EditCondition="false"))
	int32 TextLen = 0;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="AutoGenerate", meta=(EditCondition="false"))
	FText LowerText;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="AutoGenerate", meta=(EditCondition="false"))
	FText UpperText;
};