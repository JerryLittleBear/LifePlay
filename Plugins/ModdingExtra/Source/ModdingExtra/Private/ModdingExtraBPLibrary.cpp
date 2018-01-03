// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "ModdingExtraBPLibrary.h"
#include "ModdingExtra.h"
#include "Engine.h"

UModdingExtraBPLibrary::UModdingExtraBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float UModdingExtraBPLibrary::ModdingExtraSampleFunction(float Param)
{
	return -1;
}

 bool UModdingExtraBPLibrary::GetAllFilesFromFolder(TArray<FString>& Files, FString RootFolderFullPath, FString Ext)
 {
     if(RootFolderFullPath.Len() < 1) return false;
     
     // FPaths::NormalizeDirectoryName(RootFolderFullPath);
     
     //RootFolderFullPath = FPaths::ConvertRelativePathToFull(RootFolderFullPath);
     
     IFileManager& FileManager = IFileManager::Get();
     
     FString RelativePath = FPaths::ProjectContentDir();
     FString FullPath = FileManager.ConvertToAbsolutePathForExternalAppForRead(*RelativePath);
     
     if(Ext == "") 
     {
         Ext = "*.*";
     }
     else
     {
         Ext = (Ext.Left(1) == ".") ? "*" + Ext : "*." + Ext;
     }
     
     FString FinalPath = FullPath + "/" + RootFolderFullPath + "/" + Ext;
     FileManager.FindFiles(Files, *FinalPath, true, false);
     return true;                  
 }
 
 bool UModdingExtraBPLibrary::LoadTxt(FString FileNameA, FString& SaveTextA)
{
     return FFileHelper::LoadFileToString(SaveTextA, *(FPaths::ProjectContentDir() + FileNameA));
}

 FString UModdingExtraBPLibrary::ContentDirectory()
{
    FString RelativePath = FPaths::ProjectContentDir();
    FString FullPath = IFileManager::Get().ConvertToAbsolutePathForExternalAppForRead(*RelativePath);
    return FullPath;
}
