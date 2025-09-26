// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NBC_Task6 : ModuleRules
{
	public NBC_Task6(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
