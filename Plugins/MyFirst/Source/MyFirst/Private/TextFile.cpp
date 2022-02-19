// Fill out your copyright notice in the Description page of Project Settings.


#include "TextFile.h"

void UTextFile::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	const FName PropertyName = (PropertyChangedEvent.Property ? PropertyChangedEvent.GetPropertyName() : NAME_None); 
	if (PropertyName == GET_MEMBER_NAME_STRING_CHECKED(UTextFile, Text))
	{
		TextLen = GetNum(Text.ToString());
		LowerText = Text.ToLower();
		UpperText = Text.ToUpper();
	}
	UObject::PostEditChangeProperty(PropertyChangedEvent);
}
