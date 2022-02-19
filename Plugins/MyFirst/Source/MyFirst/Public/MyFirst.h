// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TextFileActions.h"

class FMyFirstModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

protected:
	/** Registers a single asset type action */
	void RegisterAssetTypeAction();
	/** Unregister asset type action */
	void UnRegisterAssetTypeAction() const;

	/** Asset Type Actions */
	TSharedPtr<FTextFileActions> AssetTypeAction;
};