#pragma once

#include "CoreMinimal.h"
#include "Materials/MaterialExpression.h"
#include "MaterialExpressionHeightmap.generated.h"

UCLASS(MinimalAPI, collapsecategories, hidecategories=Object)
class UMaterialExpressionHeightmap : public UMaterialExpression
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Options)
	class UTexture* Texture;

	UPROPERTY(EditAnywhere, Category = Options)
	uint32 ConstCoordinate;

	UPROPERTY(meta = (RequiredInput = "false", ToolTip = "Defaults to 'ConstCoordinate' if not specified"))
	FExpressionInput Coordinates;

	UTexture* GetReferencedTexture() override
	{
		return Texture;
	}

	bool CanReferenceTexture() const override { return true; }

	//~ Begin UMaterialExpression Interface
#if WITH_EDITOR
	int32 Compile(class FMaterialCompiler* Compiler, int32 OutputIndex) override;
	void GetCaption(TArray<FString>& OutCaptions) const override;
	void GetExpressionToolTip(TArray<FString>& OutToolTip) override;
#endif
	//~ End UMaterialExpression Interface
};