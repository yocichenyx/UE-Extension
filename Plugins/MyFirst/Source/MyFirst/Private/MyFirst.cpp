// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyFirst.h"
#include "AssetToolsModule.h"
#include "TextFileActions.h"

#define LOCTEXT_NAMESPACE "FMyFirstModule"

void FMyFirstModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// @yoci: [创建编辑器新Asset] 4. 在模块被加载到内存后，将自定义的Asset操作类(FXXXActions)注册到AssetTools
	RegisterAssetTypeAction();
}

void FMyFirstModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	// @yoci:  [创建编辑器新Asset] 5. 在模块被清理前，从AssetTools解除注册自定义Asset操作类
	RegisterAssetTypeAction();
}

void FMyFirstModule::RegisterAssetTypeAction()
{
	// 初始化AssetTypeAction指针并注册到AssetTools模块
	AssetTypeAction = MakeShareable(new FTextFileActions());
	if (AssetTypeAction.IsValid() && FModuleManager::Get().IsModuleLoaded("AssetTools"))
	{
		FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get().RegisterAssetTypeActions(AssetTypeAction.ToSharedRef());
	}
}

void FMyFirstModule::UnRegisterAssetTypeAction() const
{
	// 结束注册AssetTypeAction
	if (AssetTypeAction.IsValid() && FModuleManager::Get().IsModuleLoaded("AssetTools"))
	{
		FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get().RegisterAssetTypeActions(AssetTypeAction.ToSharedRef());
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMyFirstModule, MyFirst)