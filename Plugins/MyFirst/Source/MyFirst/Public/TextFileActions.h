// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"

class ISlateStyle;

/**
 * 自定义资产的操作
 * @yoci: [创建编辑器新Asset] 3. 实现自定义Asset的操作类，继承自FAssetTypeActions_Base (如Filter过滤、资产缩略图颜色、名字、资产类...)
 */
class MYFIRST_API FTextFileActions
	: public FAssetTypeActions_Base
{
public:
	FTextFileActions();
	// FTextFileActions(const TSharedRef<ISlateStyle>& InStyle);
	
	// 是否可以用Filters过滤类型资产
	virtual bool CanFilter() override { return true; };
	// 创建资产时的归类
	virtual uint32 GetCategories() override;
	// 资产名
	virtual FText GetName() const override;
	// 支持的资产类
	virtual UClass* GetSupportedClass() const override;
	// 资产缩略图颜色
	virtual FColor GetTypeColor() const override;
	// ???
	virtual bool HasActions(const TArray<UObject*>& InObjects) const override;
	//
	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor) override;

private:
	// TSharedRef<ISlateStyle> Style;
};
