// Fill out your copyright notice in the Description page of Project Settings.

#include "TextFileManager.h"

bool UTextFileManager::SaveArrayText(FString SaveDirectory, FString FileName, TArray<FString> SaveText, bool AllowOverwriting = false, bool AllowAppending = false)
{ //set complete file path

	SaveDirectory += "\\";
	SaveDirectory += FileName;

	if (!AllowOverwriting)
	{
		if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*SaveDirectory))
		{
			return false;
		}
	}

	FString FinalString = "";
	for (FString& Each : SaveText)
	{
		FinalString += Each;
		FinalString += LINE_TERMINATOR;

	}

	/*
	FILEWRITE_None = 0x00,
	FILEWRITE_NoFail = 0x01,
	FILEWRITE_NoReplaceExisting = 0x02,
	FILEWRITE_EvenIfReadOnly = 0x04,
	FILEWRITE_Append = 0x08,
	FILEWRITE_AllowRead = 0x10
	*/

	if (AllowAppending)
	{
		return FFileHelper::SaveStringToFile(FinalString, *SaveDirectory, FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get(), FILEWRITE_Append);
	}
	else
	{
		return FFileHelper::SaveStringToFile(FinalString, *SaveDirectory, FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get());
	}
	
}
